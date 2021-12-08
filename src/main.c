#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

int* nombre = 0;

int main()
{
	int lower = 10, upper = 120;
	int nbrFils = 0, nbrFilsSimul = 3;
	srand(time(0));
	int nbrRand = (rand() % (upper - lower + 1)) + lower;

	do{
		printf("Entrer un nombre de fork() : ");
		scanf("%d", &nbrFils);
		printf("\n");
	}while(nbrFils>10);

	for(int i=0; i<nbrFils; i++){
		if(fork() == 0){
			printf("je suis un fils numéro %d (pid fils) --> %d (pid parent) --> %d\n", i, getpid(), getppid());
			nombre = nbrRand;
			printf("%d\n", nombre);
			exit(0);
		}else{
			if(nbrFils >= nbrFilsSimul){
				wait(NULL);
				nbrFils--;
			}
			nbrFils++;
		}
		
	}
}

