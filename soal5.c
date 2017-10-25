#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

FILE * finput;
pthread_t tid[1000];

int panjang;
char kata[100];


void *readandcount (void *arg){
	int jumlah=0;
	finput = fopen("home/dewisekar/TUGAS_SISOP/modul3/SoalShift_Modul3_E06/Novel.txt", "r");
    char storage[panjang+1];
	if (finput==NULL) printf("File tidak ada!\n");
	while(fgets(storage,panjang+1,finput)!=NULL)
	{
        printf("%s\n", kata);
		if(strcmp(kata,storage)==0)
			jumlah++;
	}
	printf("%s: %d\n", kata,jumlah);
    fclose(finput);
}


int main(int argc, char** argv) {
    int err;
    for (int i = 0; i < argc-1; i++) {
        printf("%s\n", argv[i+1]);
        panjang=strlen(argv[i+1]);
        printf("%d\n", panjang);
        for(int j=0; j<panjang; j++)
            kata[j]=argv[i][j];
        //printf("%s\n", kata);
        err=pthread_create(&(tid[i]),NULL,&readandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
    }
    
}
 
