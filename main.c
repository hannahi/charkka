/* 
 * File:   main.c
 * Author: hendri & hanna
 *
 * Created on September 30, 2011, 7:25 PM
 */
#include <stdio.h>
#include <stdlib.h>

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
    return (EXIT_SUCCESS);
}