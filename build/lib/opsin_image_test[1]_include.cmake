if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/opsin_image_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/opsin_image_test[1]_tests.cmake")
else()
  add_test(opsin_image_test_NOT_BUILT opsin_image_test_NOT_BUILT)
endif()