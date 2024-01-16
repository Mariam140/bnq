#ifndef COMPTE_H
#define COMPTE_H

/*typedef enum { EPARGNE, COURANT } TypeCompte;
typedef enum { LIBRE, BLOQUE } EtatCompte;*/

typedef struct Compte {
    long numero;
    int type;
    long numero_client;
    float solde;
    int etat;
    struct Compte *suivant;
} Compte;

typedef struct {
    Compte *debut;
} ListeComptes;

void initialiserListeComptes(ListeComptes *liste);
void enregistrer_compte(ListeComptes *liste, Compte *nouveau_compte);
void enregistrer_compte_dans_fichier(Compte *nouveauCompte);
void charger_compte_depuis_fichier(ListeComptes *liste, const char *nom_fichier) ;
void afficher_compte(Compte nouveauCompte);
void afficher_comptes(ListeComptes *liste);
void debloquer_compte(ListeComptes *liste, long numero);

#endif
