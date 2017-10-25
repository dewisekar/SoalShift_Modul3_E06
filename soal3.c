#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>
pthread_t timer;
int status_lohan=100,status_kepiting=100;
pthread_t feeding[3];
int status=0;
int i;
void* stopwatch(void *arg){
	for (i = 1; i <= 100000; i++)
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
	else if (pthread_equal(id,feeding[3]))
	{
		printf("\n\nsudah %d detik sejak permainan dimulai\nkeadaan lohan: %d\nkeadaan kepiting: %d\n", i, status_lohan, status_kepiting);
	}
	status++;
}

int main(){
	int menu;
	pthread_create(&(timer),NULL,&stopwatch,NULL);
	while(1){
		printf("\n\nMENU\n1.beri makan lohan\n2.beri makan kepiting\n3.cek waktu dan keadaan lohan/kepiting\n(1/2/3): ");
		scanf("%d", &menu);
		pthread_create(&(feeding[menu]),NULL,&beri_makan,NULL);
		
		while(status==0){};
		status=0;


		if (status_lohan<=0||status_kepiting<=0||status_lohan>100||status_kepiting>100)
		{
			return 0;
		}
	}
}