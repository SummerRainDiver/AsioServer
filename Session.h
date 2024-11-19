#pragma once

#include "Network/AsioSocketChannel.h"

using boost::asio::ip::tcp;
using namespace std;

class session
    : public std::enable_shared_from_this<session>
{
public:
    session(tcp::socket socket)
        : socket_(std::move(socket))
    {
    }

    void start()
    {
        cout << "Session on..." << endl; // ����Ǯ ����� ���� ���� ��ȣ �ٿ��� �α� �������� ������.  
        do_read();
    }

private:
    void do_read()
    {
        auto self(shared_from_this());
        socket_.async_read_some(boost::asio::buffer(data_, max_length),
            [this, self](boost::system::error_code ec, std::size_t length)
            {
                if (!ec)
                {
                    do_write(length);
                }
            });
    }

    void do_write(std::size_t length)
    {
        if (length > 1)
        {
            cout << "Message from Client [" << data_ << "]" << endl;
        }

        //char loveletter[128] = "loveletter";

        auto self(shared_from_this());
        //boost::asio::async_write(socket_, boost::asio::buffer(loveletter, sizeof(loveletter)),
        boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
            [this, self](boost::system::error_code ec, std::size_t /*length*/)
            {
                if (!ec)
                {
                    cout << "Trying to read Client message..." << endl;
                    do_read();
                }
            });
    }

    tcp::socket socket_;
    enum { max_length = 1024 };
    char data_[max_length];
};