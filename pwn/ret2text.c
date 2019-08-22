/*************************************************************************
 @Author: le3d1ng
 @Created Time : 2019年08月19日 星期一 18时08分09秒
 @File Name: pwn1.c
 @Description:
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void init(){
    int fd;
    setvbuf(stdin,0,2,0);
    setvbuf(stdout,0,2,0);
    setvbuf(stderr,0,2,0);
    fd = open("/dev/urandom",0);
    close(fd);
    fd = open("./flag",O_RDONLY);
    if(fd==-1){
        puts("where is the flag?\n");
        exit(0);
    }
    close(fd);
    puts("欢迎各位2019级新生来到山东科技大学(泰安)·信息安全协会！");
    puts("非常期待能遇见喜欢pwn的新生23333");
    puts("");
    puts("简单的栈溢出~");
}

void youwin(){//0x080486b6
    puts("Wooo~TQL.Take my flag.");
    system("cat flag");
    getchar();
    getchar();
}

void vuln(){
    char buf[40];
    puts("give me your message :");
    read(0,buf,56);
}

int main(){
    init();
    vuln();
    return 0;
}
