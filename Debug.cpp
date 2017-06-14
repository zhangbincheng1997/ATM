#ifndef _DEBUG_H
#define _DEBUG_H

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h> // 文件操作头文件
#include <sys/types.h> // 文件操作头文件
#include <sys/stat.h> // 文件操作头文件
#include <fcntl.h> // 文件操作头文件

// MAIN
void MENU_MAIN()
{
    printf("-------------------MAIN---------------------\n");
    printf("[q]退出	    [0]菜单\n");
    printf("[1]工作	    [2]休息\n");
    printf("[3]状态	    [4]ATM\n");
    printf("--------------------------------------------\n");
}

// ATM
void MENU_ATM()
{
    printf("-------------------ATM----------------------\n");
    printf("[q]退出	    [0]菜单\n");
    printf("[1]登录	    [2]注册\n");
    printf("[3]存钱	    [4]取钱\n");
    printf("[5]查询余额	    [6]查询记录\n");
    printf("[7]口袋余额	    [8]MAIN\n");
    printf("--------------------------------------------\n");
}

// 测试
void DEBUG()
{
    char path[] = "debug.txt";
    int fd;

    fd = open(path, O_RDONLY);
    if(fd == -1)
	exit(0);

    char buf[1024];
    while(read(fd, buf, sizeof(buf) - 1) > 0)
	printf("%s\n", buf);

    close(fd);
}

// 加载
void LOAD()
{
    int i = 33;
    while(i--) {
	putchar('#');
	fflush(stdout);
	usleep(33 * 1000);
    }
    putchar('\n');
}

#endif

