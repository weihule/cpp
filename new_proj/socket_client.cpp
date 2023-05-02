#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>

int main() {
    WSADATA wsaData;
    SOCKET sock;
    int iResult;

    // 初始化Winsock库
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed!" << std::endl;
        return 1;
    }

    // 创建套接字
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "socket failed!" << std::endl;
        WSACleanup();
        return 1;
    }

    // 将套接字绑定到本地地址和端口号
    addrinfo hints = {};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    addrinfo *result = nullptr;
    iResult = getaddrinfo("localhost", "8080", &hints, &result);
    if (iResult != 0 || result == nullptr) {
        std::cerr << "getaddrinfo failed: " << iResult << std::endl;
        WSACleanup();
        return 1;
    }

    // 选择第一个可用的地址和端口号并将其绑定到套接字上
    SOCKADDR_IN serverAddr;
    int serverPort;
    iResult = bind(sock, result->ai_addr, (int) result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        std::cerr << "bind failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }
    else if (iResult == sizeof(serverAddr)) { // 如果无法分配内存，则返回错误。这通常发生在32位系统上。在64位系统上，此代码将正常工作。
        std::cerr << "bind failed" << std::endl;
        closesocket(sock);
        WSACleanup();
        return 1;
    }
}


