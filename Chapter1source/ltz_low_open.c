#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void error_handling(char* message);

int main()
{
	int fd;
	char buf[]="WILL, let's go!\n";
	
	fd=open("ltz_data.txt", O_CREAT|O_RDWR|O_TRUNC);
        printf("%d\n", fd);
	if(fd==-1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if(write(fd, buf, sizeof(buf))==-1)
		error_handling("write() error!");
        close(fd);
	fd=open("ltz_data.txt", O_RDWR);
        char rbuf[65535];
        if(read(fd, rbuf, sizeof(rbuf))==-1)
		error_handling("read() error!");
        printf("data: %s\n", rbuf);
	close(fd);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/*
root@com:/home/swyoon/tcpip# gcc low_open.c -o lopen
root@com:/home/swyoon/tcpip# ./lopen
file descriptor: 3 
root@com:/home/swyoon/tcpip# cat data.txt
Let's go!
root@com:/home/swyoon/tcpip# 
*/
