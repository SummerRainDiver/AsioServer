#pragma once


class server
{
public:
	/*
	server(boost::asio::io_context& io_context, short port)
		: acceptor_(io_context, tcp::endpoint(tcp::v4(), port))
	{
		do_accept();
	}
	*/
	void Init();

private:
	void do_accept();
	/*
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
	*/

	// tcp::acceptor acceptor_;
};