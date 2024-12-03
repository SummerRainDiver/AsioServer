#pragma once

#include <boost/asio.hpp>
#include "AsioIoContext.h"
#include "Session.h"

#include <iostream>

using boost::asio::ip::tcp;
using namespace std;

class AsioServer
{
public:
	AsioServer();
	//virtual ~AsioServer();

	// 이거 쓸까말까 고민중. 
	/*
	AsioServer(boost::asio::io_context& ioContext, unsigned short port)
		: m_Acceptor(ioContext, boost::asio::ip::tcp::endpoint(tcp::v4(), port))
	{
		DoAccept();
	}
	*/

public:
	void Initialize();
	//virtual bool Listen();
	//virtual bool Stop();
	//virtual bool Release();

private:
	void Accept();

	tcp::acceptor m_Acceptor;
	const unsigned short PORT_NUMBER = 3100;
};
