#include <boost/asio.hpp>
#include <iostream>
#include "./server/Server.h"

using boost::asio::ip::tcp;



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: join_server <port>\n";
        return 1;
    }

    short port = std::atoi(argv[1]);
    boost::asio::io_context io_context;
    Server server(io_context, port);
    io_context.run();
}
