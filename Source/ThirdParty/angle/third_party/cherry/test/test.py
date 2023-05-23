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
import shutil
import subprocess
import unittest
import argparse

from cherry import *

from selenium import webdriver

# Win32 process launch flags.
DETACHED_PROCESS	= 0x00000008

# Global config.
SUPPORTED_BROWSERS	= ['chrome', 'firefox', 'ie']
SELECTED_BROWSER	= None
SUPPORT_CURRENT_URL	= True		# IE11 always returns base url for some reason
BASE_URL			= ''

# Static data.

class BatchResultInfo:
	def __init__(self, id, name):
		self.id		= id
		self.name	= name

# Information about contents of cherry-test.db. If the database is created with new data, this needs to be updated.

BASIC_BATCH_RESULT = BatchResultInfo('2014-05-15T15:47:35+03:00', u'2014-May-15 15:47:35')

# Create browser instance.

def createBrowserDriver():
	global SUPPORT_CURRENT_URL
	if SELECTED_BROWSER == 'chrome':
		return webdriver.Chrome()
	elif SELECTED_BROWSER == 'firefox':
		return webdriver.Firefox()
	elif SELECTED_BROWSER == 'ie':
		SUPPORT_CURRENT_URL = False
		return webdriver.Ie()
	else:
		raise Exception('trying to create invalid browser: ' + browser)

# BasicTestCase

class BasicTestCase(unittest.TestCase):
	def setUp(self):
		self.driver = createBrowserDriver()
		self.driver.implicitly_wait(3)
		self.driver.get(BASE_URL)
		self.app = Application(self.driver, SELECTED_BROWSER)

	def testPageTitle(self):
		self.assertIn('Cherry', self.driver.title)

	def testTestLaunchPage(self):
		self.app.gotoTestLaunchPage()
		if SUPPORT_CURRENT_URL:
			self.assertIn('/testLaunch', self.driver.current_url)

	def testBatchResultListPage(self):
		# \todo [petri] should goto functions return resulting page?
		self.app.gotoBatchResultListPage()
		if SUPPORT_CURRENT_URL:
			self.assertIn('/results', self.driver.current_url)
		batchResultListPage = self.app.getBatchResultListPage()
		batchResults = batchResultListPage.getBatchResults()
		batchResultNames = [br.name for br in batchResults]
		self.assertIn(BASIC_BATCH_RESULT.name, batchResultNames)

		# \todo [petri] check for something on results page..
#		print "%d BATCH RESULTS:" % len(batchResults)
#		for br in batchResults:
#			print "BR:", br

	def testBatchResultPage(self):
		# Go to batch result page and do basic checks.
		self.app.gotoBatchResultPage(BASIC_BATCH_RESULT.id)
		batchResultPage = self.app.getBatchResultPage()
		self.assertIn('Finished', batchResultPage.getStatus())

		# Get test case tree, and expand a node.
		testCaseTree = batchResultPage.getTestCaseTree()
		groupNodes = testCaseTree.getVisibleGroupNodes()
		testCaseTree.expandVisibleGroup('dEQP-GLES2.info')

		# Check that we have some test cases visible.
		leafNodes = testCaseTree.getVisibleLeafNodes()
		self.assertEqual(len(leafNodes), 6) # 6 cases in dEQP-GLES2.info.*

		testCasePath = 'dEQP-GLES2.info.version'
		versionNode = testCaseTree.getTestCaseNode(testCasePath)
		versionNode.select()

		detailsView = batchResultPage.getDetailsView()
		self.assertEqual(detailsView.title, testCasePath)
		self.assertIn('Pass', detailsView.status)

		#time.sleep(3)

	def testCreateDeviceConfig(self):
		self.app.gotoTestLaunchPage()
		testLaunchPage = self.app.getTestLaunchPage()

		# Device config to create.
		deviceName			= 'test config'
		deviceAddress		= '127.0.0.1'
		devicePort			= '50016'
		deviceLocalProcess	= '../candy-build/deqp-wgl/execserver/Release/execserver.exe'
		deviceBinaryName	= 'Debug/${TestPackageName}.exe'
		deviceWorkingDir	= '../candy-build/deqp-wgl/modules/${TestPackageDir}'
		deviceCommandLine	= '--deqp-watchdog=enable --deqp-crashhandler=enable --deqp-visibility=hidden --deqp-gl-config-name=rgba8888d24s8ms0'

		# Create & save new config.
		deviceList = testLaunchPage.getDeviceConfigList()
		device = deviceList.getNewDevice()
		# \todo [petri] wrap expand click() and send_keys() calls?
		device.expandButton.click()
		self.app.waitRPC() # \todo [petri] wait for animations to complete (required on IE?)
		device.name.send_keys(deviceName)
		device.targetAddress.send_keys(deviceAddress)
		device.targetPort.send_keys(devicePort)
		device.spawnLocalProcess.send_keys(deviceLocalProcess)
		device.binaryName.send_keys(deviceBinaryName)
		device.workingDir.send_keys(deviceWorkingDir)
		device.commandLine.send_keys(deviceCommandLine)
		device.saveButton.click()
		self.app.waitRPC() # wait for save to complete..

		# Use created device for running tests.
		device = deviceList.getDeviceByName(deviceName)
		device.select()

		# Check that created device has correct values.
		device.expandButton.click()
		# \todo [petri] wrap input field getters?
		self.assertEqual(deviceName, device.name.get_attribute("value"));
		self.assertEqual(deviceAddress, device.targetAddress.get_attribute("value"));
		self.assertEqual(devicePort, device.targetPort.get_attribute("value"));
		self.assertEqual(deviceLocalProcess, device.spawnLocalProcess.get_attribute("value"));
		self.assertEqual(deviceBinaryName, device.binaryName.get_attribute("value"));
		self.assertEqual(deviceWorkingDir, device.workingDir.get_attribute("value"));
		self.assertEqual(deviceCommandLine, device.commandLine.get_attribute("value"));

	def testExecuteBatch(self):
		self.app.gotoTestLaunchPage()
		testLaunchPage = self.app.getTestLaunchPage()

		# Select 'Localhost' device for running tests.
		deviceList = testLaunchPage.getDeviceConfigList()
		device = deviceList.getDeviceByName('Localhost')
		device.select()

		# Test selection.
		testSelection = testLaunchPage.getTestCaseSelection()
		testSelection.extraTestFilters.send_keys('dEQP-GLES2.info.*')

		# Launch test execution.
		testLaunchPage.execute()
		self.app.waitRPC()

		# Goes automatically to batch result page.
		# \note should we get this automatically from launch execution?
		batchResultPage = self.app.getBatchResultPage()
		batchResultPage.waitUntilFinished()
