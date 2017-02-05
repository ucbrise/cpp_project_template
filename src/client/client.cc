#include <cstdint>
#include <iostream>
#include <string>

#include <zmq.hpp>

#include "glog/logging.h"
#include "proto/api.pb.h"
#include "zeromq_util/util.h"

namespace {

void prompt() { std::cout << "> " << std::flush; }

}  // namespace

int main(int, char* argv[]) {
  google::InitGoogleLogging(argv[0]);

  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REQ);
  const std::string address = "tcp://localhost:5555";
  socket.connect(address);
  LOG(INFO) << "Client connected to " << address;

  prompt();
  for (std::string line; std::getline(std::cin, line); prompt()) {
    Request request;
    long x = std::stol(line);
    CHECK_GT(x, 0) << "Cannot factor non-positive value.";
    request.set_x(std::stol(line));
    send_proto(request, &socket);

    Reply reply;
    recv_proto(&reply, &socket);
    for (const int64_t factor : reply.factor()) {
      std::cout << factor << std::endl;
    }
  }
}
