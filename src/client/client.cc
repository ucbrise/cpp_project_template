#include <iostream>
#include <string>

#include <zmq.hpp>

#include "proto/api.pb.h"
#include "zeromq/util.h"

namespace {

void prompt() { std::cout << "> " << std::flush; }

}  // namespace

int main() {
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REQ);
  socket.connect("tcp://localhost:5555");

  prompt();
  for (std::string line; std::getline(std::cin, line); prompt()) {
    Request request;
    request.set_x(std::stol(line));
    send_proto(request, &socket);

    Reply reply;
    recv_proto(&reply, &socket);
    for (const long factor : reply.factor()) {
      std::cout << factor << std::endl;
    }
  }
}
