#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define BUF_SIZE 256


void DieWithError(char *errorMessage){
	perror(errorMessage);
	exit(1);
}

void common(int sock){
	char buf[BUF_SIZE];
	char buf_old[BUF_SIZE];
	char buf2[2*BUF_SIZE];	
	int len_r;
		char response[BUF_SIZE];
	
	buf_old[0]='\0';
	
	while((len_r=recv(sock,buf,BUF_SIZE,0))>0){
		//printf("%s\n",buf);レスポンス全体の表示//
		buf[len_r]='\0';
		
		sprintf(buf2,"%s%s",buf_old,buf);
		
		if(strstr(buf2,"\r\n\r\n")){
			
			break;
		}
		sprintf(buf_old,"%s",buf);
	}
    if (len_r <= 0)
        DieWithError("received() failed.");
    
    printf("received HTTP Request.\n");//←受け取ったことだけしめす//
	

    sprintf(response, "HTTP/1.1 200 OK\r\n");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
    
    sprintf(response, "Content-Type: text/html; charset=utf-8\r\n");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
        
    sprintf(response, "\r\n");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
    
    sprintf(response, "<!DOCTYPE html><html><head><title>");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
    
    sprintf(response, "ネットワークプログラミングのwebサイト");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
    
    sprintf(response, "</title></head><body>ネットワークダイスキ</body></html>");
    if(send(sock, response, strlen(response), 0) != strlen(response))
        DieWithError("send() sent a message of unexpected bytes");
}

int main(int argc, char **argv){
	int servSock=socket(PF_INET, SOCK_STREAM, 0);
	int cliSock;
	struct sockaddr_in servAddress;
	struct sockaddr_in clientAddress;
	unsigned int szClientAddr;
	
	
	if (servSock < 0)
        DieWithError("socket() failed");
    
	
	servAddress.sin_family=AF_INET;
	servAddress.sin_addr.s_addr=htonl(INADDR_ANY);
	servAddress.sin_port=htons(80);
	bind(servSock,(struct sockaddr*)&servAddress,sizeof(servAddress));
	listen(servSock,5);
	
	while(1){
		szClientAddr=sizeof(clientAddress);
		cliSock=accept(servSock,(struct sockaddr*)&clientAddress,&szClientAddr);
		
		common(cliSock);
		
		close(cliSock);
	}
	close(servSock);
	return 0;
}