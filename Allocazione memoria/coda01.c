#include <stdio.h>
#include <malloc.h>

typedef struct nodo { // uso il nome anche qui per usarlo all'interno
	int dato;
	struct nodo *next; // non posso ancora usare nodo ma posso usare struct nodo
} nodo;

typedef nodo *codaInt;

// protitpi delle funzioni per la coda
codaInt init();
void add(codaInt *, int);
int pull(codaInt *);
int first(codaInt);

void main(){
	codaInt miaCoda;
	int temp;
	char continua;
	
	miaCoda = init(); // inizializzo la coda
	
	do {
		printf("Inserisci un valore intero: ");
		scanf("%d", &temp);
		
		add(&miaCoda, temp); // aggiungo un elemento in coda
		
		printf("Continui? [y/n]");
		scanf(" %c", &continua);
	}while(continua!='n');
	
	while(miaCoda != NULL){
		printf("Valore estratto: %d\n", pull(&miaCoda));
	}
}

// implementazione delle funzioni per la coda

codaInt init(){
	return NULL; // restituisco null per inizializzare la coda
}

void add(codaInt *coda, int elem){
	codaInt nuovo; 	// dichiaro un puntatore al nuovo nodo
	codaInt temp;	// dichiaro un puntatore per scorrere la coda
	
	nuovo = (codaInt) malloc(sizeof(nodo)); // creo il nuovo nodo
	nuovo->dato = elem; // inserisco il valore nel nuovo nodo
	nuovo->next = NULL; // il nuovo sarà l'ultimo e punterà a NULL
	
	if (*coda == NULL) {
		*coda = nuovo; 	// se la testa della coda è NULL il nuovo
						// elemento è il primo
	}else{
		// se ho già altri elementi scorro la coda per
		// arrivare all'ultimo elemento. Parto dalla testa
		// copiandola nella variabile temp, per trovare
		// l'ultimo nodo controllo se il campo next è NULL	
		temp = *coda;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nuovo; 	// inserisco in coda il nuovo elemento
	}
}

int pull(codaInt *coda){
	if (*coda == NULL)
		return -1;
		
	codaInt garb; 	// dichiaro una variabile temporanea di appoggio in cui 
					// memorizzare l'elemento da distruggere
	int temp;		// dichiaro una variabile temporanea per memorizzare il
					// valore da restituire
	garb = *coda;	// salvo il puntatore all'elemento da distruggere	
	temp = garb->dato;	// salvo il valore dell'elemento da restituire
	*coda = garb->next; // faccio puntare la testa all'elemento successivo
	free(garb);		// distruggo l'emento puntato e libero la memoria	
	return temp; 	// restituisco il valode dell'elemento puntato da temp 
}

int first(codaInt coda){
	if (coda == NULL)
		return -1;
	else
		return coda->dato;	// restituisco il valode dell'elemento puntato da temp 
}