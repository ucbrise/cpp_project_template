CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_EXECUTABLE(server server.cc)
TARGET_LINK_LIBRARIES(server
    api
    factor
    zmq
)
