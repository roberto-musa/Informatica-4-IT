/**
 * Si realizzi una pila di stringhe di una parola (max 29 car)
 * ricordando che è necessario creare i tipi predefiniti per il
 * nodo, composto da valore (la stringa letta) e puntatore al
 * nodo successivo e la pila, costituita dal puntatore al nodo
 * in testa.
 * Si leggano parole chiedendo all'utente se continuare o meno
 * e, quando l'inserimento termina, stampare il contenuto della
 * pila verificando l'inserimento con logica di tipo L.I.F.O.
 */
 
#include <stdio.h> // libreria per le funzioni di input/output
#include <malloc.h> // libreria per usare la funzione malloc()
#include <string.h> // libreria per usare la funzione strcpy()

typedef struct nodo { // uso il nome anche qui per usarlo all'interno
	char dato[30]; 	// Il dato incapsulato permette di creare stringhe
					// di 29 caratteri e terminarle col carattere '\0'
	struct nodo *next; // non posso ancora usare nodo ma posso usare struct nodo
} nodo;

typedef nodo *pilaStr; // La pila è il puntatore al nodo in testa

// protitpi delle funzioni per la pila e le sue varianti
pilaStr init();
void push(pilaStr *, char[30]);
void pop(pilaStr *, char[30]);
void top(pilaStr, char[30]);
char *pop1(pilaStr *);
char *top1(pilaStr);

void main(){
	pilaStr miaPila; // dichiaro una pila
	char temp[30]; // dichiaro la variabile per leggere la parola
	char continua; // dichiaro la variabile per gestire l'inserimento
	
	miaPila = init(); // inizializzo la pila
	
	do {
		printf("Inserisci una parola max di 29 caratteri: ");
		scanf("%s", temp);
		
		push(&miaPila, temp); // aggiungo un elemento in testa
		
		printf("Continui? [y/n]");
		scanf(" %c", &continua); 
		// lo spazio prima del placeholder impedisce che il carattere
		// '\n' dell'inserimento precedente sia letto come risposta
	}while(continua!='n'); 
	// continua in maniera indefinita fino a che l'utente dice di no
	
	while(miaPila != NULL){
		printf("Valore in testa prima dell'estrazione': %s\n", top1(miaPila));
		// chiamo top1 per testare l'altra variante senza modificare la pila
		pop(&miaPila, temp);
		// alla pop passo il puntatore alla pila, in quanto la modifica,
		// e la stringa, che è già un puntatore essendo un vettore.
		printf("Valore estratto: %s\n", temp);
	}
}

// implementazione delle funzioni per la pila

pilaStr init(){
	return NULL; // restituisco null per inizializzare la pila
}


// nella fase di implementazione i parametri hanno anche un nome
void push(pilaStr *pila, char elem[30]){
	int i;	// dichiaro un intero da usare per i cicli for
	pilaStr nuovo; // dichiaro un puntatore al nuovo nodo
	nuovo = (pilaStr) malloc(sizeof(nodo)); // creo il nuovo nodo
	/**
	 * Copiamo i caratteri della stringa uno alla volta
	 * fino al \0 perché dev-C++ non vedeva il parametro
	 * passato come una stringa nonostante il '\0'.
	 */
	for(i=0; i<30; i++) {
		nuovo->dato[i]=elem[i];
		if (nuovo->dato[i]=='\0') break;
		// quando trovo il carattere di fine stringa esco dal ciclo
	}
	/**
	 * Una volta fatta la copia per carattere dev-C++ ha
	 * ripreso a vedere il dato incapsulato come una stringa
	 */
	nuovo->next = *pila; // accodo al nuovo elemento la pila attuale
	*pila = nuovo; 	// faccio puntare la testa della pila al nuovo elemento
}

/**
 * Versione non funzionante per lo scope della stringa.
 * Il puntatore restituito punta ad una variabile dichiarata
 * dentro la funzione che va a morire con la sua conclusione.
 */

/*
char* pop(pilaStr *pila){
	int i;
	if (*pila == NULL)
		return "Pila vuota";
		
	pilaStr garb; 	// dichiaro una variabile temporanea di appoggio in cui 
					// memorizzare l'elemento da distruggere
	char temp[30];	// dichiaro una variabile temporanea per memorizzare il
					// valore da restituire
	garb = *pila;	// salvo il puntatore all'elemento da distruggere	
	
	for(i=0; i<30; i++) {
		temp[i] = garb->dato[i];
		if (garb->dato[i]=='\0') break;
	}
	*pila = garb->next; // faccio puntare la testa all'elemento successivo
	free(garb);		// distruggo l'emento puntato e libero la memoria	
	return temp; 	// restituisco il valode dell'elemento puntato da temp 
}
*/

