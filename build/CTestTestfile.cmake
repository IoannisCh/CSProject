# CMake generated Testfile for 
# Source directory: /home/yiannis/Documents/CSProject/libjxl
# Build directory: /home/yiannis/Documents/CSProject/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(bash_test "/usr/bin/bash" "/home/yiannis/Documents/CSProject/libjxl/bash_test.sh")
set_tests_properties(bash_test PROPERTIES  _BACKTRACE_TRIPLES "/home/yiannis/Documents/CSProject/libjxl/CMakeLists.txt;414;add_test;/home/yiannis/Documents/CSProject/libjxl/CMakeLists.txt;0;")
subdirs("third_party/googletest")
subdirs("third_party")
subdirs("lib")
subdirs("tools")
