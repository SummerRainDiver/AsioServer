#include "AsioIoContext.h"

AsioIoContext::AsioIoContext()
{
	m_IoContext = nullptr;
	m_asioContextThreadList.clear();
}

AsioIoContext::~AsioIoContext()
{
	delete m_IoContext;
	m_IoContext = nullptr;
}

bool AsioIoContext::Init()
{
	m_IoContext = new boost::asio::io_context();
	if (m_IoContext == nullptr)
	{
		return false;
	}
	return true;
}

bool AsioIoContext::Start()
{
	if (m_IoContext == nullptr)
	{
		return false;
	}

	for (int i = 0; i < 1; i++)
	{
		m_asioContextThreadList.push_back(std::thread([this]() { m_IoContext->run(); }));
	}

	return true;
}

bool AsioIoContext::Stop()
{
	if (m_IoContext == nullptr)
	{
		return false;
	}

	m_IoContext->stop();

	for (auto& thread : m_asioContextThreadList)
	{
		thread.join();
	}

	m_asioContextThreadList.clear();

	return true;
}