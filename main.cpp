#include <iostream>
#include"csapp.h"
#include <stdio.h>
#include <arpa/inet.h>
using namespace std;

int foo()
{
    return 1;
}
int main(int argc, char **argv) {
//    int fd1,fd2;
//    char r[10];
//    char *p =r;
//    int a =1 ;
//    fd1 = open("/home/genius/Documents/Webserver1.0/foo.txt",O_RDWR,0);
//    fd2 = open("/home/genius/Documents/Webserver1.0/foo.txt",O_RDWR,0);
//    int n = read(fd2,&r,20);
//    int n = rio_readn(fd1,&r,50);
//    int n1 = rio_readn(fd1,&r,10);
//    int a = read(fd2,&r,50);
//    int a1 = read(fd2,&r,10);
//    dup2(fd2,fd1);
//    read(fd1,&r,1);
//    cout << n<<"c" <<n1<< endl;
//    cout << a << "c"<< a1 << endl;
//    cout << fd1<<endl;
//        rio_t rio;
//    rio_readinitb(&rio,fd1);
//    ssize_t n =rio_readlineb(&rio,r,20);

//    if ((a=foo())==2)
//        *p++ = 'c';
//        cout << *p++ <<endl;
//        cout << *p <<endl;

//    char *src = "128.2.210.175";
//    int ip;
//    int ip = inet_pton(AF_INET,src,ip);
//    exit(0);
//    struct in_addr inaddr;
//    uint32_t addr;
//    char buf[MAXBUF];
//     if(argc!= 2)
//         exit(0);
//     sscanf(argv[1],"%x", &addr);
//     inaddr.s_addr = htonl(addr);
//     inet_ntop(AF_INET,&inaddr,buf,MAXBUF);
//     cout << buf<< endl;
//     sockaddr_in sock;
//     unsigned char sin[8];
//     cout << sizeof(inaddr) <<endl;
    struct addrinfo *p, *listp ,hints;
    char buf[MAXBUF];
    int rc, flags;
//    if (argc !=2)
//    {
//        cout << stderr << argv[0];
//    }
    argv[1] = "wwww.baidu.com";
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family  = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp))!=0)
    {
        fprintf(stderr, "geraddrinfo error :%s\n" ,gai_strerror(rc));
        exit(1);
    }
    flags = NI_NUMERICHOST;
    for(p = listp;p; p = p->ai_next) {
        getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXBUF, NULL, 0, flags);
        cout<< buf <<endl;
    }
    freeaddrinfo(listp);
    exit(0);




    return 0;
}