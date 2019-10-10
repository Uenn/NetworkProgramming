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

        void
        DieWithError(char *errorMesseage)
    {
        perror(errorMessage);
        exit(1);
    }
