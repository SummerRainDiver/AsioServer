#pragma once
//#include <asio/io_context.hpp>
#include <thread>
#include <vector>

#include <boost/asio.hpp>

#include <iostream>

using boost::asio::ip::tcp;
using namespace std;

class AsioIoContext
{
public:
	AsioIoContext();
	~AsioIoContext();

public:
	bool Init();
	bool Start();
	bool Stop();

	boost::asio::io_context* GetIoContext() { return m_IoContext;  };

private:
	boost::asio::io_context* m_IoContext;
	std::vector<std::thread> m_asioContextThreadList;
};