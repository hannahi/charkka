/* 
 * File:   main.c
 * Author: hendri & hanna
 *
 * Created on September 30, 2011, 7:25 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include "tiedosto.h"
#include "avl.h"

int testaaPuu() {
    avl_puu T = NULL;

    T = lisaa("koira", T);
    T = lisaa("ja", T);
    T = lisaa("ja", T);
    T = lisaa("kisu", T);
    T = lisaa("aapeli", T);
    T = lisaa("kisu", T);
    T = lisaa("a", T);
    T = lisaa("koira", T);


    
    tulostaJarjestyksessa(T);

    return 0;
}

char* teksti;

/*
 * Jos ohjelma ei saa komentoriviparametrina tiedostonnimea 
 * se kysyy sita kayttajalta funktiolla lue_tied(). Muuten ohjelma lataa
 * suoraan muistiin parametrina saadun tiedostonnimen, jos tiedosto loytyy.
 */
int main(int argc, char** argv) {
    if (argc == 2)
        teksti = lataa_sisalto(argv[1]);
    else {
        teksti = lue_tiedosto();
    }
    printf("%d", laske_sanat(teksti));
    
    testaaPuu();
    return (EXIT_SUCCESS);
}
