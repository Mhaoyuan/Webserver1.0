#include <iostream>
#include"csapp.h"
#include <stdio.h>
#include <arpa/inet.h>
#include "opensocket.h"
#include "rio.h"
using namespace std;

/*
 * webserver1.0 -A simple. interative HTTP/1.0 Web server that uses the
 *     Get method to serve static and dynamic content
 */
void doit(int fd);
void read_requestdrs(rio_t *rp);
int parse_uir(char*uri, char*filename, char*cgiargs);
void serve_static(int fd, char* filename, int filesize);
void get_filtype(char *filename, char* filetype);
void serve_dynamic(int fd, char*filename , char* cgiargs);
void clienterror(int fd, char *cause, char* errnum,
                 char*shortmsg, char* longmsg);
void get_filetype(char* filename , char* filetype);




int main(int argc, char **argv) {


    int listenfd ,connfd;
    char hostname[MAXLINE], port[MAXLINE];
    socklen_t clientlen;
    struct sockaddr_storage clientaddr;
    argv[1] = "9888";

    /* Check command-line args */
//    if(argc!=2){
//        fprintf(stderr,"usage:%s<port>\n",argv[0]);
//        exit(1);
//    }
    listenfd = open_listenfd(argv[1]);

    while(1)
    {
        clientlen = sizeof(clientaddr);
        connfd = accept(listenfd, (SA*)& clientaddr,&clientlen);
        getnameinfo((SA*)&clientaddr,clientlen, hostname, MAXLINE,port,MAXLINE, 0);
        printf("Accepted connection form (%s %s)\n", hostname, port);
        doit(connfd);
        close(connfd);
    }

}

void doit(int fd) {
    int is_static;
    struct stat sbuf;
    char buf[MAXLINE],method[MAXLINE],uri[MAXLINE],version[MAXLINE];
    rio_t rio;

    char filename[MAXLINE],cgiargs[MAXLINE];
    rio_readinitb(&rio,fd);
    rio_readlineb(&rio,buf, MAXLINE);
    printf("Request headers:\n");
    printf("%s", buf);
    sscanf(buf,"%s %s %s", method, uri, version);
    if(strcasecmp(method,"GET"))
    {
        clienterror(fd, method,"501", "Not implemented",
                    "Tiny does not implement this method");
        return;
    }
    read_requestdrs(&rio);
    /* Parse URI from GET request */
    is_static = parse_uri(uri, filename, cgiargs);


}
void read_requestdrs(rio_t *rp) {
    char buf[MAXLINE];

    rio_readlineb(rp, buf,MAXLINE);
    while(strcmp(buf,"\r\n"))
    {
        rio_readlineb(rp, buf, MAXLINE);
        printf("%s", buf);
    }
}
int parse_uir(char*uri, char*filename, char*cgiargs){
    char *ptr;
    if(!strstr(uri,"cgi-bin")) //Static cintent
    {
        strcpy(cgiargs,"");
        strcpy(filename, ".");
        strcat(filename,uri);
        if(uri[strlen(uri)-1] == '/')
            strcat(filename,"home.html");
        return 1;
    }
    else {
         //Dynamic content
        ptr = index(uri,'?');
        if(ptr) {
            strcpy(cgiargs,ptr+1);
            *ptr='\0';
        }
        else strcpy(cgiargs,"");
        strcpy(filename,".");
        strcat(filename,uri);
        return 0;
    }
}
void server_static(char *uri, char* filename, char *cgiargs)
{
    int srcfd;
    char *srcp ,filetype[MAXLINE], buf[MAXBUF];
    /* Send response headers to client*/

    get_filetype(filename,filetype);
}
void get_filtype(char *filename, char* filetype){}
void serve_dynamic(int fd, char*filename , char* cgiargs){}
void clienterror(int fd, char *cause, char* errnum,
                 char*shortmsg, char* longmsg){
    char buf[MAXLINE], body[MAXLINE];

    /* Build the http response body*/
    sprintf(body,"<html><title> webserver error</title>");
    sprintf(body,"%s<body bgcolor = ""ffffff"">\r\n",body);
    sprintf(body,"%s%s: %s\r\n", body,errnum,shortmsg);
    sprintf(body,"%s<p>%s: %s\r\n",body, longmsg,cause);
    sprintf(body,"%s<hr><em> The Wen Server</em>\r\n", body);

    /* Print the HTTP response */
    sprintf(buf, "HTTP/1.0 %s %s\r\n", errnum,shortmsg);
    rio_writen(fd, buf, strlen(buf));
    sprintf(buf ,"Content-type； text/html\r\n");
    rio_writen(fd,buf,strlen(buf));
    sprintf(buf, "Content-length:%d\r\n\r\n", (int)strlen(body));
    rio_writen(fd,buf,strlen(buf));
    rio_writen(fd,body,strlen(body));

}
void get_filetype(char* filename, char* filetype) {
    if(strstr(filename, ".html"))
        strcpy(filetype, "text/html");
    else if(strstr(filename,".gif"))
        strcpy(filetype,"image/html");
    else if(strstr(filename, ".png"))
        strcpy(filetype,"image/png");
    else if (strstr(filename,".jpg"))
        strcpy(filename,"iamge/jpeg");
    else strcpy(filetype,"text/plain");
}