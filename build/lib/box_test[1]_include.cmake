if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/box_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/box_test[1]_tests.cmake")
else()
  add_test(box_test_NOT_BUILT box_test_NOT_BUILT)
endif()