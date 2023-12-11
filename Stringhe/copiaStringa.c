#include <stdio.h>
#include <string.h>

void main(){
	char s1[30], s2[30];
	
	printf("Inserire una parola: ");
	scanf("%s", s1);
	
	// s2 = s1; // errata: copia l'indirizzo
	// può dar problemi secondo il compilatore
	strcpy(s2, s1);
	
	s1[0] = "C";
	
	printf(s2);
	// se la copia è fatta correttamente
	// s2 sarà corretto altrimenti, se fatta
	// un'assegnazione, con copia dell'indirizzo,
	// la modifica ad s1 si rifletterà su s2
	
}