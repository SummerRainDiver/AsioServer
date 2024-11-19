#pragma once
#include "asio.hpp"
#include <boost/asio.hpp>
#include "AsioIoContext.h"

/*
namespace Network
{
	class AsioServer
	{
	public:
		AsioServer(boost::asio::io_context& ioContext, unsigned short port)
			: m_Acceptor(ioContext, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
		{
			DoAccept();
		}

	private:
		void DoAccept()
		{
			m_Acceptor.async_accept(
				[this](boost::system::error_code ec, boost::asio::ip::tcp::socket socket)
				{
					if (!ec)
					{
						std::make_shared<AsioSocketChannel>(std::move(socket))->Start();
					}

					DoAccept();
				});
		}

	private:
		boost::asio::ip::tcp::acceptor m_Acceptor;
	};
}
*/

class AsioServer
{
public:
	AsioServer();
	virtual ~AsioServer();

public:
	virtual bool Initialize();
	virtual bool Listen();
	virtual bool Stop();
	virtual bool Release();

private:
	boost::asio::ip::tcp::acctoptor m_Acceptor;
};

class server
{
public:
	server(boost::asio::io_context& io_context, short port)
		: acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
	{
		do_accept();
	}

private:
	void do_accept()
	{
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

	tcp::acceptor acceptor_;
};
