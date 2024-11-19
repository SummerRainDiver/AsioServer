#pragma once
#include "asio.hpp"
#include <asio/io_context.hpp>
#include <thread>
#include <vector>

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