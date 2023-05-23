# Copyright 2015 Google Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

import os
import sys
import time

from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

# Global application (there should only ever be one!)

g_app = None

# Services

class Services:
	def __init__(self, driver):
		self.driver = driver

# DeviceConfig

class DeviceConfig:
	def __init__(self, root):
		self.root = root

		# Find child relevant elements.
		# \todo [petri] would it be better to wrap these as functions instead of exposing Selenium elements?
		# \todo [petri] always query Selenium elements on-demand to avoid any potential issues with dynamically loaded/changing data?
		self.titleBar			= root.find_element_by_id("titleBar")
		self.expandButton		= root.find_element_by_id("expandButton")
		self.name				= root.find_element_by_id("name")
		self.targetAddress		= root.find_element_by_id("targetAddress")
		self.targetPort			= root.find_element_by_id("targetPort")
		self.spawnLocalProcess	= root.find_element_by_id("spawnLocalProcess")
		self.binaryName			= root.find_element_by_id("testBinaryName")
		self.workingDir			= root.find_element_by_id("testBinaryWorkingDir")
		self.commandLine		= root.find_element_by_id("testBinaryCommandLine")
		self.saveButton			= root.find_element_by_id("saveButton")
		try: # \note 'new device' doesn't have delete button
			self.deleteButton	= root.find_element_by_id("deleteButton")
		except NoSuchElementException:
			pass

	def select(self):
		self.titleBar.click()
		g_app.waitRPC()

# DeviceConfigList

class DeviceConfigList:
	def __init__(self, root):
		self.root = root

	def getNewDevice(self):
		return DeviceConfig(self.root.find_element_by_xpath("//div[@id='newDeviceConfig']"))

	def getDeviceByName(self, name):
		deviceRoot = self.root.find_element_by_xpath("//b[text() = '%s']/ancestor::div[@id='deviceConfig']" % name)
		return DeviceConfig(deviceRoot)

# TestSet

class TestSet:
	def __init__(self, root):
		self.root = root

	def foo(self):
		pass

# TestCaseSelection

class TestCaseSelection:
	def __init__(self, root):
		self.root = root

		#self.testSetList		= TestSetList(self.root_find_element_by_id())
		self.extraTestFilters	= self.root.find_element_by_id("testNameFilters")

# TestLaunchPage

class TestLaunchPage:
	def __init__(self, driver):
		self.driver	= driver

		self.executeButton = driver.find_element_by_id("executeButton")

	def getDeviceConfigList(self):
		return DeviceConfigList(self.driver.find_element_by_xpath("//div[@id='deviceConfigList']"))

	def getTestCaseSelection(self):
		return TestCaseSelection(self.driver.find_element_by_id("testCaseSelection"))

	def execute(self):
		self.executeButton.click()

# BatchResult

class BatchResult:
	def __init__(self, root):
		self.root	= root
		self.name	= root.find_element_by_id("batchResultName").text

	def __str__(self):
		return self.name

# BatchResultListPage

class BatchResultListPage:
	def __init__(self, driver):
		self.driver = driver

	def getBatchResults(self):
		elems = self.driver.find_elements_by_xpath("//a[@id='batchResult']")
		return [BatchResult(elem) for elem in elems]

# TreeNodeType

class TreeNodeType:
	Group	= 0
	Leaf	= 1

	@staticmethod
	def getName(value):
		#print dir(TreeNodeType)
		return dir(TreeNodeType)[value]

# TestCaseTreeNode

class TestCaseTreeNode:
	def __init__(self, root, nodeType):
		self.root		= root
		self.nodeType	= nodeType
		self.labelNode	= root.find_element_by_id('nodeLabel')
		self.label		= self.labelNode.text
		self.path		= root.find_element_by_id('nodePath').get_attribute('node-path')
		assert(self.label != '')

	def select(self):
		self.labelNode.click()
		g_app.waitRPC()

	def isExpanded(self):
		classes = self.root.get_attribute('class').split(' ')
		#print "CL:", classes
		return 'tree-expanded' in classes

	def toggleExpand(self):
		assert(self.nodeType == TreeNodeType.Group)
		treeHead = self.root.find_element_by_css_selector('.tree-branch-head')
		treeHead.click() # \todo [petri] check that node is currently unexpanded?

	def __str__(self):
		return "node: path='%s' type=%s" % (self.path, TreeNodeType.getName(self.nodeType))

