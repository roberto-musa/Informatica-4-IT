/**
 * Si raccolgano da tastiera una serie di cognomi e nomi e 
 * si memorizzino in due vettori.
 * Si chieda un nome e si visualizzino su schermo tutti i
 * cognomi associati al nome.
 */
 
 /**
  * Scomponiamo il problema in sottoproblemi:
  * 1 - Dichiaro due matrici di caratteri perché in C
  *     le stringhe sono vettori di caratteri e le matrici
  *     sono vettori di vettori;
  * 2 - Facciamo l'imput di nomi e cognomi
  * 3 - Memorizziamo nomi e cognomi nei vettori
  * 4 - Leggo il nome da cercare
  * 5 - Faccio un ciclo per controllare i nomi
  * 6 - Visualizzo a schermo i cognomi abbinati al nome
  */
 
 #include <stdio.h> // Mi serve per le operazioni di I/O
 #include <string.h> // Mi serve per la comparazione tra stringhe
 
 #define N 10 // Definisco una costante N di valore 10
 // Le costanti sono maiuscole, senza uguale e senza punto e virgola
 
 void leggiNomi(char [][31], char [][31], int);
 // Prototipo di funzione: tipoOutput nomeFunzione(tipoInput,...);
 // Prototipo di una funzione che prende in input
 // due vettori di stringhe ed il numero di stringhe
 // da leggere. La funzione memorizzerà le stringhe
 // lette nei vettori passati.
 void cercaNome(char [31], char [][31], char [][31], int);
 // Prototipo di una funzione che prende in input
 // la stringa da cercare, il vettore di stringhe 
 // in cui cercare, quello per la stampa ed il 
 // numero di stringhe contenute nei vettori.
 // La funzione stamperà i cognomi scelti.
 
 void main (){ 
 	// Quando avviamo il programma l'esecuzione parte dal main
 	// void perché non restituisce alcun valore, le parentesi
 	// sono vuote perché non passo parametri in ingresso 
	// (es.: mkdir nomeCartella)
	
	char nomi[N][31]; 
	// n è il numero di stringhe, 31 la dimensione compreso il '\0'
	char cognomi[N][31];
	// nomi e cognomi da 30 caratteri, il 31o per '\0'
	char nome[31];
	leggiNomi(nomi, cognomi, N);
	printf("Inserisci il nome da cercare: ");
	scanf("%s", nome);
	cercaNome(nome, nomi, cognomi, N);
 }
 
 void leggiNomi(char nomi[][31], char cognomi[][31], int n){
 	// Implementazione della funzione leggiNomi
 	// Qui scriviamo il codice che definisce cosa fa la funzione.
 	// Qui oltre il tipo dei dati in input mi serve il nome per
 	// riferirmi a loro nel codice.
 	int i;
 	
 	for(i=0; i<n; i++) {
 	// faccio n volte la richiesta e lettura di nomi e cognomi
 		printf("Inserire il nome: ");
 		// chiedo il nome
 		scanf("%s", nomi[i]);
 		// leggo il nome
 		printf("Inserire il cognome: ");
 		// chiedo il cognome
 		scanf("%s", cognomi[i]);
 		// leggo il cognome
	 }
 }
 
 void cercaNome(char nome[31], char nomi[][31], char cognomi[][31], int n){
 	// Faccio un ciclo per controllare i nomi
 	// Se il nome viene trovato stampo il cognome
 	// corrispondente.
 	int i;
 	for(i=0; i<n; i++){
 		if(!strcmp(nome, nomi[i]))
 			printf("%s\n", cognomi[i]);
	}
 }