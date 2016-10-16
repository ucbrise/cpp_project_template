CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

ADD_EXECUTABLE(client client.cc)
TARGET_LINK_LIBRARIES(client
    api
    zeromq_util
    zmq
)
