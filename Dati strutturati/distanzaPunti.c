/**
 * - Si parta dal tipo punto definito nella precedente
 *   esercitazione.
 * - Si crei una funzione calcola distanza che prenda in
 *   input due punti e restituisca un valore reale (float)
 * - Si leggano da tastiera nome e coordinate dei due punti
 *   e si scriva su schermo la distanza tra i due.
 */

#include <stdio.h> // Per input ed output
#include <math.h> // Per le funzioni matematiche

// definisco il tipo punto
typedef struct {
	char nome;
	float x, y;	
} punto;

float calcolaDistanza(punto, punto);

void main(){
	punto punti[2];
	int i;
	
	/**
	 * Per lasciare il ciclo dipendente dalla dimensione del
	 * vettore senza vincoilarlo a fare un numero di cicli
	 * predeterminato ho usato la funzione sizeof().
	 * sizeof() restituisce la dimensione di variabili e di
	 * tipi di dato per cui, dividendo la dimensione di un
	 * vettore di punti per la dimensione del tipo di dato
	 * punto, ottengo che il vettore contiene 2 elementi.
	 */
	for (i=0; i<(sizeof(punti)/sizeof(punto)); i++){
		printf("Inserire il nome del punto: ");
		scanf(" %c", &punti[i].nome);
		/**
		 * lo spazio prima del placeholder serve ad ignorare
		 * il carattere di newline (\n) rimasto in memoria
		 * dalla fine del ciclo precedente. Senza, al secondo
		 * ciclo, salta la lettura del nome. Ignora anche i
		 * caratteri di whitespace (spazi).
		 */
		printf("Inserire la coordinata x del punto: ");
		scanf("%f", &punti[i].x);
		printf("Inserire la coordinata y del punto: ");
		scanf("%f", &punti[i].y);
	}
	
	printf("La distanza tra il punto %c ed il punto %c risulta di %f", punti[0].nome, punti[1].nome, calcolaDistanza(punti[0], punti[1]));
	// Dentro la printf richiamo la funzione calcolaDistanza()
	// che mi restituisce la distanza tra i due punti.
}

float calcolaDistanza(punto a, punto b){
	float c1, c2;
	c1 = a.x - b.x; 
	// Calcolo la proiezione della distanza sull'asse x
	c2 = a.y - b.y;
	// Calcolo la proiezione della distanza sull'asse y
	
	return (sqrt(pow(c1,2)+pow(c2,2)));
	// restituisco la radice quadrata della somma dei quadrati
	// costruiti sui cateti di un ipotetico triangolo rettangolo
	// i cui cateti sono la proiezione delle distanze sugli assi.
	// L'ipotenusa così ottenuta (Teorema di Pitagora) sarà la
	// distanza tra i due punti
}