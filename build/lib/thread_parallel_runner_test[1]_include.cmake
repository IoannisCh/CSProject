if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/thread_parallel_runner_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/thread_parallel_runner_test[1]_tests.cmake")
else()
  add_test(thread_parallel_runner_test_NOT_BUILT thread_parallel_runner_test_NOT_BUILT)
endif()
