if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/fields_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/fields_test[1]_tests.cmake")
else()
  add_test(fields_test_NOT_BUILT fields_test_NOT_BUILT)
endif()
