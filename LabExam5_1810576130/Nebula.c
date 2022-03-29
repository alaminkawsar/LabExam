#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sched.h>
#include <wait.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <pthread.h>
#include <stdlib.h>
#define _GNU_SOURCE
pthread_mutex_t key;

void x()
{

    cpu_set_t mark;
    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);

    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);
    printf("Nebula Thread =%d, Pid: %d cpu: %d, scheduling_algorithm: %d\n", gettid(), getpid(), sched_getcpu(), sched_getscheduler(0));
}

void y()
{
    cpu_set_t mark;
    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);

    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);
    printf("Nebula Thread =%d, Pid: %d cpu: %d, scheduling_algorithm: %d\n", gettid(), getpid(), sched_getcpu(), sched_getscheduler(0));
}

int main()
{
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, (void *)x, NULL);
    pthread_create(&tid2, NULL, (void *)y, NULL);

    cpu_set_t mark;

    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);
    pthread_getaffinity_np(pthread_self(), sizeof(cpu_set_t), &mark);
    for (int i = 0; i < 10; i++)
        printf("Nebula Thread =%d, Pid: %d cpu: %d, scheduling_algorithm: %d\n", gettid(), getpid(), sched_getcpu(), sched_getscheduler(0));

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
