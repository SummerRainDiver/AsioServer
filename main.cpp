#include "Server.h"
#include "NetWork/AsioServer.h"

#include <iostream>
using namespace std;
// const unsigned short PORT_NUMBER = 3100;

int main()
{
	AsioServer server;

	try
	{
		cout << "Server Start..." << endl;

		server.Initialize();

		cout << "Server Closed..." << endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}