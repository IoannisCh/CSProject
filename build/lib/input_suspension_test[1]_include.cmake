if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/input_suspension_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/input_suspension_test[1]_tests.cmake")
else()
  add_test(input_suspension_test_NOT_BUILT input_suspension_test_NOT_BUILT)
endif()
