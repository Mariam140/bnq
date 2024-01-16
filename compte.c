#include "compte.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void initialiserListeComptes(ListeComptes *liste) {
    liste->debut = NULL;
}
void afficher_comptes(ListeComptes *liste){
    Compte *actuel =liste->debut;
    while(actuel!=NULL){
    printf("Numeros : %ld type : %d numero_client : %ld solde : %s  etat : %c  \n",
        actuel->numero,
        actuel->type,
        actuel->numero_client,
        actuel->solde,
        actuel->etat,
        actuel=actuel->suivant );
    }
}

void afficher_compte(Compte nouveauCompte){
    char type[20] ="EPARGNE";
    char etat [20]="LIBRE";
    if (nouveauCompte.type == 1){
        strcpy(type,"COURANT");
    }
    if (nouveauCompte.etat == 1)
    {
        strcpy(etat ,"BLOQUER");
    }

    printf("Numeros : %ld type : %s numero_client : %ld solde : %f  etat : %s  \n",
        nouveauCompte.numero,
        type,
        nouveauCompte.numero_client,
        nouveauCompte.solde,
        etat);
}

void enregistrer_compte(ListeComptes *liste, Compte *nouveau_compte) {
    nouveau_compte->suivant = liste->debut;
    liste->debut = nouveau_compte;
}
void enregistrer_compte_dans_fichier(Compte *nouveauCompte) {
    FILE *fichier;
    fichier = fopen("compte.txt", "a");
    if(fichier != NULL){
        char type[20] ="EPARGNE";
        char etat [20]="LIBRE";
        if (nouveauCompte->type == 1){
            strcpy(type,"COURANT");
        }
        if (nouveauCompte->etat == 1)
        {
            strcpy(etat ,"BLOQUER");
        }
        int result = fprintf(fichier, "%ld %s %ld %f %s \n",
                            nouveauCompte->numero,
                            type,
                            nouveauCompte->numero_client,
                            nouveauCompte->solde,
                            etat);
        if (result < 0) {
            printf("Erreur lors de l'�criture dans le fichier.\n");
        } else {
            fclose(fichier);
            printf("Le compte a �t� enregistr� avec succ�s.\n");
        }
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}
    void charger_compte_depuis_fichier(ListeComptes *liste, const char *nom_fichier) {
    FILE *file = fopen(nom_fichier, "r");
    if (file != NULL) {
        Compte nouveauCompte;
        while (fscanf(file, "%ld %d %ld %lf %d",
                      &nouveauCompte.numero,
                      &nouveauCompte.type,
                      &nouveauCompte.numero_client,
                      &nouveauCompte.solde,
                      &nouveauCompte.etat) == 5) {
            enregistrer_compte(liste, &nouveauCompte);
        }
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void debloquer_compte(ListeComptes *liste, long numero) {
    Compte *courant = liste->debut;

    while (courant != NULL) {
        if (courant->numero == numero) {
            if (courant->etat == 1) {
                printf("BLOQUER");

                courant->etat = 0;
                printf("Compte %ld debloque avec succes.\n", numero);
            } else {
                printf("Le compte %ld n'est pas bloque.\n", numero);
            }
            return;
        }
        courant = courant->suivant;
    }

    printf("Aucun compte trouve avec le numero %ld\n", numero);
}
