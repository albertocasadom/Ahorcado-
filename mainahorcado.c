#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* Variales globales necesarias para guardar la información introducida por los jugadores */

char  * palabra;
char * caracter;


char * leerteclado(){

	char * cadena = NULL;
	size_t len = 0;
	ssize_t read;

	read = getline(&cadena,&len,stdin);

	if(read == -1){

		cadena = NULL;

	}else{

		cadena[strlen(cadena)-1] = '\0';
	}

	return cadena;

}

void pintar_muneco(int fallo){

	switch(fallo){

		case 0:

			printf("------¬\n");
			printf("|     &\n");
			printf("|      \n");
			printf("|      \n");
			printf("|      \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 1:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|      \n");
			printf("|      \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 2:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|     8\n");
			printf("|      \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 3:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|    /8\n");
			printf("|      \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 4:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|    /8)\n");
			printf("|      \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 5:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|    /8)\n");
			printf("|    ( \n");
			printf("|	   \n");
			printf("|______\n");

		break;

		case 6:

			printf("------¬\n");
			printf("|     &\n");
			printf("|     0\n");
			printf("|    /8)\n");
			printf("|    ( )\n");
			printf("|	   \n");
			printf("|______\n");
			printf("\n\n ¡¡  L O S E R  !!\n\n");

		break;

	}
}


int ahorcado(char * palabra, char * caracter, int fallo){

	int i;
	int cont = 0;

	char palabrarray [strlen(palabra)+1];
	char caracterarray [strlen(caracter)+1];

	strcpy(palabrarray,palabra);
	strcpy(caracterarray,caracter);

	for(i= 0; i<strlen(palabra); i++){

		if(palabrarray[i] == caracterarray[0]){

			cont++;
		}
	}

	return cont;
}

void print_word(int barras, char word []){

	printf("\n");

	for(int i=0; i < barras; i++){

		printf("%c", word[i]);
	}

	printf("\n\n");

}

int main(){

	int fallo = 0;
	
	printf("JUGADOR [1]: INTRODUZCA PALABRA A ADIVINAR: ");

	palabra = leerteclado();

	int barras = strlen(palabra);

	for(int i = 0; i < 150; i++){

		printf("\n");
	}

	char word [barras];

	for(int i=0; i < barras; i++){

		word[i] = '_';

	}

	pintar_muneco(fallo);

	print_word(barras, word);


	while(fallo != 6){

		printf("JUGADOR [2]: INTRODUZCA LETRA: ");
		
		caracter = leerteclado();

		char palabrarray [strlen(palabra)+1];
		strcpy(palabrarray,palabra);

		char caracterarray [strlen(caracter)+1];
		strcpy(caracterarray,caracter);

		int acierto = ahorcado(palabra,caracter,fallo);

		if (acierto == 0){

			fallo++;
			pintar_muneco(fallo);

		}else{

			for(int i = 0; i< barras; i++){

				if(palabrarray[i] == caracterarray[0]){

					word[i] = caracterarray[0];
				}
			}

			print_word(barras, word);

			if(strcmp(palabra, word) == 0){

				printf("\n\n ¡¡  W I N N E R  !!\n\n");
				exit(0);
			}

		}

	}

	return 0;

}