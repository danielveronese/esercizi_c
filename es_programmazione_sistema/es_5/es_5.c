#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc,char *argv[]){

   if(argc=!2){
     
     printf("gli argomenti sono errati");
     exit(0);
   }
   char stringa[1000] ,codice[5];
   int p1p0[2],tot=0,pid;
pipe(p1p0);
   while(1){
 
        printf("inserire il codice ");
        scanf("%s",codice);
        if(strcmp(codice,"esci")==0){

          printf("il totale degli insoluti sono %d",tot);

          close(p1p0[1]);
          close(p1p0[0]);

            exit(1);
        }     


        pid=fork();

        if(pid==0){

            close(p1p0[0]);  
            close(1);
            dup(p1p0[1]);
            close(p1p0[1]);

            execl("/usr/bin/grep","grep","-c",strcat(codice,"insoluto"),argv[1],NULL);
            return -1;

           }  
        
        close(p1p0[1]);

        read(p1p0[0],stringa,sizeof(stringa));
        tot= tot + atoi(stringa);

        printf("sono stati trovati %d",atoi(stringa));

   }
return 0;
}