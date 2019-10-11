#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 256
#define MONEY_DIGIT_SOZE 10

void DieWithError(char *);
int prepare_client_socket(char *, int);
void void commun(int);

int main(int argc, char **argv[])
{
    if (args != 3)
        DieWithError("usage: client ./client ip_address port");
    int sock

        void DieWithError(char *errorMesseage)
    {
        perror(errorMessage);
        exit(1);
    }
 int prepare_client_socket(char *ipaddr, int port){
     int sock = socket(PF_INET, SOCK_STREAM, 0 );
     if (sock < 0)
        DieWithError("socket() failed");

    struct sockaddr_in target;
    target.sin_familly = AF_INET;
    target.sin_addr.s_addr = inet_addr(ipaddr);
    target.sin_port = htons(port);
    if (connect(sock, (struct sockaddr*)&target, sizeof(target) < 0)
        DieWithError("connect() failed");
    
    return sock;

 }