/* 
 * File:   avl.h
 * Author: hanna
 *
 * Created on 27. lokakuuta 2011, 22:02
 */

#ifndef AVL_H
#define	AVL_H

#ifdef	__cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Solmu;
typedef struct Solmu *avl_puu;

avl_puu vapauta(avl_puu solmu);
avl_puu etsi(char *X, avl_puu solmu);
avl_puu lisaa(char *X, avl_puu solmu);
int korkeus(avl_puu solmu);
int maksimikorkeus(int Lhs, int Rhs);
avl_puu yks_rotaatio_vasen(avl_puu solmu);
avl_puu yks_rotaatio_oikea(avl_puu solmu);
avl_puu tupla_rotaatio_vasen(avl_puu solmu);
avl_puu tupla_rotaatio_oikea(avl_puu solmu);
char* tulosta(avl_puu P);
void tulostaJarjestyksessa(avl_puu T);


#ifdef	__cplusplus
}
#endif

#endif	/* AVL_H */

