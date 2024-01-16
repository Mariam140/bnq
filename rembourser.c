#include  "rembourser.h"
#include  "emprunter.h"
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

void initialiserListeRemboursements(ListeRemboursements *liste) {
    liste->debut = NULL;
}
void effectuer_remboursement(ListeRemboursements *liste, Remboursement *nouveau_remboursement) {
    nouveau_remboursement->suivant = liste->debut;
    liste->debut = nouveau_remboursement;
}


void effectuer_remboursement_dans_fichier(Remboursement *nouvel_remboursement, Emprunt *empruntArembouser) {
    FILE *fichier;
    fichier = fopen("remboursement.txt", "a");
    if (fichier != NULL) {
        int result = fprintf(fichier, "%ld %ld %s %c %s %s %s\n",
                              nouvel_remboursement->numero,
                              empruntArembouser->numero_client,
                              nouvel_remboursement->montant,
                              nouvel_remboursement->date,
                              nouvel_remboursement->suivant);

        fclose(fichier);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void afficher_remboursements(ListeRemboursements *liste) {
    Remboursement *courant = liste->debut;

    while (courant != NULL) {
        printf("Num�ro: %ld, Montant: %.2f, Date: %s\n",
               courant->numero, courant->montant, courant->date);
        courant = courant->suivant;
    }
}

