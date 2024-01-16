#ifndef REMBOURSER_H
#define REMBOURSER_H
#include "emprunter.h"


typedef struct Remboursement {
    long numero;
    long numero_client;
    double montant;
    char date[15];
    long empruntARembouser;
    struct Remboursement *suivant;
} Remboursement;

typedef struct {
    Remboursement *debut;
} ListeRemboursements;

void initialiserListeRemboursements(ListeRemboursements *liste);
void effectuer_remboursement(ListeRemboursements *liste, Remboursement *nouveau_remboursement);
void effectuer_remboursement_dans_fichier(Remboursement *nouvel_remboursement, Emprunt *empruntArembouser);
void afficher_remboursements(ListeRemboursements *liste);


#endif
