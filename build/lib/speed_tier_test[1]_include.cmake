if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/speed_tier_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/speed_tier_test[1]_tests.cmake")
else()
  add_test(speed_tier_test_NOT_BUILT speed_tier_test_NOT_BUILT)
endif()
