#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    pid_t pid;
    pid = getpid();
    pid_t child = fork();
    printf("%d %d\n",pid, child);

    return 0;
}