#include "Server.h"

int main()
{
	Server server;

	if (0)
	{
		// 서버 실행
	}

	return 0;
}

/*
const unsigned short PORT_NUMBER = 3100;

int main()
{
	boost::asio::io_context io_context;

	// server s(io_context, std::atoi(argv[1])); 
	server s(io_context, PORT_NUMBER);

	try
	{
		cout << "Server Start..." << endl;
		io_context.run();
		cout << "Server closed..." << endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}
*/