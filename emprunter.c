#include "emprunter.h"
#include <stdio.h>
#include <stdlib.h>

void initialiserListeEmprunts(ListeEmprunts *liste) {
    liste->debut = NULL;
}
void solliciter_emprunt(ListeEmprunts *liste, Emprunt *nouvel_emprunt) {
    nouvel_emprunt->suivant = liste->debut;
    liste->debut = nouvel_emprunt;
}

void enregistrer_emprunt(Emprunt *nouvel_emprunt){
        FILE *fichier;
        fichier =fopen("emprunt.txt", "a");
        if(fichier != NULL){
        int result = fprintf(fichier, "%ld %s %s %c %s %s %s\n",
                            nouvel_emprunt->numero_client,
                            nouvel_emprunt->type,
                            nouvel_emprunt->raison,
                            nouvel_emprunt->montant,
                            nouvel_emprunt->date_limite,
                            nouvel_emprunt->date_premier_remboursement);

        if (result < 0) {
            printf("Erreur lors de l'ecriture dans le fichier.\n");
        } else {
            fclose(fichier);
            printf("Le compte a ete enregistre avec succes.\n");
        }


}
else{
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
        }

void afficher_emprunts(ListeEmprunts *liste) {
    Emprunt *courant = liste->debut;

    while (courant != NULL) {
        printf("Num�ro: %ld, Type: %d, Montant: %.2f, Statut: %d\n",
               courant->numero, courant->type, courant->montant, courant->statut);
        courant = courant->suivant;
    }
}
Emprunt *rechercher_emprunt(ListeEmprunts *liste, long numero) {
    Emprunt *courant = liste->debut;

    while (courant != NULL) {
        if (courant->numero == numero) {
            return courant;
        }
        courant = courant->suivant;
    }

    return NULL;
}

