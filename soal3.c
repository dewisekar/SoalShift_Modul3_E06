#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
pthread_t timer;
int status_lohan=100,status_kepiting=100;
pthread_t feeding[2];
int status=0;

void* stopwatch(void *arg){
	status++;
	for (int i = 1; i <= 100000; i++)
	{	
        sleep(1);
		if (i%10==0)
			status_lohan-=15;
		if (i%20==0)
			status_kepiting-=10;
	}
}

void* beri_makan(void *arg){
	pthread_t id= pthread_self();

	if (pthread_equal(id,feeding[1]))
	{
		status_lohan+=10;
		printf("status_lohan bertambah 10\n");
	}
	else if (pthread_equal(id,feeding[2]))
	{
		status_kepiting+=10;
		printf("status_kepiting bertambah 10\n");
	}
}

int main(){
	int menu;
	pthread_create(&(timer),NULL,&stopwatch,NULL);
	while(status==0){};
	while(1){
		printf("MENU\n1.beri makan lohan\n2.beri makan kepiting\n(1/2): ");
		scanf("%d", &menu);
		pthread_create(&(feeding[menu]),NULL,&beri_makan,NULL);

		if (status_lohan==0||status_kepiting==0||status_lohan>100||status_kepiting>100)
		{
			break;
		}
	}

	return 0;
}