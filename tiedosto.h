/* 
 * File:   tiedosto.h
 * Author: hendri
 *
 * Created on 26. lokakuuta 2011, 15:46
 */

#ifndef TIEDOSTO_H
#define	TIEDOSTO_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* lue_tiedosto();
int hae_tiedoston_pituus(char* filename);
char* lataa_sisalto(char* filename);
int laske_sanat(char* syote);

#ifdef	__cplusplus
}
#endif

#endif	/* TIEDOSTO_H */