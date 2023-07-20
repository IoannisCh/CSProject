# CMake generated Testfile for 
# Source directory: /home/yiannis/Documents/CSProject/libjxl/tools
# Build directory: /home/yiannis/Documents/CSProject/build/tools
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(LibraryCLinkageTest "/home/yiannis/Documents/CSProject/build/tools/tests/libjxl_test")
set_tests_properties(LibraryCLinkageTest PROPERTIES  WORKING_DIRECTORY "/home/yiannis/Documents/CSProject/build" _BACKTRACE_TRIPLES "/home/yiannis/Documents/CSProject/libjxl/tools/CMakeLists.txt;392;add_test;/home/yiannis/Documents/CSProject/libjxl/tools/CMakeLists.txt;0;")
subdirs("box")
subdirs("conformance")
subdirs("wasm_demo")
