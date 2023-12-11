/**
 * nome file: sommaPunt.c
 * Si leggano due valori interi da tastiera. (Nel main)
 * Si scriva una funzione che prenda in input 3 variabili di tipo
 * intero e memorizzi nella terza la somma delle prime due.
 * Si stampi il valore della terza variabile. (Nel main)
 */
 
#include <stdio.h>
 
// scrivo il prototipo della funzione
void somma(int, int, int*);
// il terzo valore sarà un puntatore perché le funzioni
// copiano i valori passati ma un indirizzo copiato
// punta alla stessa zona in memoria della copia originale
 
void main(){
 	int n1, n2, n3; //dichiaro le variabili necessarie
 	
 	// lettura dei valori da sommare
 	printf("Inserire il primo valore da sommare: ");
 	scanf("%d", &n1);
 	
 	printf("Inserire il secondo valore da sommare: ");
 	scanf("%d", &n2);
 	
 	// richiamo la funzione dichiarata
 	somma(n1, n2, &n3); // & serve ad ottenere il puntatore
 	// se non usassi il puntatore il risultato sarebbe in
 	// una copia di n3 e non potrei usarlo nel main
 	
 	// stampa del valore contenente la somma
 	printf("Somma dei valori inseriti: %d", n3);
}

// implementazione della funzione
void somma(int n1, int n2, int *n3){
	// a differenza del prototipo qui do un nome ai
	// parametri per riferirmi a loro nel codice
	
	*n3 = n1 + n2;
	// per usare la variabile puntata e non il suo
	// puntatore lascio il simbolo * davanti al nome
	// della variabile.

}