#		print "BATCH RESULT NAME: '%s'" % batchResultPage.name.text

	def tearDown(self):
		self.driver.quit()

# Main.

# \note Can run single test case with:
# > test.py --unittest BasicTestCase.testCreateDeviceConfig

if __name__ == '__main__':
	# Make sure we're in cherry/test directory
	os.chdir(os.path.dirname(__file__))

	# Parse command-line arguments.
	parser = argparse.ArgumentParser(description='Cherry Selenium Tests')
	parser.add_argument('-b', '--browser', help='specify browser to use (chrome, firefox, ie)', default='firefox')
	parser.add_argument('-x', '--xml', help='generate output in XML format into specified directory', default=None)
	parser.add_argument('-p', '--port', help='port used for ExecServer communication', default='8086')
	parser.add_argument('--unittest', nargs='*', help='pass rest of arguments to python unittest')
	args = parser.parse_args()

	port = int(args.port)
	BASE_URL = 'http://localhost:%d' % port

	if args.browser not in SUPPORTED_BROWSERS:
		raise Exception('invalid browser "' + args.browser + '", supported browsers are ' + ', '.join(SUPPORTED_BROWSERS))
	SELECTED_BROWSER = args.browser
	print 'Using browser:   %s' % SELECTED_BROWSER
	print 'ExecServer port: %d' % port

	sys.argv = [sys.argv[0]] + (args.unittest or [])

	# Take a temp copy of Cherry database file to execute tests with.
	# \note Database contains a pre-generated data so that test cases can be built to assume existence of such data.
	tmpDBName = '_tmp.db'
	shutil.copy2('cherry-test.db', tmpDBName)

	# Spawn Cherry server.
	# \todo [petri] should server be restarted on every test case?
	server = subprocess.Popen(['../Cherry.exe', '--db=test/'+tmpDBName, '--port=%d' % port], cwd='../', creationflags=DETACHED_PROCESS)
	# \todo [petri] wait for server to be booted up properly
	time.sleep(3) # give Cherry server a bit of time to boot up

	try:
		if args.xml:
			import xmlrunner
			unittest.main(testRunner=xmlrunner.XMLTestRunner(output=args.xml), verbosity=2)
		else:
			unittest.main(verbosity=2)
	finally:
		try:
			print "Killing child process."
			subprocess.Popen.kill(server)
		except Exception as e:
			print "WARNING: unable to kill process: %s" % e

	# Remove tmp database.
	os.remove(tmpDBName)