/**
 * In questa versione della pop() passo come parametro la stringa in cui
 * salvare il dato estratto ovviando al problema dello scope incontrato
 * con la versione base.
 */
void pop(pilaStr *pila, char temp[30]){
	int i;
	if (*pila == NULL)
		for(i=0; i<strlen("Pila vuota"); i++) {		
			temp[i] = ("Pila vuota")[i];
			if (("Pila vuota")[i]=='\0') break;		
		}
		
	pilaStr garb; 	// dichiaro una variabile temporanea di appoggio in cui 
					// memorizzare l'elemento da distruggere
					
	garb = *pila;	// salvo il puntatore all'elemento da distruggere	
	*pila = garb->next; // Sposto la testa della pila all'elemento successivo
	
	/**
	 * Copiamo i caratteri della stringa uno alla volta
	 * fino al \0 perché dev-C++ non vedeva il parametro
	 * passato come una stringa nonostante il '\0'.
	 */
	for(i=0; i<30; i++) {		
		temp[i] = garb->dato[i];
		if (garb->dato[i]=='\0') break;		
	}
	/**
	 * Una volta fatta la copia per carattere dev-C++ ha
	 * ripreso a vedere il dato estratto come una stringa
	 */
	
	free(garb);		// distruggo l'emento puntato e libero la memoria		
}

void top(pilaStr pila, char temp[30]){
	int i;
	if (pila == NULL)
		for(i=0; i<strlen("Pila vuota"); i++) {		
			temp[i] = ("Pila vuota")[i];
			if (("Pila vuota")[i]=='\0') break;		
		}
	else
		for(i=0; i<30; i++) {			
			temp[i] = pila->dato[i];
			if (pila->dato[i]=='\0') break;
			
		}
}

/**
 * Di seguito le versioni classiche con l'opportuna modifica
 * per funzionare:
 * se avete fatto caso, i nodi che allocavamo all'interno delle
 * funzioni push() restavano in vita al termine della funzione
 * perché moriva solo il puntatore dichiarato internamente ma
 * il suo valore veniva copiato nella testa alla pila. Lo spazio
 * allocato restava tale e pertanto, allocando dinamicamente la
 * stringa, il puntatore a questa muore ma la stringa resta e
 * si può restituirne l'indirizzo.
 */
 
char* pop1(pilaStr *pila){
	int i;		// dichiaro un intero per usarlo nei cicli for
	char *temp;	// dichiaro un puntatore per allocare spazio per una stringa
				// lo spazio così allocato non muore con la funzione e posso
				// restituire una stringa valida
	pilaStr garb; 	// dichiaro una variabile temporanea di appoggio in cui 
					// memorizzare l'elemento da distruggere
	
	if (*pila == NULL){
		temp = (char *)malloc(sizeof(char)*strlen("Pila vuota"));
		// alloco spazio per la stringa "Pila vuota"
		for(i=0; i<strlen("Pila vuota"); i++) {		
			temp[i] = ("Pila vuota")[i];
			if (("Pila vuota")[i]=='\0') break;		
		}
		return temp;
	}
		
	
	garb = *pila;	// salvo il puntatore all'elemento da distruggere	
	*pila = garb->next; // Sposto la testa della pila all'elemento successivo
	temp = (char *)malloc(sizeof(char)*strlen(garb->dato));
	// alloco lo spazio necessario a contenere la stringa incapsulata dal nodo
	// estratto dalla testa della pila
	
	/**
	 * Copiamo i caratteri della stringa uno alla volta
	 * fino al \0 perché dev-C++ non vedeva il parametro
	 * passato come una stringa nonostante il '\0'.
	 */
	for(i=0; i<30; i++) {		
		temp[i] = garb->dato[i];
		if (garb->dato[i]=='\0') break;		
	}
	
	free(garb);		// distruggo l'emento puntato e libero la memoria
	return temp;		
}

char *top1(pilaStr pila){
	int i;
	char *temp;
	if (pila == NULL){
		temp = (char *)malloc(sizeof(char)*strlen("Pila vuota"));
		// alloco spazio per la stringa "Pila vuota"
		for(i=0; i<strlen("Pila vuota"); i++) {		
			temp[i] = ("Pila vuota")[i];
			if (("Pila vuota")[i]=='\0') break;		
		}
		return temp;
	} else {
		temp = (char *)malloc(sizeof(char)*strlen(pila->dato));
		for(i=0; i<30; i++) {		
			temp[i] = pila->dato[i];
			if (pila->dato[i]=='\0') break;		
		}
		return temp;
	}
}