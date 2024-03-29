#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "hwy::hwy" for configuration "Debug"
set_property(TARGET hwy::hwy APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hwy::hwy PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libhwy.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS hwy::hwy )
list(APPEND _IMPORT_CHECK_FILES_FOR_hwy::hwy "${_IMPORT_PREFIX}/lib/libhwy.a" )

# Import target "hwy::hwy_test" for configuration "Debug"
set_property(TARGET hwy::hwy_test APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(hwy::hwy_test PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libhwy_test.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS hwy::hwy_test )
list(APPEND _IMPORT_CHECK_FILES_FOR_hwy::hwy_test "${_IMPORT_PREFIX}/lib/libhwy_test.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
