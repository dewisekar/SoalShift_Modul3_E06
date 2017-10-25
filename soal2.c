#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
#include <string.h>

char player1[100];
char player2[100];
int lubang1[17];
int lubang2[17];
int poin1, poin2;
pthread_t player[3];
pthread_t keamanan;
pthread_t wasit;
int status=0;

void* pasang_player(void *arg){
	pthread_t id=pthread_self();
	int masang=1, ranjau;
	
	if (pthread_equal(id,player[1]))
	{
		/* code */
		while(masang<=4){
			printf("\n%s, anda memiliki %d kesempatan\nsst! saudara %s ingin memasang ranjau pada lubang ke: ", player1,5-masang,player1);
			scanf("%d", &ranjau);
			lubang1[ranjau]=1;
			masang++;
		}
	}

	else if (pthread_equal(id,player[2]))
	{
		/* code */
		while(masang<=4){
			printf("\n%s, anda memiliki %d kesempatan\nsst! saudara %s ingin memasang ranjau pada lubang ke: ", player2,5-masang,player2);
			scanf("%d", &ranjau);
			lubang2[ranjau]=1;
			masang++;
		}
	}

	
	status++;
}

void* nebak_player(void *arg){
	int nebak=1, ranjau;
	pthread_t id=pthread_self();

	if (pthread_equal(id,player[1]))
	{	

		while(nebak<4){
			printf("saudara %s menebak tempat yang aman ada pada lubang ke: ", player1);
			scanf("%d", &ranjau);
			if (lubang2[ranjau]!=1)
			{	

				poin1++;
				printf("selamat tebakan anda benar!sekarang poin anda berjumlah : %d\n", poin1);
				if (poin1==10)
				{	
					printf("%s menang!\n", player1);
					return 0;
				}
			}
			else if (lubang2[ranjau]==1)
			{
				/* code */
				poin2++;
				printf("selamat tebakan anda salah!sekarang poin musuh anda berjumlah : %d\n", poin2);
				if (poin2==10)
				{	
					printf("%s menang!\n", player2);
					return 0;
				}
			}
			nebak++;
		}
	}
	else if (pthread_equal(id,player[2]))
	{
		/* code */
		while(nebak<4){
			printf("saudara %s menebak tempat yang aman ada pada lubang ke: ", player2);
			scanf("%d", &ranjau);
			if (lubang1[ranjau]!=1)
			{
				/* code */
				poin2++;
				printf("selamat tebakan anda benar!sekarang poin anda berjumlah : %d\n", poin2);
				if (poin2==10)
				{
					/* code */
					printf("%s menang!\n", player2);
					return 0;
				}
			}
			else if (lubang1[ranjau]==1)
			{
				/* code */
				poin1++;
				printf("selamat tebakan anda salah!sekarang poin musuh anda berjumlah : %d\n", poin1);
				if (poin1==10)
				{	
					printf("%s menang!\n", player1);
					return 0;
				}
			}
			nebak++;
		}
	}

	status++;
}

void* cek_ranjau(void *arg){
	while(status==0){};
			status=0;
	int flag=0;
	for (int i = 1; i < 16; ++i)
	{
		
		if (lubang1[i]==0 || lubang2[i]==0)
		{
			flag++;
		}
	}

	if (flag==0)
	{	
		printf("seri\n");
		return 0;
	}
	status++;
}

void* score(void *arg){
	printf("\npoin %s: %d\n", player1,poin1);
	printf("\npoin %s: %d\n", player2,poin2);
}

int main(){
	char cek_skor[4];
	printf("masukan nama pemain anda\n");
	
	printf("player 1: ");
	scanf("%s", player1);
	printf("player 2: ");
	scanf("%s", player2);
	int n=1;
	while(n<3){
		pthread_create(&(player[n]),NULL,&pasang_player,NULL);
		while(status==0){};
		status=0;

		if (n==1)
		{
			pthread_create(&(player[2]),NULL,&nebak_player,NULL);
		}
		else if (n==2)
		{
			pthread_create(&(player[1]),NULL,&nebak_player,NULL);
			
		}

		pthread_create(&(keamanan),NULL,&cek_ranjau,NULL);
		while(status==0){};
		status=0;

		printf("Cek skor: ");
		scanf("%s", cek_skor);
		if (strcmp(cek_skor,"yes")==0)
		{
			/* code */
			pthread_create(&(wasit),NULL,&)
		}
		
		if (n==2)
			n=1;

	

		n++;
	}


}