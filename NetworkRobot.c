#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include "RobotFunctions.h"

void strtolower(char* str)
{
	int i=0;
	while(str[i] != '\0')
		str[i] = tolower(str[i]);
}

int main()
{
        int sock, nConnection, number_bytes_recieved , True = 1;  
        char send_data [1024] , recv_data[1024];       

        struct sockaddr_in server_socket_address, client_socket_address;    
        int sin_size;
        
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) 
		exit(1);

        if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&True,sizeof(int)) == -1) 
		exit(1);
        
        server_socket_address.sin_family = AF_INET;         
        server_socket_address.sin_port = htons(5000);     
        server_socket_address.sin_addr.s_addr = INADDR_ANY; 
        bzero(&(server_socket_address.sin_zero),8); 

        if (bind(sock, (struct sockaddr *)&server_socket_address, sizeof(struct sockaddr)) == -1) 
		exit(1);

        if (listen(sock, 5) == -1) 
		exit(1);
	
        fflush(stdout);


        while(1)
        {  

            sin_size = sizeof(struct sockaddr_in);
            nConnection = accept(sock, (struct sockaddr *)&client_socket_address,&sin_size);

		while (1)
		{
			number_bytes_recieved = recv(nConnection,recv_data,1024,0);

			recv_data[number_bytes_recieved] = '\0';
			//strtolower(recv_data);
			if (strcmp(recv_data , "q") == 0)
			{
				close(nConnection);
				break;
			}
			else
				rAction(recv_data);
			fflush(stdout);
		}
        }       

      close(sock);
      return 0;
} 
