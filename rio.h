//
// Created by genius on 18-7-26.
//

#ifndef WEBSERVER_RIO_H
#define WEBSERVER_RIO_H
#include<sys/types.h>
#define RIO_BUFSIZE 8192


typedef struct {
    int rio_fd;
    ssize_t rio_cnt;
    char* rio_bufptr;
    char rio_buf[RIO_BUFSIZE];
}rio_t;

ssize_t rio_readn(int fd, void* usrbuf, size_t n);
ssize_t rio_writen(int fd, void *usrbuf, size_t n);
void rio_readinitb(rio_t* rp, int fd);
ssize_t rio_readlineb(rio_t* rp, void* usrbuf, size_t maxlen);
ssize_t rio_readnb(rio_t *rp, void *usrbuf, size_t n);
#endif //WEBSERVER_RIO_H
