/**
 * Si scriva un programma che legge due stringhe da
 * tastiera e poi scrive su schermo se sono uguali 
 * o diverse.
 */
 
 #include <stdio.h>
 // Includo la libreria con le operazioni di input/output
 #include <string.h>
 // Includo la libreria delle stringhe per le operazioni
 // su di queste (copia, comparazione, ecc.)
 
 void main() {
 	//dichiaro le variabili che conterranno le stringhe
 	char s1[30], s2[30];
 	// richiesta della prima stringa
 	printf("Inserire la prima parola: ");
	//lettura della prima stringa
	scanf("%s", s1);
	// richiesta della seconda stringa
 	printf("Inserire la seconda parola: ");
	//lettura della seconda stringa
	scanf("%s", s2); 
	//non si usa & perché la stringa è un vettore/puntatore
	
	// comparazione errata perché controlla gli indirizzi
	if (s1 == s2)
		printf("Le stringhe sono uguali\n");
	else
		printf("Le stringhe sono diverse\n");
		
	// comparazione corretta
	if (!strcmp(s1, s2)) 
	// la funzione strcmp restituisce falso se le stringhe sono vere
		printf("Scherzavo: le stringhe sono uguali\n");
	else
		printf("Casualmente era vero: le stringhe sono diverse\n");
 }