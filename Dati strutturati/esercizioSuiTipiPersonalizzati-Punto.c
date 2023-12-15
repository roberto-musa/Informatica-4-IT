/**
 * - Si scriva un programma C che definisca un tipo punto
 *   che ha come campi un nome composto da un carattere,
 *   la coordinata x e la coordinata y composte da un numero
 *   reale.
 * - Definito il tipo personalizzato "punto" si crei un vettore di
 *   3 punti, A, B e C, con coordinate A(1, 1), B(2, 3) e C (4, 5).
 * - Si chieda all'utente di inserire il nome del punto di cui
 *   si vogliono conoscere le coordinate.
 * - Si passi il vettore di punti ed il nome del punto richiesto ad 
 *   una funzione che effettui il controllo e restituisca il punto
 *   individuato.
 * - Si stampino su schermo le coordinate del punto restituito.
 */

/**
 * CONSIGLI:
 * - si usi l'istruzione typedef per definire il tipo punto
 *   usando il tipo complesso "struct" secondo le istruzioni
 *   date
 * - si definisca il tipo globalmente al fine di poterlo usare
 *   sia nel main che nella funzione
 */
 
#include <stdio.h> // Per input ed output

// definisco il tipo punto
typedef struct {
	char nome;
	float x, y;	
} punto;

// prototipi delle funzioni
punto trovaPunto (punto[], char);

// main
void main(){
	punto punti[3]; // dichiaro il vettore di 3 punti
	char chiave; // variabile per la chiave di ricerca
	punto trovato; // variabile che ospiterà il punto trovato
	
	// riempio i valori dei punti nel vettore come da richiesta
	punti[0].nome = 'A';
	punti[0].x = 1;
	punti[0].y = 1;
	
	punti[1].nome = 'B';
	punti[1].x = 2;
	punti[1].y = 3;
	
	punti[2].nome = 'C';
	punti[2].x = 4;
	punti[2].y = 5;
	
	// chiedo quale punto cercare 
	printf("Di quale punto vuoi conoscere le coordinate? ");
	// e lo memorizzo nella chiave di ricerca
	scanf("%c", &chiave);
	
	//cerco il punto richiesto e lo memorizzo in una variabile
	trovato = trovaPunto(punti, chiave);
	
	// restituisco le coordinate del punto trovato dalla funzione
	printf("Le coordinate del punto richiesto sono:\nx: %f\ny: %f", trovato.x, trovato.y);
}

// implemento la funzione
punto trovaPunto (punto elenco[3], char chiave){
	int i;	
	
	// scorro il vettore e controllo i nomi degli elementi
	for (i=0; i<3; i++){
		if (elenco[i].nome==chiave)
			return elenco[i];
			// se il nome corrisponde alla chiave restituisco il punto
	}
	/**
	 * L'istruzione return interrompe la funzione. Se
	 * l'esecuzione della funzione arriva a questo punto
	 * significa che il punto non era contenuto nel vettore.
	 */
			
	// azioni se non trovo il punto in elenco
	punto none; // dichiaro una variabile di tipo punto
	// metto dei valori per il punto nullo
	none.nome = 'O';
	none.x = 0;
	none.y = 0;
	
	return none; // restituisco il punto nullo
}