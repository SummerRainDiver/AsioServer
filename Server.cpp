#include "Server.h"

void Server::Init()
{
	boost::asio::io_context io_context;
	tcp::acceptor acceptor_(io_context, tcp::endpoint(tcp::v4(), 3100));
	//AsioServer::Accept();
	io_context.run();

}

void Server::Terminate()
{
	// acceptor_.close();
}

// �ڵ带 ¥�ٺ��ϱ� Server, AsioServer �Ѵ� �ʿ����� ���� �� ����. 