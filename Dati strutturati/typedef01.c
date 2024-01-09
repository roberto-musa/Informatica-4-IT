#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[30]; // Campo del dato con etichetta nome di tipo string
	char cognome[30]; // Campo del dato con etichetta cognome di tipo string
	int eta; // Campo del dato con etichetta eta di tipo int
} studente;

typedef struct {
	char *classe; // un puntatore per la stringa
	studente alunni[15];
	studente insegnanti[3];
} studenti;


/**
 * La definizione con un nome, portata fuori dal main
 * è globale: si può usare in tutte le funzioni.
 * Se la definizione della struct fosse nel main avrebbe
 * valore solo in questo ed andrebbe ridefinita nelle
 * altre funzioni.
 */
	
void main(){
	
	studenti a4;
	int i;
	a4.classe = "4a it";
	
	for (i = 0; i<15, i++) {
		scanf("%s", a4.alunni[i].nome);
		scanf("%s", a4.alunni[i].cognome);
		scanf("%d", &a4.alunni[i].eta);
	}
	
}