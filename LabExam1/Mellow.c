#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<stdlib.h>

int main(){
	pid_t cpid, pid, cc,i;

	cpid = fork(); 
	if (cpid < 0){ 
		printf("Unsuccessfull(:");
		exit(-1);
	}
	else if (cpid == 0){ 
		execlp("./Killow",NULL);

	}
	else if(cpid > 0){ 
		pid_t ccpid = fork();
		if(ccpid==0){
			execlp("./Pillow",NULL);
		}else if(ccpid>0){
			for(int i=0;i<1;i--){
				printf("Process-%u, parent of Pillow-%u and Killow-%u, running at CPU-%d.\n",getpid(),ccpid,cpid,sched_getcpu());
				sleep(1);
			}
		}
		
	}

	return 0;
}