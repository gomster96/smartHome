#ifndef SERVER_H
#define SERVER_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
// #include <string>
// #include <cstring>
#include "control.h"

using namespace std;
#define BUFF_SIZE 1024

class Server
{
    public:
        void init();
        void work();
    private:
        int server_socket;
        int client_socket;
        socklen_t client_addr_size;
        struct sockaddr_in server_addr;
        char buff_rcv[BUFF_SIZE+5];
        char buff_snd[BUFF_SIZE+5];
        
        Control start;
};

#endif
