#include <stdio.h>
#include <string.h>

void main(){
	// dichiarazione delle variabili necessarie
	char mat[10][11] = {"abbfilmpru", "caioniaiin", "ctbtfntasi", "otlolgenpv", "geiguumoee", "lroreaaftr", "iitangtots", "esefcgiraa", "rtcieictrl", "eaaaroaeee"};
	char col[10][11]; // Matrice di caratteri in cui memorizzare le stringhe corrispondenti alle colonne della matrice data
	char s1[11]; // s1 conterrà la stringa letta da tastiera
	int i, j, found = 0; // i e j mi serviranno per i cicli, found per la condizione finale (stringa trovata o non trovata)
	
	// stampo a schermo la matrice
	printf("In questa matrice la stringa inserita viene cercata per riga: \n");
	for (i = 0; i < 10; i++)
		printf("%d:\t%s \n", i+1, mat[i]);
	
	// ciclo di inversione della matrice
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++)
			col[i][j] = mat[j][i]; // le colonne di mat diventano le righe di col
		col[i][10]='\0'; //aggiungo il carattere di fine stringa
	}
	
	// stampo la matrice invertita
	printf("Questa matrice invertita serve per cercare la stringa per colonna: \n");
	for (i = 0; i < 10; i++)
		printf("%d:\t%s \n", i+1, col[i]);
	
	// chiedo l'inserimento della stringa e la leggo	
	printf("Inserire una stringa di 10 caratteri: \n");
	scanf("%s", s1);
	
	// controllo se s1 è presente nelle varie righe della matrice
	for (int i = 0; i<10; i++)
		if(!strcmp(mat[i], s1)) { // controllo la corrispondenza di s1 alla riga i
			printf("La stringa si trova alla riga %d\n", i+1);
			found = 1; //se trovata imposto found ad 1
		}
	
	// controllo se s1 è presente nelle varie colonne della matrice originale usando le righe di quella invertita
	for (int i = 0; i<10; i++)
		if(!strcmp(col[i], s1)){ // controllo la corrispondenza di s1 alla riga i do col corrispondente alla colonna i di mat
			printf("La stringa si trova alla colonna %d\n", i+1);
			found = 1; //se trovata imposto found ad 1
		}
	
	// controllo se la stringa non è stata trovata (i booleani in C sono interi: 0 è falso, 1 è vero
	if (!found)
		printf("La matrice non contiene la stringa inserita\n"); // Comunico che la stringa non è stata trovata
}