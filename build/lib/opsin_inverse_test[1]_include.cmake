if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/opsin_inverse_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/opsin_inverse_test[1]_tests.cmake")
else()
  add_test(opsin_inverse_test_NOT_BUILT opsin_inverse_test_NOT_BUILT)
endif()
