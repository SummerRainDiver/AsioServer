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

		cout << "Client connected..." << endl; // ���⵵ Ŭ�󸶴� ���� �ο��ϱ�.
		do_accept();
	});

}