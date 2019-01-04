/* alarm_pause.c */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ret = alarm(5);
    printf("%d\n", ret);
	pause();
	printf("I have been waken up: %d\n",ret);
}