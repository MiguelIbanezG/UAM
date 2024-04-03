#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CADENA 256
#define MAX_CANCIONES 100

typedef struct {
	char *titulo;
	char *artista;
	int duracion;
} Cancion;

typedef struct {
	Cancion canciones[MAX_CANCIONES];
	int numCanciones;
} Playlist;

/* El argumento playlist podría ser una variable en lugar de un puntero. En este caso utilizamos un puntero para emplear menos memoria */
int playlist_guardar(Playlist *playlist, char *nombreFichero) {
	FILE *fichero = NULL;
	int i;

	if ( !playlist || !nombreFichero ) {
		return -1;
	}

	fichero = fopen(nombreFichero, "a");

	for ( i=0; i<playlist->numCanciones; i++ ) {
		fprintf(fichero, "\n%s#%s#%d", playlist->canciones[i].titulo, playlist->canciones[i].artista, playlist->canciones[i].duracion);
	}

	fclose(fichero);

	return 0;
}

int playlist_numeroCanciones(char *nombreFichero) {
	FILE *fichero = NULL;
	char titulo[MAX_CADENA], artista[MAX_CADENA];
	int duracion, numCanciones;

	if ( !nombreFichero ) {
		return -1;
	}

	numCanciones = 0;

	fichero = fopen(nombreFichero, "r");

	while ( fscanf(fichero, "%s#%s#%d", titulo, artista, &duracion)==1 ) {
		numCanciones++;
	}
        
        /* Otra opción sería:
        while ( !feof(fichero) ) {
		fscanf(fichero, "%s#%s#%d", titulo, artista, &duracion);
		numCanciones++;
	}
        */

	fclose(fichero);

	return numCanciones;
}

int main() {
	Playlist playlist;
	char cadena[MAX_CADENA];
	int n, i;

	printf("Numero de canciones: ");
	scanf("%d", &n);

	playlist.numCanciones = 0;
	for ( i=0; i<n; i++ ) {
		printf("Titulo de la cancion %d: ", i+1);
		scanf("%s", cadena);
		playlist.canciones[i].titulo = (char *) malloc((1 + strlen(cadena)) * sizeof(char));
		strcpy(playlist.canciones[i].titulo, cadena);

		printf("Artista de la cancion %d: ", i+1);
		scanf("%s", cadena);
		playlist.canciones[i].artista = (char *) malloc((1 + strlen(cadena)) * sizeof(char));
		strcpy(playlist.canciones[i].artista, cadena);

		printf("Duracion de la cancion %d: ", i+1);
	        scanf("%d", &playlist.canciones[i].duracion);

		playlist.numCanciones++;
	}

	playlist_guardar(&playlist, "datos2.txt");

	for ( i=0; i<n; i++ ) {
		free(playlist.canciones[i].titulo);
		free(playlist.canciones[i].artista);
	}
        
        n = playlist_numeroCanciones("datos2.txt");
	printf("El fichero tiene ahora %d canciones guardadas.\n", n);

	return 0;
}n;
