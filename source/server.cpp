/**
* @file server.cpp
* @brief HTTP Server development file.
*/

#include "./includes/http_server.hpp"

#include <netinet/in.h>
#include <sys/socket.h>
#include <stdio.h>

/**
* This method is used to start the server.
*/

void InitializeServer(HTTP_Server * server, int port)
{
    server -> port = port;

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct socketAddress address;

    // Setting the socket family.
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    // Binding the socket to the address.
    bind(server, (struct sockaddr *) &address, sizeof(address));

    // Listening for connections.
    listen(server, 5);

    // Success.
    server -> socket = serverSocket;

    printf("[Protocol: HTTP] Starting server on port %d", server -> port);
}