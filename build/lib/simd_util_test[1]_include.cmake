if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/simd_util_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/simd_util_test[1]_tests.cmake")
else()
  add_test(simd_util_test_NOT_BUILT simd_util_test_NOT_BUILT)
endif()
