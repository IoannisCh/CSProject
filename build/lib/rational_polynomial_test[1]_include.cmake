if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/rational_polynomial_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/rational_polynomial_test[1]_tests.cmake")
else()
  add_test(rational_polynomial_test_NOT_BUILT rational_polynomial_test_NOT_BUILT)
endif()