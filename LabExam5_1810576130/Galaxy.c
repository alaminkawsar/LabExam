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

int main(){
    pid_t cid,ccid,cccid;
    cid = fork();
    int loop=100;
    if(cid==0){
        for(int i=0;i<loop;i++){
            execlp("./Nebula",NULL);
        }
    }
    ccid = fork();
    if(ccid==0){
        for(int i=0;i<loop;i++){
            execlp("./BlackHole",NULL);
        }
    }
    
    wait(NULL);
    return 0;

}