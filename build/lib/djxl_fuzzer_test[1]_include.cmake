if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/djxl_fuzzer_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/djxl_fuzzer_test[1]_tests.cmake")
else()
  add_test(djxl_fuzzer_test_NOT_BUILT djxl_fuzzer_test_NOT_BUILT)
endif()