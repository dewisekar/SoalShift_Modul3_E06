#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int in;
pthread_t tid[100];

void* faktorial(void *arg)
{
    int hasil=1;
    for (int i=in; i>=1; i--)
    	hasil=hasil*1;
    printf("Faktorial %d: %d\n", in, hasil);
    return NULL;
    
}



int main(int argc, char** argv)
{
	
	for(int i=0; i<argc-1; i++)
	{
		in=0;
		for(int j=0; j<strlen(argv[i+1]); j++)
		{
			in=in*10;
			in+=(argv[i+1][j]-'0');
		}
		printf("%d\n", in);
		pthread_create(&(tid[i]), NULL, &faktorial, NULL);
	}
	
}