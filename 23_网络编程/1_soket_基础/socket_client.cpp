//
// Created by ZYB on 2025/3/27.
//
#include "socket_client.h"

int main(){
    int client_socket= socket(AF_INET,SOCK_STREAM,0); //客户端socket

    struct sockaddr_in server_address; //服务端信息
    memset(&server_address,0, sizeof(server_address));
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr= inet_addr("127.0.0.1");
    server_address.sin_port=htons(8888);

//    bind(client_socket,(sockaddr*)&server_address, sizeof(server_address)); //客户端无需绑定
    connect(client_socket,(sockaddr*)&server_address,sizeof(server_address));
    return 0;
}