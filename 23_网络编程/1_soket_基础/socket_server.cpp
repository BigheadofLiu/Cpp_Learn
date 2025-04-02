 //
 // Created by ZYB on 2025/3/27.
 //
 #include "socket_client.h"

 using namespace std;
 int main(){
     int server_socket= socket(AF_INET,SOCK_STREAM,0);
     struct sockaddr_in server_address;
 //    std::bzero(); bzero已弃用
     memset(&server_address,0,sizeof(server_address));
     server_address.sin_family=AF_INET; //指定ipv4
     server_address.sin_addr.s_addr= inet_addr("127.0.0.1");  //黑人问号  指定客户端ip
     server_address.sin_port= htons(8888);//指定端口号
     bind(server_socket,(sockaddr*)&server_address,sizeof(server_address)); //第二个选项必选强转
     listen(server_socket,SOMAXCONN); //监听

     struct sockaddr_in client_address;
     socklen_t client_address_len=sizeof (client_address);
     memset(&client_address,0,sizeof(client_address));
     int client_socket_find= accept(server_socket,(sockaddr*)&client_address,&client_address_len);
     cout<<"new client find:"<<client_socket_find<<"ip:"<<inet_ntoa(client_address.sin_addr)<<"端口号："<<client_address.sin_port<<endl;
 }

//#include <iostream>
//#include <cstring>
//
//#ifdef _WIN32
//    #include <winsock2.h>
//    #include <ws2tcpip.h>
//    #pragma comment(lib, "ws2_32.lib")
//#else
//    #include <arpa/inet.h>
//    #include <sys/socket.h>
//    #include <netinet/in.h>
//    #include <unistd.h>
//#endif
//
//using namespace std;
//
//int main() {
//    #ifdef _WIN32
//        WSADATA wsa;
//        if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
//            cerr << "WSAStartup failed" << endl;
//            return 1;
//        }
//    #endif
//
//    // 创建 socket
//    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
//    if (server_socket == -1) {
//        cerr << "Socket creation failed" << endl;
//        return 1;
//    }
//
//    struct sockaddr_in server_address;
//    memset(&server_address, 0, sizeof(server_address));
//    server_address.sin_family = AF_INET;
//
//    // 采用 inet_pton 替代 inet_addr
//    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
//        cerr << "Invalid address" << endl;
//        return 1;
//    }
//
//    server_address.sin_port = htons(8888);
//
//    // 绑定 socket
//    if (bind(server_socket, (sockaddr*)&server_address, sizeof(server_address)) == -1) {
//        cerr << "Bind failed" << endl;
//        return 1;
//    }
//
//    // 监听 socket
//    if (listen(server_socket, SOMAXCONN) == -1) {
//        cerr << "Listen failed" << endl;
//        return 1;
//    }
//
//    struct sockaddr_in client_address;
//    socklen_t client_address_len = sizeof(client_address);
//    memset(&client_address, 0, sizeof(client_address));
//
//    // 等待客户端连接
//    int client_socket_find = accept(server_socket, (sockaddr*)&client_address, &client_address_len);
//    if (client_socket_find == -1) {
//        cerr << "Accept failed" << endl;
//        return 1;
//    }
//
//    // 使用 inet_ntop 代替 inet_ntoa
//    char client_ip[INET_ADDRSTRLEN];
//    inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
//
//    cout << "New client connected: " << client_socket_find
//         << " IP: " << client_ip
//         << " Port: " << ntohs(client_address.sin_port) << endl;
//
//    // 关闭 socket
//    #ifdef _WIN32
//        closesocket(server_socket);
//        closesocket(client_socket_find);
//        WSACleanup();
//    #else
//        close(server_socket);
//        close(client_socket_find);
//    #endif
//
//    return 0;
//}

