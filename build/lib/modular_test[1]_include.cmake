if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/modular_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/modular_test[1]_tests.cmake")
else()
  add_test(modular_test_NOT_BUILT modular_test_NOT_BUILT)
endif()
