/**
 * @file http_server.h
 * @brief HTTP server component for the website server.
*/

#ifndef HTTP_SERVER_H
    #define HTTP_SERVER_H

    typedef struct HTTP_Server
    {
        int address;
        int port;
    } HTTP_Server;

    void ServerStart(HTTP_Server* server, int port);
#endif