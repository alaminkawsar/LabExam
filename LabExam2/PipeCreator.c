#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(int pipeNumber, char *pipeName[]){
    int status;

    /*
    for(int i=0;i<pipeNumber;i++){
        printf("%s\n",pipeName[i]);
    }
    */
    
    for(int i=0;i<pipeNumber;i++){
        //ignoring first argument
        if(i==0) continue;
        if(access(pipeName[i],F_OK)==0){
            printf("%s Exist\n",pipeName[i]);
            //continue;
        }
        else{
            status = mkfifo(pipeName[i],0666);
            if(status<0){
                printf("Error!\n");
                exit(-1);
            }else{
                printf("%s Created\n",pipeName[i]);
            }
        }
    }
    
}