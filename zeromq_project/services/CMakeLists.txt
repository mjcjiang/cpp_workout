LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

#add_executable (zmq_server zmq_server.c)
#target_link_libraries(zmq_server zmq)

#add_executable (zmq_client zmq_client.c)
#target_link_libraries(zmq_client zmq)

add_executable (cppzmq_example cppzmq_example.cc)
target_link_libraries(cppzmq_example zmq)

add_executable (boost_test boost_test.cc)
