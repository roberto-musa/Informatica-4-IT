#include <stdio.h>
#include <string.h>

struct studente { // se aggiungo un nome dopo struct posso riusare il tipo
	char nome[30]; // Campo del dato con etichetta nome di tipo string
	char cognome[30]; // Campo del dato con etichetta cognome di tipo string
	int eta; // Campo del dato con etichetta eta di tipo int
};

/**
 * La definizione con un nome, portata fuori dal main
 * è globale: si può usare in tutte le funzioni.
 * Se la definizione della struct fosse nel main avrebbe
 * valore solo in questo ed andrebbe ridefinita nelle
 * altre funzioni.
 */
	
void main(){
	
	struct studente st1, st2;
	
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
	
	struct studente st3; 
	// avendo dato un nome alla struct la riuso senza ridefinirla
	
	strcpy(st3.nome, "Ennio");
	strcpy(st3.cognome, "Porrino");
	st3.eta = 19;
	
	if (st2.eta > st1.eta)
		printf("%s ha un numero di anni maggiore di %s\n", st2.cognome, st1.cognome);
	else
		printf("%s non ha un numero di anni maggiore %s\n", st2.cognome, st1.cognome);
		
	if (st2.eta > st3.eta)
		printf("%s ha un numero di anni maggiore di %s\n", st2.cognome, st3.cognome);
	else
		printf("%s non ha un numero di anni maggiore %s\n", st2.cognome, st3.cognome);
}