#include "AsioServer.h"
#include "AsioSocketChannel.h"

void AsioServer::Initialize()
{
	boost::asio::io_context io_context;
	tcp::acceptor acceptor_(io_context, tcp::endpoint(tcp::v4(), PORT_NUMBER));
	Accept();
	io_context.run();
}

void AsioServer::Accept()
{
	m_Acceptor.async_accept(
		[this](boost::system::error_code ec, tcp::socket socket)
		{
			if (!ec)
			{
				std::make_shared<Session>(std::move(socket))->Start();
			}

			cout << "Client connected..." << endl; // ���⵵ Ŭ�󸶴� ���� �ο��ϱ�.
			Accept();
		});
}