#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


int main()

{
        int sock;  
        char send_data[1024];
        struct hostent *host;
        struct sockaddr_in server_socket_address;  

        host = gethostbyname("192.168.1.5");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            perror("Socket");
            exit(1);
        }

        server_socket_address.sin_family = AF_INET;     
        server_socket_address.sin_port = htons(5000);   
        server_socket_address.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_socket_address.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_socket_address,
                    sizeof(struct sockaddr)) == -1) 
        {
            perror("Connect");
            exit(1);
        }

        while(1)
        {
        
		printf("\nSEND (q to quit) : ");
		gets(send_data);
           
		if (strcmp(send_data , "q") == 0 )
		{
			send(sock,send_data,strlen(send_data), 0); 
			close(sock);
			break;
		}
		else
			send(sock,send_data,strlen(send_data), 0);   
        }   
	return 0;
}
