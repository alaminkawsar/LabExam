#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    pid_t pid;
    pid = getpid();
    for(int i=0;i<1;i--){
       printf("I am child-%u running at CPU-%d.\n",pid,sched_getcpu());
       sleep(1);
    }

    return 0;
}