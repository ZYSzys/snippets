#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

#define MYFIFO "/Users/zyszys/Desktop/myfifo"
#define YOURFIFO "/Users/zyszys/Desktop/yourfifo"
#define MAX_BUFFER_SIZE PIPE_BUF

void ReadFromYourFIFO()
{
	char buff[MAX_BUFFER_SIZE];
	int fd;
	int nread;

	if (access(YOURFIFO, F_OK) == -1) {
		if ((mkfifo(YOURFIFO, 0666) < 0) && (errno != EEXIST)) {
			printf("Cannot create fifo file\n");
			exit(1);
		}
	}
	fd = open(YOURFIFO, O_RDONLY);
	if (fd == -1) {
		printf("Open fifo file error\n");
		exit(1);
	}

	pid_t pid = getpid();
	char p[100];
	sprintf(p,"%d",pid);
	strcat(p, " ");
	strcat(p, buff);
	memset(buff, 0, sizeof(buff));
	if ((nread = read(fd, buff, MAX_BUFFER_SIZE)) > 0) {
		printf("fifo_write: received => %s\n", buff);
	}
	close(fd);
	return;
}

void WriteToMyFIFO()
{
	int fd;
	char buff[MAX_BUFFER_SIZE];
	int nwrite;
	fd = open(MYFIFO, O_WRONLY);
	if (fd == -1) {
		printf("Open fifo file error\n");
		exit(1);
	}
	while(1)
	{
    printf("请输入: ");
		scanf("%s", buff);

		pid_t pid = getpid();
		char p[100];
		sprintf(p,"%d",pid);
		strcat(p, " ");
		strcat(p, buff);
		if ((nwrite = write(fd, p, MAX_BUFFER_SIZE)) > 0) {
			printf("fifo_write: write => %s\n", p);
			ReadFromYourFIFO();
		}
	}
	close(fd);
	return;
}

int main(int argc, char * argv[]) {
	WriteToMyFIFO();
}
