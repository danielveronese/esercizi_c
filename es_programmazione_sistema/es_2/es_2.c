#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>



int main(int argc,char *argv[]){


    if(argc=!2){
 
     printf("gli argomenti sono errati");      

       exit(1);
    }

    int fd,p1p0[2],p2p0[2],pid;

    pipe(p1p0);
    pid=fork();
    if(pid==0){

        close(p1p0[0]);
        close(1);
        dup(p1p0[1]);
        close(p1p0[1]);
                         
       execl("/bin/cat","cat",argv[1],NULL);
       return -1;                  
    }


    pipe(p2p0);
    pid= fork();
 if(pid==0){
 
     close(p1p0[1]);
     close(0);
     dup(p1p0[0]);
     close(p1p0[0]);


     close(p2p0[0]);
     close(1);
     dup(p2p0[1]);
     close(p2p0[1]);
    
    execl("/bin/wc","wc",NULL);

return-1;

 }

 close(p1p0[0]);
 close(p1p0[1]);
 close(p2p0[1]);
 close(0);
 dup(p2p0[0]);
 close(p2p0[0]); 
 open("wc.txt",O_WRONLY | O_CREAT,0777);

 execl("/bin/tee","tee",NULL);

return -1;
}