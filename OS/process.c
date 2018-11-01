#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#define random(x) (rand()%x)

struct Process 
{
    int pid;
    int priority;
    int size;
    int status;
    char info[10];
};

struct Process memory[20];
int count = 0, hang = 0, pid, flag = 0;

void create()
{
    if(count >= 20)
        printf("\n内存已满，请先结束或唤出进程\n");
    else
    {
        int i, j;
        for(i = 0; i < 20; i++)
        {
            if(memory[i].status == 0)
                break;
        }
        printf("\n请输入新进程pid: ");
        //scanf("%d", &(memory[i].pid));
        memory[i].pid = random(20);
        printf("%d\n", memory[i].pid);
        for(j = 0; j < i; j++)
        {
            if(memory[i].pid == memory[j].pid)
            {
                printf("\n 该进程已存在 \n");
                return;
            }
        }
        printf("\n请输入新进程优先级\n");
        //scanf("%d", &memory[i].priority);
        memory[i].priority = random(20);
        printf("%d\n", memory[i].priority);
        printf("\n请输入新进程大小\n");
        //scanf("%d", &(memory[i].size));
        memory[i].size = random(20);
        printf("%d\n", memory[i].size);
        printf("\n请输入新进程内容\n");
        //scanf("%s", (memory[i].info));
        //memory[i].info = "w";
        printf("%s\n", memory[i].info);
        memory[i].status = 1;
        count++;
    }
    printf("\n创建进程成功!\n");
}

void run()
{
    for(int i = 0; i < count; i++)
    {
        if(memory[i].status == 1)
        {
            printf("Pid: %d\n", memory[i].pid);
            printf("优先级: %d\n", memory[i].priority);
            printf("大小: %d\n", memory[i].size);
            printf("状态: %d\n", memory[i].status);
            printf("内容: %s\n", memory[i].info);
        }
    }
    if(!flag)
        printf ("\n 当前没有运行进程\n");
}

void hangout()
{
    if(!count)
    {
        printf("当前没有运行进程\n");
        return;
    }
    printf("\n请输入要唤出进程的PID值:");
    //scanf("%d", &pid);
    pid = random(20);
    printf("%d\n", pid);
    for(int i = 0; i < 20; i++) 
    {
        //定位，找到所要唤出的进程，根据其状态做相应处理
        if(pid == memory[i].pid)
        {
            if (memory[i].status == 1){
                memory[i].status = 2;
                hang++;
                printf("\n已经成功唤出进程\n");
            }
            else if (memory[i].status == 0) 
                printf("\n要唤出的进程不存在\n");
            else 
                printf ("\n 要唤出的进程已被挂起\n");
            flag = 1;
            break;
        }
    }
    //找不到，则说明进程不存在
    if (flag == 0) 
        printf("\n要唤出的进程不存在\n");
}

void kill()
{
    if (!count) {
        printf("当前没有运行进程\n");
        return;
    }
    printf("\n输入杀死进程的PID值");
    //scanf("%d", &pid);
    pid = random(20);
    printf("%d\n", pid);
    for(int i = 0; i < 20; i++) 
    {
      //定位，找到所要唤出的进程，根据其状态做相应处理
        if(pid == memory[i].pid)
        {
            if (memory[i].status == 1){
                memory[i].status = 0;
                count--;
                printf("\n已成功杀死进程\n");
            }
            else if (memory[i].status == 0) 
                printf("\n要杀死的进程不存在\n");
            else 
                printf("\n 要杀死的进程已被挂起\n");
            flag = 1;
            break;
        }
    }
    if (!flag) 
        printf("\n要杀死的进程不存在\n");
}

void wakeup()
{
    if (!count) {
        printf("当前没有运行进程\n");
        return;
    }
    if (!hang) {
        printf("当前没有挂起进程\n");
        return;
    }

    printf("\n请输入要唤醒进程的PID:\n");
    //scanf("%d", &pid);
    pid = random(20);
    printf("%d\n", pid);
    for(int i = 0; i < 20; i++) 
    {
        //定位，找到所要唤醒的进程，根据其状态做相应处理
        if(pid == memory[i].pid)
        {
            flag = 1;
            if (memory[i].status == 2)
            {
                memory[i].status = 1;
                hang--;
                printf("\n已经成功唤醒进程\n");
            }
            else if (memory[i].status == 0) 
                printf("\n要唤醒的进程不存在\n");
            else 
                printf("\n 要唤醒的进程已被挂起\n");
            break;
        }
    }
    //找不到，则说明进程不存在
    if (!flag) 
        printf("\n要唤醒的进程不存在");
}

int main()
{
    int n = 1, num, operations[8] = { 1, 2, 3, 2, 5, 2, 4, 2 };
    for(int i = 0; i < 20; i++)
    {
        memory[i].status = 0;
    }
    for(int i = 0; i < 8; i++)
    {
        printf("\n**********************************************");
        printf("\n*               进程演示系统                 *");
        printf("\n**********************************************");
        printf("\n     1.创建新的进程             2.查看运行进程");
        printf("\n     3.唤出某个进程             4.杀死运行进程");
        printf("\n     5.唤醒某个进程             6.退出系统    ");
        printf("\n**********************************************");
        printf("\n请选择(1～6): ");
        //scanf("%d",&num);
        num = operations[i];
        switch(num)
        {
            case 1: create(); break;
            case 2: run(); break;
            case 3: hangout(); break;
            case 4: kill(); break;
            case 5: wakeup(); break;
            case 6: exit(0);
            default: n = 0;
        }
        flag = 0;
        sleep(2);
    }
    return 0;
}