# TestCaseTree

class TestCaseTree:
	def __init__(self, root):
		self.root = root

	def getVisibleGroupNodes(self):
		elems = self.root.find_elements_by_id('testCaseGroupNode')
		elems = [elem.find_element_by_xpath('(ancestor::li)[last()]') for elem in elems] # get matching <li> node (real root for tree node)
		return [TestCaseTreeNode(elem, TreeNodeType.Group) for elem in elems]

	def getVisibleLeafNodes(self):
		elems = self.root.find_elements_by_id('testCaseLeafNode')
		elems = [elem.find_element_by_xpath('(ancestor::li)[last()]') for elem in elems] # get matching <li> node (real root for tree node)
		return [TestCaseTreeNode(elem, TreeNodeType.Leaf) for elem in elems]

	def getVisibleNodes(self):
		return self.getVisibleGroupNodes() + self.getVisibleLeafNodes()

	def getTestCaseNode(self, nodePath):
		allNodes = self.getVisibleNodes()
		for node in allNodes:
			if node.path == nodePath:
				#print "FOUND:", node.label, node.path
				return node
		else:
			# \todo [petri] expand parent nodes until desired node is found?
			raise Exception("test case node not found with path '%s'" % nodePath)

	def expandVisibleGroup(self, nodePath):
		groupNodes = self.getVisibleGroupNodes()
		for node in groupNodes:
			if node.path == nodePath:
				assert(not node.isExpanded())
				node.toggleExpand()
				g_app.waitRPC()
				break
		else:
			raise Exception('no visible group node found with path="%s"' % nodePath)

#	def getVisibleNodes(self):
#		return

# DetailsView

class DetailsView:
	def __init__(self, root):
		self.root = root

		self.title	= root.find_element_by_id('title').text
		self.status	= root.find_element_by_id('status').text

# BatchResultPage

class BatchResultPage:
	def __init__(self, driver):
		self.driver = driver

		self.name	= self.driver.find_element_by_id('batchResultName')
		self.status	= self.driver.find_element_by_id('batchResultStatus')

	def waitUntilFinished(self):
		WebDriverWait(self.driver, 600).until(EC.invisibility_of_element_located((By.XPATH, "//div[@id='batchResultSpinner']/div")))

	def getStatus(self):
		return self.driver.find_element_by_id('batchResultStatus').text

	def getTestCaseTree(self):
		return TestCaseTree(self.driver.find_element_by_id('testCaseTree'))

	def getDetailsView(self):
		return DetailsView(self.driver.find_element_by_id('testCaseContainer'))

# Application

class Application:
	def __init__(self, driver, browser):
		self.driver		= driver
		self.browser	= browser
		#self.spinner	= driver.find_element_by_id("globalSpinner")

		# \todo [petri] bit of a kludge but didn't really want to pass this all over the place
		global g_app
		g_app = self

	def waitRPC(self):
		# Kludge extra sleep with IE, because it doesn't seem to wait for animations to complete automatically.
		if g_app.browser == 'ie':
			time.sleep(1)

		# RPC loading is ready when globalSpinner has no 'div' as its child.
		WebDriverWait(self.driver, 10).until(EC.invisibility_of_element_located((By.XPATH, "//div[@id='globalSpinner']/div")))

	def gotoTestLaunchPage(self):
		self.driver.find_element_by_link_text('Tests').click()
		self.waitRPC()

	def gotoBatchResultListPage(self):
		self.driver.find_element_by_link_text('Results').click()
		self.waitRPC()

	def gotoBatchResultPage(self, batchResultId):
		# id is of form: 2014-05-15T15:47:35+03:00
		url = '/#/results/batch/%s/testGroup/' % batchResultId
		# \note using driver.get() apparently doesn't work with Angular-style #-prefixed urls
		self.driver.execute_script('window.location = "%s";' % url)
		self.waitRPC()

	def getTestLaunchPage(self):
		# \todo [petri] assert we're on right page or make this func gotoTestLaunchPage?
		return TestLaunchPage(self.driver)

	def getBatchResultListPage(self):
		return BatchResultListPage(self.driver)

	def getBatchResultPage(self):
		return BatchResultPage(self.driver)
