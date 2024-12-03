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

// 코드를 짜다보니까 Server, AsioServer 둘다 필요하진 않은 것 같음. 