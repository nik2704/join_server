
#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include "Database.h"

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket, Database& db) : socket_(std::move(socket)), db_(db) {}

    void start() { read(); }

private:
    void read() {
        auto self(shared_from_this());
        boost::asio::async_read_until(socket_, boost::asio::dynamic_buffer(data_), '\n',
            [this, self](boost::system::error_code ec, std::size_t) {
                if (!ec) { process_command(); read(); }
            });
    }

    void process_command() {
        std::istringstream iss(data_);
        std::string cmd, table, name;
        int id;
        std::string response;

        iss >> cmd;
        if (cmd == "INSERT") {
            iss >> table >> id >> name;
            db_.insert(table, id, name, response);
        } else if (cmd == "TRUNCATE") {
            iss >> table;
            db_.truncate(table, response);
        } else if (cmd == "INTERSECTION") {
            response = db_.intersection();
        } else if (cmd == "SYMMETRIC_DIFFERENCE") {
            response = db_.symmetric_difference();
        } else {
            response = "ERR unknown command\n";
        }
        data_.clear();
        write(response);
    }

    void write(const std::string& response) {
        auto self(shared_from_this());
        boost::asio::async_write(socket_, boost::asio::buffer(response),
            [this, self](boost::system::error_code, std::size_t) {});
    }

    tcp::socket socket_;
    Database& db_;
    std::string data_;
};
