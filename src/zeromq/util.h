#ifndef ZEROMQ_UTIL_H_
#define ZEROMQ_UTIL_H_

#include <cstring>
#include <string>

#include <zmq.hpp>

// Converts the data within a `zmq::message_t` into a string.
std::string message_to_string(const zmq::message_t& message) {
  return std::string(static_cast<const char*>(message.data()), message.size());
}

// Serialize a proto and `send` it over the socket.
template <typename RequestProto>
void send_proto(const RequestProto& request, zmq::socket_t* socket) {
  std::string request_str;
  request.SerializeToString(&request_str);
  zmq::message_t request_msg(request_str.size());
  memcpy(request_msg.data(), request_str.c_str(), request_str.size());
  socket->send(request_msg);
}

// `recv` a message and unserialize it into a proto.
template <typename ResponseProto>
void recv_proto(ResponseProto* reply, zmq::socket_t* socket) {
  zmq::message_t reply_msg;
  socket->recv(&reply_msg);
  std::string reply_str = message_to_string(reply_msg);
  reply->ParseFromString(reply_str);
}

#endif  // ZEROMQ_UTIL_H_
