
    #ifndef EMPRUNTER_H
    #define EMPRUNTER_H

   /* typedef enum { PRET_SCOLAIRE, PRET_INVESTISSEMENT, PRET_IMMOBILIER } TypeEmprunt;
    typedef enum { EN_COURS, SOLDE } StatutEmprunt;*/

    typedef struct Emprunt {
        long numero;
        char type;
        long numero_client;
        char raison[100];
        double montant;
        char date_limite[15];
        char date_premier_remboursement[15];
        char statut;
        struct Emprunt *suivant;
    } Emprunt;

    typedef struct {
        Emprunt *debut;
    } ListeEmprunts;

    void initialiserListeEmprunts(ListeEmprunts *liste);
    void solliciter_emprunt(ListeEmprunts *liste, Emprunt *nouvel_emprunt);
void charger_emprunt_depuis_fichier(ListeEmprunts *liste, const char *nom_fichier);
    void enregistrer_emprunt(Emprunt *nouvel_emprunt);
    void afficher_emprunts(ListeEmprunts *liste);
    Emprunt *rechercher_emprunt(ListeEmprunts *liste, long numero);

    #endif
