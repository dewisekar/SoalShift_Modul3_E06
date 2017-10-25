#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

FILE * finput;
pthread_t tid[1000];

int status;



/*void *readandcount (void *arg){
	int jumlah=0;
	finput = fopen("home/dewisekar/TUGAS_SISOP/modul3/SoalShift_Modul3_E06/Novel.txt", "r");
	if (finput==NULL) printf("File tidak ada!\n");
	while(fgets(storage,strlen(argv[i]),finput)!=NULL)
	{
		if(strcmp(argv[i],storage)==0)
			jumlah++;
	}
	//printf("%s: %d\n", argv[i],jumlah);

*/
int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
        int panjang=strlen(argv[i]);
        printf("%d\n", panjang);
    }
}
 //  fclose(finput);
