#pragma once

#include <boost/asio.hpp>
#include "Database.h"
#include "Session.h"

using boost::asio::ip::tcp;

class Server {
public:
    Server(boost::asio::io_context& io_context, short port) : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
        accept();
    }

private:
    void accept() {
        acceptor_.async_accept(
            [this](boost::system::error_code ec, tcp::socket socket) {
                if (!ec) {
                    std::make_shared<Session>(std::move(socket), db_)->start();
                }
                accept();
            });
    }

    tcp::acceptor acceptor_;
    Database db_;
};
