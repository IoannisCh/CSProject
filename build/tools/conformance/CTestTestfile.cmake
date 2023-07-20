# CMake generated Testfile for 
# Source directory: /home/yiannis/Documents/CSProject/libjxl/tools/conformance
# Build directory: /home/yiannis/Documents/CSProject/build/tools/conformance
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(conformance_tooling_test "/usr/bin/bash" "/home/yiannis/Documents/CSProject/libjxl/tools/conformance/tooling_test.sh" "/home/yiannis/Documents/CSProject/build" "/home/yiannis/Documents/CSProject/libjxl/testdata")
set_tests_properties(conformance_tooling_test PROPERTIES  SKIP_RETURN_CODE "254" _BACKTRACE_TRIPLES "/home/yiannis/Documents/CSProject/libjxl/tools/conformance/CMakeLists.txt;10;add_test;/home/yiannis/Documents/CSProject/libjxl/tools/conformance/CMakeLists.txt;0;")
