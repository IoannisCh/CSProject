if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/enc_linalg_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/enc_linalg_test[1]_tests.cmake")
else()
  add_test(enc_linalg_test_NOT_BUILT enc_linalg_test_NOT_BUILT)
endif()