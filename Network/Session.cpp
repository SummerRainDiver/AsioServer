#include "Session.h"

void Session::Start()
{
    cout << "Session on..." << endl; // 세션풀 만들고 세션 마다 번호 붙여서 로그 추가
    DoRead();
}

void Session::DoRead()
{
	auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, std::size_t length)
		{
			if (!ec)
			{
				DoWrite(length);
			}
		});
}

void Session::DoWrite(std::size_t length)
{
	if (length > 1)
	{
		cout << "Message from Client [" << data_ << "]" << endl;
	}

	auto self(shared_from_this());
	boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
		[this, self](boost::system::error_code ec, std::size_t /*length*/)
		{
			if (!ec)
			{
				cout << "Trying to read message..." << endl;
				DoRead();
			}
		});
}