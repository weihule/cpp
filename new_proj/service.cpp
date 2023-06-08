#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    // 初始化socket库
    WORD wVersionRequested = MAKEWORD(2, 2);
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0)
    {
        return 1;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        WSACleanup();
        return 1;
    }

    // 创建用于监听的socket
    SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
    if(sockSrv == -1)
    {
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    addrSrv.sin_family = AF_INET;
    addrSrv.sin_port = htons(6000);

    // 绑定socket，name参数要做一个大端转换
    if (bind(sockSrv, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) == -1)
    {
        closesocket(sockSrv);
        WSACleanup();
        return 1;
    }

    // 启动监听，准备接受客户端的连接请求，设置最多15个客户端
    if (listen(sockSrv, 15) == -1)
    {
        closesocket(sockSrv);
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN addrClient;
    int len = sizeof(SOCKADDR);
    char msg[] = "Hello World";
    while(true)
    {
        // 等待客户端请求的到来，如果有客户端连接，则接受连接
        SOCKET sockClient = accept(sockSrv, (SOCKADDR*)&addrClient, &len);
        if (sockClient == -1)
        {
            break;
        }

        std::cout << "客户端地址: " << inet_ntoa(addrClient.sin_addr) << std::endl;

        send(sockClient, msg, strlen(msg), 0);
        closesocket(sockClient);
    }

    closesocket(sockSrv);
    WSACleanup();

    return 0;
}


