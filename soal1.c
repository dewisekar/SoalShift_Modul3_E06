#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

pthread_t seller[3];
pthread_t buyer[3];
int stock_senjata[10];

void* menu_jual(void *arg){
	unsigned long i=0;
	pthread_t id=pthread_self();

	if (pthread_equal(id,seller[1]))
	{
		/* code */
		if (stock_senjata[1]!=0)
		{
			/* code */
			printf("MP4A1 = %d\n",stock_senjata[1]);
		}
		if (stock_senjata[2]!=0)
		{
			/* code */
			printf("PM2-V1 = %d\n",stock_senjata[2]);
		}
		if (stock_senjata[3]!=0)
		{
			/* code */
			printf("SPR-3 = %d\n", stock_senjata[3]);
		}
		if (stock_senjata[4]!=0)
		{
			/* code */
			printf("SS2-V5 = %d\n", stock_senjata[4]);
		}
		if (stock_senjata[5]!=0)
		{
			/* code */
			printf("SPG1-V3 = %d\n",stock_senjata[5]);
		}
		if (stock_senjata[6]!=0)
		{
			/* code */
			printf("MINE = %d\n",stock_senjata[6]);
		}

	}
	else if (pthread_equal(id,seller[2]))
	{
		/* code */

	}
	else{
		printf("error\n");
	}
}

void* menu_beli(void *arg){
	unsigned long i=0;
	pthread_t id=pthread_self();
	char senjata[8];
	int jumlah_senjata;


	if (pthread_equal(id,buyer[1]))
	{
		/* code */
		
			printf("MP4A1 = %d\n",stock_senjata[1]);
			printf("PM2-V1 = %d\n",stock_senjata[2]);
			printf("SPR-3 = %d\n", stock_senjata[3]);
			printf("SS2-V5 = %d\n", stock_senjata[4]);
			printf("SPG1-V3 = %d\n",stock_senjata[5]);
			printf("MINE = %d\n",stock_senjata[6]);
	}
	else if (pthread_equal(id,buyer[2]))
	{
		/* code */
		scanf("%s %d", senjata, &jumlah_senjata);

		if (strcmp(senjata,"MP4A1")==0)
		{
			/* code */
			stock_senjata[1]+=jumlah_senjata;

		}

	}
	else{
		printf("error\n");
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
			printf("error try again\n");
		}
	}
	return 0;
}