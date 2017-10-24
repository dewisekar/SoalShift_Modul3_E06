#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

File *finput;
pthread_t tid[2]

char str1[10],str2[10];
int jumstr1=0, jumstr2=0;
int status;
int panjang;

void *readandcount (void *arg){

	if(status==0)
	{
		panjang=strlen(str1);

	}

}

int main(){

	char str1[10],str2[10];
	scanf("%s %s", &str1, &str2);
	int i=0;
    int err;
    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,&playandcount,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }

}