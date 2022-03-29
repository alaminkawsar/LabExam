#define _GNU_SOURCE
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<string.h>
#include<wait.h>
#include<stdlib.h>
#include<sched.h>
#include<semaphore.h>

int getshemaphorID(){
    key_t k;
    k = ftok("create.c",'a');
    int id = shmget(k,1024,IPC_CREAT | 0666);
    return id;
}

int main(int num, char *number[]){
    int num1 = atoi(number[1]), num2 = atoi(number[2]);
    sem_t *loc = sem_open("/loc",O_CREAT,0666,1);

    printf("Mittu pid=%d, CPU=%d, num1=%d, num2=%d\n",getpid(),sched_getcpu(),num1,num2);

    int sID = getshemaphorID();
    char *memlocation = shmat(sID,NULL,0);

    int result = atoi(memlocation);
    result = result+num1*num2;

    printf("Mittu Result: %d\n",result);
    sprintf(memlocation,"%d",result);
    sem_post(loc);
    shmdt(loc);
    shmdt(memlocation);

}
