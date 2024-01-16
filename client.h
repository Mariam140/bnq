#ifndef CLIENT_H
#define CLIENT_H

typedef struct Date {
    int jj;
    int mm;
    int aaaa;
} Date;

typedef struct Client {
    long numero;
    char nom[50];
    char prenom[50];
    char genre;
    Date date_naissance;
    char lieu_naissance[50];
    char profession[50];
    struct Client *suivant;
} Client;



typedef struct {
    Client *debut;
} ListeClients;

void initialiserListeClients(ListeClients *liste);
void enregistrer_client(ListeClients *liste, Client *nouveau_client);
void enregistrer_client_dans_fichier(Client *nouveauClient);
extern int info_validate_date(Date);
void afficher_clients(ListeClients *liste);
void afficher_client(Client nouveauClient);
   void charger_client_depuis_fichier(ListeClients *liste, const char *nom_fichier) ;


void modifier_client(ListeClients *liste, long numero);
Client* rechercher_client(ListeClients *liste, long numero);

#endif
