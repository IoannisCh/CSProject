if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/encode_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/encode_test[1]_tests.cmake")
else()
  add_test(encode_test_NOT_BUILT encode_test_NOT_BUILT)
endif()
