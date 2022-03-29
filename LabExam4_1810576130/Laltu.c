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

int main(){
    int num1,num2; 
    scanf("%d%d",&num1,&num2);

    char a[10],b[10];
    sprintf(a,"%d",num1);
    sprintf(b,"%d",num2);

    int shmid = getshemaphorID();
    char *result = shmat(shmid,NULL,0);
    sprintf(result,"%d",0);
    shmdt(result);

    pid_t cid,ccid,cccid;
    cid = fork();
    if(cid==0){
        execlp("./Ittu","Ittu",a,b,NULL);
    }
    ccid = fork();
    if(ccid==0){
        execlp("./Bittu","Bittu",a,b,NULL);
    }

    cccid = fork();
    if(cccid==0){
        execlp("./Mittu","Mittu",a,b,NULL);
    }
    
    wait(NULL);
    return 0;

}