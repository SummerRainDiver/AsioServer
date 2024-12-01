#pragma once

#include "AsioSocketChannel.h"
#include <iostream>

using boost::asio::ip::tcp;
using namespace std;

class Session
    : public std::enable_shared_from_this<Session>
{
public:
    Session(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

public:
    void Start();

private:
    void DoRead();
    void DoWrite(std::size_t length);

    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};