#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

#define BUFF_SIZE 1024

int main(int argc, char **argv)
{
    int client_socket;

    struct sockaddr_in server_addr;

    char buff[BUFF_SIZE+5];

    client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == client_socket)
    {
        printf("fail to create socket\n");
        exit(-1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4000);
    server_addr.sin_addr.s_addr = inet_addr("192.168.43.212");

    if(-1 == connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)))
    {
        printf("fail to connection \n");
        exit(-1);
    }

    char* total_argv = (char*)malloc(sizeof(char)*strlen(argv[1]+1));
    strcpy(total_argv, argv[1]);
    strcat(total_argv, " ");
    for(int i=2; i<argc; i++)
    {
        total_argv = (char*)realloc(total_argv, sizeof(char)*(strlen(total_argv)+ strlen(argv[i])+1));
        strcat(total_argv, argv[i]);
        strcat(total_argv, " ");
    }
    
    // printf("argv[1]: %s\n",argv[1]);
    // write(client_socket, argv[1], strlen(argv[1])+1);
    printf("total: %s\n",total_argv);
    write(client_socket, total_argv, strlen(total_argv)+1);
    read(client_socket, buff, BUFF_SIZE);
    printf("%s\n",buff);
    close(client_socket);

    return 0;
}