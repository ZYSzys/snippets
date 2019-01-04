#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

#define MSGKEY 75

struct msgform
{
    long mtype;
    char mtext [256];
};

int main()
{
    struct msgform msg;
    int msgqid, pid, *pint;
    msgqid = msgget(MSGKEY, 0777);

    pid = getpid();
    pint = (int*)msg.mtext;
    *pint = pid;
    msg.mtype = 1;
    msgsnd(msgqid, &msg, sizeof(int), 0);
    msgrcv(msgqid, &msg, 256, pid, 0);
    printf("Client : recievie from pid%d\n", *pint);
    return 0;
}
