if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/gamma_correct_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/gamma_correct_test[1]_tests.cmake")
else()
  add_test(gamma_correct_test_NOT_BUILT gamma_correct_test_NOT_BUILT)
endif()
