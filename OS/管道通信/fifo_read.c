#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#define MYFIFO "/Users/zyszys/Desktop/myfifo"
#define MAX_BUFFER_SIZE PIPE_BUF

int main(int argc, char * argv[])
{
    int fd, nread;
    char buff[MAX_BUFFER_SIZE];

    if(access(MYFIFO, F_OK) == -1)
    {
        if((mkfifo(MYFIFO, 0666) < 0) && (errno != EEXIST))
        {
            printf("Cannot create fifo file\n");
            exit(1);
        }
    }

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