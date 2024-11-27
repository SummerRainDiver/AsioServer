#include "Server.h"

void Server::do_accept()
{
	tcp::acceptor acceptor_;

	acceptor_.async_accept(
		[this](boost::system::error_code ec, tcp::socket socket)
	{
		if (!ec)
		{
			std::make_shared<session>(std::move(socket))->start();
		}

		cout << "Client connected..." << endl; // 여기도 클라마다 순번 부여하기.
		do_accept();
	});

}