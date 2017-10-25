#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

FILE * finput;





void* readandcount (void *arg){
    char storage[1000];
    char kata[100];
    int jumlah=0;

    strcpy(kata,arg);
    finput = fopen("/home/dewisekar/TUGAS_SISOP/modul3/SoalShift_Modul3_E06/Novel.txt", "r");
    if (finput==NULL) printf("File tidak ada!\n");

    while(fscanf(finput,"%s",storage))
    {
        if(strstr(storage,kata)!=NULL)
           { jumlah++;}
    }
    printf("%s: %d\n", kata,jumlah);
    return NULL;  
 
}
  


int main(int argc, char** argv) {
     pthread_t tid[100];
    for (int i = 0; i < argc-1; i++) {
       
        pthread_create(&(tid[i]),NULL,&readandcount,(void*)argv[i+1]);//membuat thread
      
    }
   for(int i=0; i<argc-1; i++)
    {
          pthread_join(tid[i],NULL);  
        
         
    }
 
}
   
    