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

avl_puu vapauta(avl_puu puu);
avl_puu etsi(char *X, avl_puu puu);
avl_puu etsi_minimi(avl_puu puu);
avl_puu etsi_maksimi(avl_puu puu);
avl_puu lisaa(char *X, avl_puu puu);
char* tulosta(avl_puu P);



#ifdef	__cplusplus
}
#endif

#endif	/* AVL_H */

