#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <sys/syscall.h>
#include <unistd.h>

int result = 0;

pthread_mutex_t key;
int signal=0;

void Ittu(int *arg)
{
    
    //printf("%d\n",sum);
    int i, cpuNo;
    pid_t pid, tid;
    
    pid = getpid();
    tid = syscall(SYS_gettid);

    for (i = 0; i < 1; i++)
    {
        pthread_mutex_lock(&key);
        result = arg[0] + arg[1];
        cpuNo = sched_getcpu();
        printf(" Ittu (PID : %d, TID: %d) is running in CPU-%d and result = %d\n", pid, tid, cpuNo, result);
        pthread_mutex_unlock(&key);
    }
    if(result==100 || signal){
        signal=1;
        _exit(-1);
    }
}

void Bittu(int *arg)
{
    
   
    int i, cpuNo;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);

    for (i = 0; i < 1; i++)
    {
        pthread_mutex_lock(&key);
        result = arg[0] - arg[1];
        cpuNo = sched_getcpu();
        printf(" Bittu (PID: %d, TID: %d) is running in CPU-%d and result = %d\n", pid, tid, cpuNo, result);
        pthread_mutex_unlock(&key);
    }
    if(result==100 || signal){
        signal=1;
        _exit(-1);
    }
}
void Mittu(int *arg)
{
    
    
    int i, cpuNo;
    pid_t pid, tid;
    pid = getpid();
    tid = syscall(SYS_gettid);

    for (i = 0; i < 1; i++)
    {
        
        pthread_mutex_lock(&key);
        result = arg[0] * arg[1];
        cpuNo = sched_getcpu();
        printf(" Mittu (PID: %d, TID: %d) is running in CPU-%d and result = %d\n", pid, tid, cpuNo, result);
        pthread_mutex_unlock(&key);
    }
    if(result==100 || signal){
        signal=1;
        _exit(-1);
    }
}

int main()
{
    pthread_t tid1, tid2, tid3;
    int i, cpuNo;
    pid_t pid, tid, cpid;
    for (int test = 0; test < 100; test++)
    {
        int number[2];
        scanf("%d%d", &number[0], &number[1]);

        pid = getpid();
        tid = syscall(SYS_gettid);
        pthread_create(&tid1, NULL, (void *)Ittu, number);
        if(signal){
            _exit(-1);
        }
        pthread_create(&tid2, NULL, (void *)Bittu, number);
        if(signal){
            _exit(-1);
        }
        pthread_create(&tid3, NULL, (void *)Mittu, number);
        if(signal){
            _exit(-1);
        }
        /*
	for (i = 0; i < 1; i++)
	{
		cpuNo = sched_getcpu();
		printf("Main thread of Parent (PID: %d, TID: %d) is running in CPU-%d\n", pid, tid, cpuNo);
	}
	*/
        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);
        pthread_join(tid3, NULL);
    }

    return 0;
}
