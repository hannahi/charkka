/* 
 * File:   main.c
 * Author: hendri & hanna
 *
 * Created on September 30, 2011, 7:25 PM
 */

#include "avl.h"

typedef struct Solmu {
    char *sana;
    avl_puu vasen;
    avl_puu oikea;
    int korkeus;
    int lkm;
} solmu;

avl_puu vapauta(avl_puu T) {
    if (T != NULL) {
        vapauta(T->vasen);
        vapauta(T->oikea);
        free(T);
    }
    return NULL;
}

avl_puu etsi(char *x, avl_puu T) {
    if (T == NULL) {
        return NULL;
    }
    if (strcmp(x, T->sana) < 0) {
        return etsi(x, T->vasen);
    } else {
        if (strcmp(x, T->sana) > 0) {
            return etsi(x, T->oikea);
        } else {
            return T;
        }
    }
}

avl_puu etsi_minimi(avl_puu T) {
    if (T == NULL) {
        return NULL;
    } else {
        if (T->vasen == NULL) {
            return T;
        } else {
            return etsi_minimi(T->vasen);
        }
    }
}

avl_puu etsi_maksimi(avl_puu T) {
    if (T != NULL)
        while (T->oikea != NULL)
            T = T->oikea;

    return T;
}

static int korkeus(avl_puu P) {
    if (P == NULL)
        return -1;
    else
        return P->korkeus;
}

static int maksimikorkeus(int Lhs, int Rhs) {
    return Lhs > Rhs ? Lhs : Rhs;
}


/* This function can be called only if K2 has a left child */
/* Perform a rotate between a node (K2) and its left child */

/* Update heights, then return new root */

static avl_puu yks_rotaatio_vasen(avl_puu K2) {
    avl_puu K1;

    K1 = K2->vasen;
    K2->vasen = K1->oikea;
    K1->oikea = K2;

    K2->korkeus = maksimikorkeus(korkeus(K2->vasen), korkeus(K2->oikea)) + 1;
    K1->korkeus = maksimikorkeus(korkeus(K1->vasen), K2->korkeus) + 1;

    return K1; /* New root */
}


/* This function can be called only if K1 has a right child */
/* Perform a rotate between a node (K1) and its right child */

/* Update heights, then return new root */

static avl_puu yks_rotaatio_oikea(avl_puu K1) {
    avl_puu K2;

    K2 = K1->oikea;
    K1->oikea = K2->vasen;
    K2->vasen = K1;

    K1->korkeus = maksimikorkeus(korkeus(K1->vasen), korkeus(K1->oikea)) + 1;
    K2->korkeus = maksimikorkeus(korkeus(K2->oikea), K1->korkeus) + 1;

    return K2; /* New root */
}


/* This function can be called only if K3 has a left */
/* child and K3's left child has a right child */
/* Do the left-right double rotation */

/* Update heights, then return new root */

static avl_puu tupla_rotaatio_vasen(avl_puu K3) {
    /* Rotate between K1 and K2 */
    K3->vasen = yks_rotaatio_oikea(K3->vasen);

    /* Rotate between K3 and K2 */
    return yks_rotaatio_vasen(K3);
}


/* This function can be called only if K1 has a right */
/* child and K1's right child has a left child */
/* Do the right-left double rotation */

/* Update heights, then return new root */

static avl_puu tupla_rotaatio_oikea(avl_puu K1) {
    /* Rotate between K3 and K2 */
    K1->oikea = yks_rotaatio_vasen(K1->oikea);

    /* Rotate between K1 and K2 */
    return yks_rotaatio_oikea(K1);
}

avl_puu lisaa(char *x, avl_puu T) {
    solmu *etsitty;

    if (T == NULL) {
        /* Create and return a one-node tree */
        T = malloc(sizeof (solmu));
        if (T == NULL) {
            printf("Muistinvaraus ei onnistunut!");
        } else {
            T->sana = x;
            T->korkeus = 0;
            T->vasen = T->oikea = NULL;
            T->lkm = 1;
        }
    } else {
        if ((etsitty = etsi(x, T)) != NULL) {
            ++etsitty->lkm;
        } else {
            if (strcmp(x, T->sana) < 0) {
                T->vasen = lisaa(x, T->vasen);
                if (korkeus(T->vasen) - korkeus(T->oikea) == 2) {
                    if (strcmp(x, T->vasen->sana) < 0) {
                        T = yks_rotaatio_vasen(T);
                    } else {
                        T = tupla_rotaatio_vasen(T);
                    }
                }
            } else {
                if (strcmp(x, T->sana) > 0) {
                    T->oikea = lisaa(x, T->oikea);
                    if (korkeus(T->oikea) - korkeus(T->vasen) == 2) {
                        if (strcmp(x, T->vasen->sana) > 0) {
                            T = yks_rotaatio_oikea(T);
                        } else {
                            T = tupla_rotaatio_oikea(T);
                        }
                    }
                }
            }
        }
    }
    T->korkeus = maksimikorkeus(korkeus(T->vasen), korkeus(T->oikea)) + 1;
    return T;
}

char* tulosta(avl_puu T) {
    return T->sana;
}

void tulostaJarjestyksessa(avl_puu T) {
         if (T == NULL) {
            return;
        }
        tulostaJarjestyksessa(T->vasen);
        printf("sana: %s\n", T->sana);
        tulostaJarjestyksessa(T->oikea);
}

int main() {
    avl_puu T = NULL;

    T = lisaa("koira", T);
    T = lisaa("ja", T);
    T = lisaa("ja", T);
    T = lisaa("kisu", T);
    T = lisaa("aapeli", T);
    T = lisaa("kisu", T);
    T = lisaa("a", T);
    T = lisaa("koira", T);


    printf("min: %s, lkm %d \n", tulosta(etsi_minimi(T)), etsi_minimi(T)->lkm);
    printf("keski: %s, lkm %d \n", tulosta(T), T->lkm);
    printf("max: %s, lkm %d \n", tulosta(etsi_maksimi(T)), etsi_maksimi(T)->lkm);
    
    tulostaJarjestyksessa(T);

    return 0;
}
