if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/passes_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/passes_test[1]_tests.cmake")
else()
  add_test(passes_test_NOT_BUILT passes_test_NOT_BUILT)
endif()
