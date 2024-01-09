/**
 * Si scriva un programma C che 
 * 1 - definisca un tipo di dato studente composto dai campi nome e cognome 
 * di tipo stringa
 * 2 - chieda all'utente il numero di studenti da registrare
 * 3 - allochi memoria per registrare il numero di studenti ottenuto
 * 4 - con un ciclo registri nome e cognome degli studenti nel vettore creato
 * 5 - stampi su schermo il contenuto del vettore
 *
 * Libreria da utilizzare per la malloc: 
 * #include <malloc.h>
 * Esempio di utilizzo:
 * array = (int *) malloc(sizeof(int) * numero);
 */
 
#include <stdio.h> // mi serve per le operazioni di I/O
#include <malloc.h> // mi serve per allocare la memoria

// 1 - Definire il tipo studente
typedef struct {
	char nome[30], cognome[30];
} studente;

void main(){
	int nStud, i;
	studente *registro; // dichiaro un puntatore a dati di tipo studente
	
	// 2 - richiesta del numero di utenti da registrare
	printf("Quanti studenti devo registrare? ");
	scanf("%d", &nStud);
	
	// 3 - Allochiamo la memoria per il vettore di studenti
	registro = (studente *) malloc(nStud * sizeof(studente));
	// Abbiamo allocato memoria per nStud studenti
	// Un puntatore al primo elemento è di fatto un vettore
	
	// 4 - Registro nomi e cognomi
	for (i=0; i<nStud; i++) {
		printf("Inserire il nome dello studente %d: ", (i+1));
		scanf("%s", registro[i].nome);
		// registro, che punta al primo elemento di tipo studente
		// viene usato come un vettore
		// Non metto la & davanti alla variabile di tipo stringa
		// perché essendo un vettore contiene già un inidirzzo
		printf("Inserire il cognome dello studente %d: ", (i+1));
		scanf("%s", registro[i].cognome);
	}
	
	// 5 - stampa su schermo
	for (i=0; i<nStud; i++) {
		printf("Studente n.%d: %s %s\n", (i+1), registro[i].cognome, registro[i].nome);
	}
}
 