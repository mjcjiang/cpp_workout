#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iceoryx_introspection::iceoryx_introspection" for configuration "Release"
set_property(TARGET iceoryx_introspection::iceoryx_introspection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(iceoryx_introspection::iceoryx_introspection PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libiceoryx_introspection.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS iceoryx_introspection::iceoryx_introspection )
list(APPEND _IMPORT_CHECK_FILES_FOR_iceoryx_introspection::iceoryx_introspection "${_IMPORT_PREFIX}/lib/libiceoryx_introspection.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
