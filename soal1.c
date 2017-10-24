#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

pthread_t seller[3];
pthread_t buyer[3];
int 

void* menu_jual(void *arg){
	unsigned long i=0;
	pthread_t id=pthread_self();

	if (pthread_equal(id,seller[1]))
	{
		/* code */
		printf("%s\n", );

	}
}

void* menu_beli(void *arg){
	unsigned long i=0;
	pthread_t id=pthread_self();

	if (pthread_equal(id,buyer[1]))
	{
		/* code */
		printf("%s %d\n", );

	}
}


int main(void)
{	
	char user[8];
	int err, n;

	scanf("%s", user);
	while(strcmp(user,"logout")==0){
		if (strcmp(user,"pembeli")==0)
		{
			/* code */
			printf("1.stock senjata\n2.beli senjata\n");
			printf("masukan input(1/2): ");

			scanf("%d", &n);
			err=pthread_create(&(buyer[n]),NULL,&menu_beli,NULL);
		}
		else if (strcmp(user,"penjual")==0)
		{	
			printf("1.stock senjata\n2.tambah stock senjata\n");
			printf("masukan input(1/2): ");

			scanf("%d", &n);
			err=pthread_create(&(seller[n]),NULL,&menu_jual,NULL);	
		}
		else{
			printf("error\n");
		}
	}
	return 0;
}