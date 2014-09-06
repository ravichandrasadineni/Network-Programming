#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libs/portutility.h"
#define MAX_LINE_LENGTH  4096
#define MAX_QUEUE 1024

int main(int argc, char* argv[]) {
    int listenfd, connfd, port_number;
    struct sockaddr_in servAddr;
    time_t ticks;
    char buff[MAX_LINE_LENGTH];

    // checking if the user has passed the port number as the command line argument
    if (argc !=2) {
        printf("usage ./a.out portNumber \n");
        return 1;
    }

    /* setting the protocol so that socket will choose the appropriate protocol */
    
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (listenfd < 0) {
        perror("SOCKET CREATION ERROR : ");
    }
    
    memset (&servAddr,0 , sizeof(servAddr));
    if(!is_valid_port(argv[1])) {
        printf("the port number %s is not valid \n", argv[1]);
        return 1;
    }
    port_number = atoi(argv[1]);
    printf("the port number is %d \n", port_number); 
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port_number);
    printf("the port number is %d \n", servAddr.sin_port);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    if (bind (listenfd, (struct sockaddr *) &servAddr, sizeof(servAddr) ) == -1) {
        perror("Server Adress Binding FAILURE :");
        return 2;
    }

    if (listen (listenfd, MAX_QUEUE) == -1) {
        perror("listen failed");
    }

    while(1) {
        connfd = accept(listenfd, (struct sockaddr* ) NULL, NULL );
        ticks = time(NULL);
        snprintf(buff, sizeof (buff), "%.24s\r\n", ctime ( &ticks ) );
        if ( write ( connfd, buff, strlen(buff) ) == -1 ) {
            perror("socket write failure :");
        }
    
    }
       
    getchar ();

}




    

    





