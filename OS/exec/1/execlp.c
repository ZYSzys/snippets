/*execlp.c*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret = fork();
	printf("ret: %d\n", ret);
	if (ret == 0)
	{
		printf("ret is 0\n");
		if ((ret = execlp("git", "git", "config", "--help", NULL)) < 0)
		{
			printf("Execlp error\n");
		}
		return 0;
	}
	return 0;
}
