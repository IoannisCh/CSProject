if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/ac_strategy_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/ac_strategy_test[1]_tests.cmake")
else()
  add_test(ac_strategy_test_NOT_BUILT ac_strategy_test_NOT_BUILT)
endif()
