#include <stdio.h>
#include <malloc.h>

typedef struct nodo { // uso il nome anche qui per usarlo all'interno
	int dato;
	struct nodo *next; // non posso ancora usare nodo ma posso usare struct nodo
} nodo;

typedef nodo *pilaInt;

// protitpi delle funzioni per la pila
pilaInt init();
void push(pilaInt *, int);
int pop(pilaInt *);
int top(pilaInt);

void main(){
	pilaInt miaPila;
	int temp;
	char continua;
	
	miaPila = init(); // inizializzo la pila
	
	do {
		printf("Inserisci un valore intero: ");
		scanf("%d", &temp);
		
		push(&miaPila, temp); // aggiungo un elemento in testa
		
		printf("Continui? [y/n]");
		scanf(" %c", &continua);
	}while(continua!='n');
	
	while(miaPila != NULL){
		printf("Valore estratto: %d\n", pop(&miaPila));
	}
}

// implementazione delle funzioni per la pila

pilaInt init(){
	return NULL; // restituisco null per inizializzare la pila
}

void push(pilaInt *pila, int elem){
	pilaInt nuovo; // dichiaro un puntatore al nuovo nodo
	nuovo = (pilaInt) malloc(sizeof(nodo)); // creo il nuovo nodo
	nuovo->dato = elem; // inserisco il valore nel nuovo nodo
	nuovo->next = *pila; // accodo al nuovo elemento la pila attuale
	*pila = nuovo; 	// faccio puntare la testa della pila al nuovo elemento
}

int pop(pilaInt *pila){
	if (*pila == NULL)
		return -1;
		
	pilaInt garb; 	// dichiaro una variabile temporanea di appoggio in cui 
					// memorizzare l'elemento da distruggere
	int temp;		// dichiaro una variabile temporanea per memorizzare il
					// valore da restituire
	garb = *pila;	// salvo il puntatore all'elemento da distruggere	
	temp = garb->dato;	// salvo il valore dell'elemento da restituire
	*pila = garb->next; // faccio puntare la testa all'elemento successivo
	free(garb);		// distruggo l'emento puntato e libero la memoria	
	return temp; 	// restituisco il valode dell'elemento puntato da temp 
}

int top(pilaInt pila){
	if (pila == NULL)
		return -1;
	else
		return pila->dato;	// restituisco il valode dell'elemento puntato da temp 
}