if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/entropy_coder_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/entropy_coder_test[1]_tests.cmake")
else()
  add_test(entropy_coder_test_NOT_BUILT entropy_coder_test_NOT_BUILT)
endif()
