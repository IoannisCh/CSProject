if(EXISTS "/home/yiannis/Documents/CSProject/build/lib/image_bundle_test[1]_tests.cmake")
  include("/home/yiannis/Documents/CSProject/build/lib/image_bundle_test[1]_tests.cmake")
else()
  add_test(image_bundle_test_NOT_BUILT image_bundle_test_NOT_BUILT)
endif()
