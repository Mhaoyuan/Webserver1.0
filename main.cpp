#include <iostream>
#include"csapp.h"
#include <stdio.h>
#include <arpa/inet.h>
using namespace std;

/*
 * webserver1.0 -A simple. interative HTTP/1.0 Web server that uses the
 *     Get method to serve static and dynamic content
 */
void doit(int fd) {}
void read_requestdrs() {}
void server_static(char *uri, char* filename, char *cgiargs) {}
void get_filtype(char *filename, char* filetype){}
void serve_dynamic(int fd, char*filename , char* cgiargs){}
void clienterroe(int fd, char *cause, char* errnum,
                 char*shortmsg, char* longmsg){}



int main(int argc, char **argv) {
    void doit(int fd);
    void read_requestdrs(rio_t *rp);
    void parse_uir(char*uri, char*filename, char*cgiargs);
    void serve_static(int fd, char* filename, int filesize);
    void get_filtype(char *filename, char* filetype);
    void serve_dynamic(int fd, char*filename , char* cgiargs);
    void clienterroe(int fd, char *cause, char* errnum,
                        char*shortmsg, char* longmsg);




    return 0;
}