#pragma once
#include "AsioServer.h"
//#include "AsioClient.h"

class AsioSocketChannel
{
public:
	AsioSocketChannel(boost::asio::io_context* io_context);
	virtual ~AsioSocketChannel();

public:
	void SetSocket(boost::asio::ip::tcp::socket socket);
	boost::asio::ip::tcp::socket& GetSocket();
	virtual bool Close();
	virtual bool Reset();
	void StartRead();
	bool ISClosing();

	std::string& GetRemoteIP();
	void SetRemoteIP(std::string ip);

public:
	virtual void OnAccept();
	virtual void OnConnect();
	virtual void OnRead(const boost::system::error_code& error, size_t bytes_transferred);
	virtual void OnWrite(const boost::system::error_code& error, size_t bytes_transferred);
	virtual void OnClose();
};