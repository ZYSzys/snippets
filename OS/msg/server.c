#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define MSGKEY 75

struct msgform
{
    long mtype;
    char mtext [256];
}msg;

int msgqid;
int main()
{
    int i, pid, *pint;
    extern void cleanup();
    for(i = 0; i < 20; i++)
    {
        signal(i, cleanup);
    }
    msgqid = msgget(MSGKEY, 0777|IPC_CREAT);
    for(;;)
    {
        msgrcv(msgqid, &msg, 256, 1, 0);
        pint = (int*)msg.mtext;
        pid = *pint;
        printf("server: receive from pid %d\n", pid);
        msg.mtype = pid;
        *pint = getpid();
        msgsnd(msgqid, &msg, sizeof(int), 0);
    }
    return 0;
}

void cleanup()
{
    msgctl(msgqid, IPC_RMID, 0);
    exit(0);
}
