# Copyright 2017 Google Inc. All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#	  http://www.apache.org/licenses/LICENSE-2.0
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
import socket
import requests
import textwrap

server_port = 0

def getBaseUrl():
	return 'http://localhost:%d' % server_port


class TestSetUploadTest(unittest.TestCase):
	def testSimpleUpload(self):
		files = {
			"set-name":		("Foo", "RealSetName"),
			"set-filters":	("filterList.txt",
							 textwrap.dedent("""dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color
												dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color"""))
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.ok)

		# \todo [2017-05-11 kraita]: Use python websockets to verify DB changes?
		# \todo [2017-05-11 kraita]: Re-do in Go and use existing Go code?

	def testEmptyFilterFile(self):
		files = {
			"set-name":		("Foo", "RealSetName"),
			"set-filters":	("filterList.txt", "")
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.server_error)

	def testEmptyName(self):
		files = {
			"set-name":		("Foo", ""),
			"set-filters":	("filterList.txt",
							 textwrap.dedent("""dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color
												dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color"""))
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.server_error)

	def testInvalidFilter(self):
		files = {
			"set-name":		("Foo", "Broken filter"),
			"set-filters":	("filterList.txt",
							 textwrap.dedent("""dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color
												dEQP-!%^@!^@^.6t=-34.
												dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color"""))
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.server_error)

	def testPatternFilter(self):
		files = {
			"set-name":		("Foo", "PatternFilter"),
			"set-filters":	("filterList.txt",
							 textwrap.dedent("""dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color
												dEQP-EGL.functional.*
												dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color"""))
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.ok)

	def testComments(self):
		files = {
			"set-name":		("Foo", "FilterWithComments"),
			"set-filters":	("filterList.txt",
							 textwrap.dedent("""dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color
												#This is a foobar comment 1()*&*^(_)
												dEQP-EGL.foo.bar # Comment at the end of line )(*&^%$^&*()*#$&*(":}:{:{}[]
												dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color"""))
		}
		r = requests.post(getBaseUrl()+"/importTestSet/", files=files)
		self.assertEqual(r.status_code, requests.codes.ok)

if __name__ == '__main__':
	# Make sure we're in cherry/test directory
	os.chdir(os.path.dirname(__file__))

	# Parse command-line arguments.
	parser = argparse.ArgumentParser(description='Cherry Server Tests')
	parser.add_argument('-p', '--port', help='port used for ExecServer communication', default='8086')
	args = parser.parse_args()

	server_port = int(args.port)
	serverAddress = ('localhost', server_port)

	# Take a temp copy of Cherry database file to execute tests with.
	# \note Database contains a pre-generated data so that test cases can be built to assume existence of such data.
	tmpDBName = '_tmp.db'
	shutil.copy2('cherry-test.db', tmpDBName)

	# Spawn Cherry server.
	server = subprocess.Popen(['./server', '--db=test/'+tmpDBName, '--port=%d' % server_port], cwd='../', stdin=None, stdout=sys.stdout, stderr=subprocess.STDOUT)

	try:
		# Wait for server to come up
		connected = False
		while not connected:
			try:
				dummyConnection = socket.create_connection(serverAddress, 60.0) # Wait max a minute for connection
				dummyConnection.close()
				connected = True
			except Exception as e:
				time.sleep(0.2)
			sys.stdout.flush()

		unittest.main(verbosity=2)
		sys.stdout.flush()
		time.sleep(2) # HACK: Wait for server stdout to clear.
	finally:
		try:
			print "Killing child process."
			server.terminate()
			server.communicate()
			server.wait()
			# Remove tmp database.
			os.remove(tmpDBName)
		except Exception as e:
			print "WARNING: unable to kill process: %s" % e

