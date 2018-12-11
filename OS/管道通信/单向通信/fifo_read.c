#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#define MYFIFO "/Users/zyszys/Desktop/myfifo"   /* 有名管道文件名 */
#define MAX_BUFFER_SIZE PIPE_BUF                /* 定义在 limits.h 中 */

int main(int argc, char * argv[])
{
    int fd, nread;
    char buff[MAX_BUFFER_SIZE];

    // 判断有名管道是否存在，若不存在则以相应的权限创建
    if(access(MYFIFO, F_OK) == -1)
    {
        if((mkfifo(MYFIFO, 0666) < 0) && (errno != EEXIST))
        {
            printf("Cannot create fifo file\n");
            exit(1);
        }
    }

    // 以只读阻塞方式打开有名管道
    fd = open(MYFIFO, O_RDONLY);
    if(fd == -1)
    {
        printf("Open fifo file error\n");
        exit(1);
    }

    while(1)
    {
        memset(buff, 0, sizeof(buff));
        if((nread = read(fd, buff, MAX_BUFFER_SIZE)) > 0)
        {
            printf("Read '%s' from FIFO\n", buff);
        }
    }

    close(fd);
    exit(0);
}
