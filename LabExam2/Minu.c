#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

int main(int pipeNumber, char *pipeName[])
{
    pid_t ppid,pid;
    int fd;

    char *pipePath;
    char temp[100];
    strcpy(temp,"./");
    pipePath=temp;
    if(pipeNumber>1){
        //printf("%s %s\n",temp,pipeName[1]);
        strcat(temp,pipeName[1]);
    }
    /*
        ./Pipe1
    */
    
    char s[100];
    char *msg = s;
    //printf("Check PipeName %s\n",pipePath);
    fd = open(pipePath, O_WRONLY);

    sprintf(s,"%d",(int)getpid());
    
    char ms[100];
    strcpy(ms,"My PID=");
    strcat(ms,s);
    strcat(ms,", My parent ID=");
    sprintf(s,"%d",(int)getppid());
    strcat(ms,s);
    write(fd, ms, strlen(ms) + 1);

    printf("%s\n",ms);

    while(1){
        scanf("%[^\n]s",s);
        printf("Msg: %s\n", s);
        write(fd, msg, strlen(msg) + 1);
        if(strcmp("Bye",s)==0){
            break;
        }
        getchar();
        //execlp("./Minu",NULL);
        //close(fd);
    }

    return 0;
}
