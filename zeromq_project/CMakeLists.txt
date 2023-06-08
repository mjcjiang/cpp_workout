CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(zeromq_project)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_EXE_LINKER_FLAGS "-Wl,-copy-dt-needed-entries")
############################################################
INCLUDE_DIRECTORIES(deps/libzmq-4.3.4/include)
INCLUDE_DIRECTORIES(deps/cppzmq-4.9.0/include)
INCLUDE_DIRECTORIES(deps/ctp-6.6.7/include)
INCLUDE_DIRECTORIES(include)

message("CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message("PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/deps/libzmq-4.3.4/lib lib)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/deps/cppzmq-4.9.0/lib lib)
execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/deps/ctp-6.6.7/lib lib)
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINRY_DIR}/lib")

ADD_SUBDIRECTORY(deps)
ADD_SUBDIRECTORY(services)
