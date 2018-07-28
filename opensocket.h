//
// Created by genius on 18-7-27.
//

#ifndef WEBSERVER_OPENSOCKET_H
#define WEBSERVER_OPENSOCKET_H


int open_clientfd(char* hostname, char* port);
int open_listenfd(char* port);
#endif //WEBSERVER_OPENSOCKET_H
