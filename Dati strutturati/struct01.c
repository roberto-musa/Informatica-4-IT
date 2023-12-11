#include <stdio.h>
#include <string.h>
	
void main(){
	
	struct {
		char nome[30]; // Campo del dato con etichetta nome di tipo string
		char cognome[30]; // Campo del dato con etichetta cognome di tipo string
		int eta; // Campo del dato con etichetta eta di tipo int
	} st1, st2;
	
	/**
	 * Le struct sono un tipo di dato strutturato definito
	 * da campi, accessibili col simbolo ".", che possono
	 * essere di tipo uguale o diverso.
	 */
	
	strcpy(st1.nome, "Mario");
	// Salvo la stringa Mario nel campo nome della variabile st1
	strcpy(st1.cognome, "Rossi");
	// Salvo la stringa Rossi nel campo cognome della variabile st1
	st1.eta = 16;
	
	strcpy(st2.nome, "Giuseppe");
	strcpy(st2.cognome, "Verdi");
	st2.eta = 18;
	
	if (st2.eta > st1.eta)
		printf("%s ha un numero di anni maggiore di %s", st2.cognome, st1.cognome);
	else
		printf("%s non ha un numero di anni maggiore %s", st2.cognome, st1.cognome);
}