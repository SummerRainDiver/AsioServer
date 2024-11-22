
#include "MainServer.h"

/*  < Echo ���� �ó����� >
* 0. ���� ����
* 1. ���Ӵ�� ���� ����
* 2. ��Ʈ ���ε�
* 3. ���Ӵ�� ���·� ��ȯ
* 4. Ŭ���̾�Ʈ ���� ó�� �� ����
* 4-1. Ŭ���̾�Ʈ ������ �޾Ƶ��̰� ���ο� ���� ����(����)
* 4-2. Ŭ���̾�Ʈ�κ��� ����
* 4-3. ������ �� �״�� �ٽ� ����
* 4-4. Ŭ���̾�Ʈ�� ���� ����
* 5. ���� ���� �ݱ�
* 6. ���� ���� ����
*/

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