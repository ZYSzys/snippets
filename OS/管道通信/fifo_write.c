#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#define MYFIFO "/Users/zyszys/Desktop/myfifo" /* 有名管道文件名 */
#define MAX_BUFFER_SIZE PIPE_BUF              /* 定义在 limits.h 中 */

int main(int argc, char * argv[])             /* 参数为即将写入的字符串 */
{
    int fd, nwrite;
    char buff[MAX_BUFFER_SIZE];
    if(argc <= 1)
    {
        printf("Usage: ./fifo_write string\n");
        exit(1);
    }
    sscanf(argv[1], "%s", buff);

    // 以只写阻塞方式打开 FIFO 管道
    fd = open(MYFIFO, O_WRONLY);
    if(fd == -1)
    {
        printf("Open fifo file error\n");
        exit(1);
    }

    // 向管道中写入字符串
    if((nwrite = write(fd, buff, MAX_BUFFER_SIZE)) > 0)
    {
        printf("Write '%s' to FIFO\n", buff);
    }
    close(fd);
    exit(0);
}
