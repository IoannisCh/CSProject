if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/data_parallel_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/data_parallel_test[1]_tests.cmake")
else()
  add_test(data_parallel_test_NOT_BUILT data_parallel_test_NOT_BUILT)
endif()