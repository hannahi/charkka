/* 
 * File:   tiedosto.c
 * Author: hendri
 *
 * Created on October 26, 2011, 3:29 PM
 * 
 * Lahdekooditiedosto sisaltaa tiedostojen lukemiseen kiintolevylta tarvittavan 
 * toiminnallisuuden.
 * 
 */

#include "tiedosto.h"

/*
 * Funktio pyytaa kayttajalta tiedostonnimea ja sen jalkeen palauttaa
 * load_data() funktion tuottaman tekstiesityksen kyseisesta tiedostosta.
 */
char* lue_tiedosto() {
    char* filename = malloc(81);
    printf("\nAnna luettavan tiedoston nimi: ");
    scanf("%s", filename);
    return lataa_sisalto(filename);
}

/*
 * Funktio avaa tiedosto-osoittimen parametrina saadusta tiedostonnimesta.
 * Jos se onnistuu funktio lukee tiedoston sisallon dynaamisesti varatulle
 * muistialueelle. Muistia varataan tarkalleen tiedoston sisaltaman tekstin 
 * vaatima tila laskemalla tiedoston pituus. Jos tiedostoa ei loydy tai muistia
 * ei saada varattua esitetaan virheilmoitus.
 */
char* lataa_sisalto(char* filename) {
    FILE *fptr;
    int index = 0, ch;
    if ((fptr = fopen(filename, "r")) == NULL) {
        printf("\nTiedostoa %s ei loytynyt! LOPETETAAN\n", filename);
    }
    char *contents = malloc(hae_tiedoston_pituus(filename));
    if (contents == NULL) {
        printf("\nMemory allocation failed at load_data()\n");
        return NULL;
    }
    while ((ch = getc(fptr)) != EOF) {
        contents[index] = ch;
        index++;
    }
    fclose(fptr);
    return contents;
}

/*
 * Funktio laskee parametrina saadun tiedostonnimen osoittaman 
 * tiedoston pituuden tavuina. Jos tiedostoa ei loydy esitetaan virheilmoitus.
 */
int hae_tiedoston_pituus(char* filename) {
    FILE* fptr;
    if ((fptr = fopen(filename, "rb")) == NULL) {
        printf("\nTiedostoa %s ei loytynyt! LOPETETAAN\n", filename);
    }
    fseek(fptr, 0, SEEK_END);
    int size = ftell(fptr);
    fclose(fptr);
    return size;
}

int laske_sanat(char* syote) {
    int sanat = 0, i = 0;
    char *ptr, *words;
    char delim[] = {' ', '.', ',', '!', '?', ';', ':'};
    while (words[i] != '\0') {
        if ((words[i] == delim[0]) || (words[i] == delim[1]))
            sanat++;
        i++;
    }
}