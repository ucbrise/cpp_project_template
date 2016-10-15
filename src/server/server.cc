#include <iostream>

#include <zmq.hpp>

#include "factor/factor.h"
#include "proto/api.pb.h"
#include "zeromq/util.h"

int main() {
  zmq::context_t context(1);
  zmq::socket_t socket(context, ZMQ_REP);
  const std::string address = "tcp://*:5555";
  socket.bind(address);
  std::cout << "Listening on " << address << std::endl;

  while (true) {
    Request request;
    recv_proto(&request, &socket);

    std::vector<long> factors = factor::factor(request.x());
    Reply reply;
    reply.set_x(request.x());
    for (const long factor : factors) {
      reply.add_factor(factor);
    }

    send_proto(reply, &socket);
  }
  return 0;
}
