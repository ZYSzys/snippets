#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int main() 
{
	pid_t pid;
	pid = fork();
	int newret;
	int count;
	if (pid == 0) {
		char *args[] = {"ls","-l","/home",NULL};
		execvp("ls", args);
		exit(0);
	} else if (pid > 0) {
		newret = system("ping www.baidu.com");
		exit(0);
	} else {
		perror("Error: Create child process failed!");
		exit(0);
	}
	return 0;
}
