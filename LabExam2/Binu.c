#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

int main(int pipeNumber, char *pipeName[])
{
    char *pipePath;
    char temp[100];
    strcpy(temp,"./");
    pipePath=temp;
    if(pipeNumber>1){
        //printf("%s %s\n",temp,pipeName[1]);
        strcat(temp,pipeName[1]);
    }
    else{
        printf("No argument pass\n");
        exit(-1);
    }
    //check pipe name  ./Pipe1
    //printf("Pipe Name: %s\n",pipePath);

    int fd;
    char buffer[200];
    fd = open(pipePath, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("%s\n",buffer);

    while(1){
        read(fd, buffer, sizeof(buffer));
        printf("Msg from Minu: %s\n",buffer);
        if(strcmp("Bye",buffer)==0){
            close(fd);
            return 0;
        }
        
        sleep(1);
        //execlp("./Binu",NULL);
    }


    return 0;
}