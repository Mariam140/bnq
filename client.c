#include "client.h"
#include <stdio.h>
#include <stdlib.h>

void initialiserListeClients(ListeClients *liste)
{
    liste->debut = NULL;
}
void afficher_clients(ListeClients *liste)
{
    Client *actuel =liste->debut;
    while(actuel!=NULL)
    {
        printf("Numeros : %ld Nom : %s Prenom : %s Genre : %c  date de naissance : %s lieu de naissance : %s profession : %s ",
               actuel->numero,
               actuel->nom,
               actuel->prenom,
               actuel->genre,
               actuel->date_naissance,
               actuel->lieu_naissance,
               actuel->profession);
        actuel=actuel->suivant;
    }
}

void afficher_client(Client nouveauClient)
{
    printf("Numeros : %ld Nom : %s Prenom : %s Genre : %c  date de naissance : %d %d %d lieu de naissance : %s profession : %s \n",
           nouveauClient.numero,
           nouveauClient.nom,
           nouveauClient.prenom,
           nouveauClient.genre,
           nouveauClient.date_naissance.aaaa,
           nouveauClient.date_naissance.mm,
           nouveauClient.date_naissance.jj,
           nouveauClient.lieu_naissance,
           nouveauClient.profession);
}

void enregistrer_client(ListeClients *liste, Client *nouveau_client)
{
    nouveau_client->suivant = liste->debut;
    liste->debut = nouveau_client;
}
void enregistrer_client_dans_fichier(Client *nouveauClient)
{
    FILE *fichier;
    fichier = fopen("clients.txt", "a");
    if(fichier != NULL)
    {
        int result = fprintf(fichier, "%ld %s %s %c %d %d %d %s %s\n",
                             nouveauClient->numero,
                             nouveauClient->nom,
                             nouveauClient->prenom,
                             nouveauClient->genre,
                             nouveauClient->date_naissance.aaaa,
                             nouveauClient->date_naissance.mm,
                             nouveauClient->date_naissance.jj,
                             nouveauClient->lieu_naissance,
                             nouveauClient->profession);

        if (result < 0)
        {
            printf("Erreur lors de l'ecriture dans le fichier.\n");
        }
        else
        {
            fclose(fichier);
            printf("Le client a ete enregistre avec succes.\n");
        }
    }
    else
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

}


int validateDate(Date d)
{
    return (d.jj > 0 && d.jj <= 31) && (d.mm > 0 && d.mm <= 12) && (d.aaaa >= 1990 && d.aaaa <= 2023);


}
   void charger_client_depuis_fichier(ListeClients *liste, const char *nom_fichier) {
    FILE *file = fopen(nom_fichier, "r");
    if (file != NULL) {
        Client nouveauClient;
        while (fscanf(file, "%ld %s %s %c %s %s %s",
                      &nouveauClient.numero,
                      nouveauClient.nom,
                      nouveauClient.prenom,
                      &nouveauClient.genre,
                      nouveauClient.date_naissance.jj,
                      nouveauClient.date_naissance.mm,
                      nouveauClient.date_naissance.aaaa,
                      nouveauClient.lieu_naissance,
                      nouveauClient.profession) == 9) {
            enregistrer_client(liste, &nouveauClient);
        }
        fclose(file);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }
}

void modifier_client(ListeClients *liste, long numero)
{
    Client *courant = liste->debut;

    while (courant != NULL)
    {
        if (courant->numero == numero)
        {
            printf("Modification du client %ld :\n", numero);

            printf("Nouveau nom : ");
            scanf("%s", courant->nom);

            printf("Nouveau prenom : ");
            scanf("%s", courant->prenom);

            printf("Nouveau genre (H/F) : ");
            scanf(" %c", &courant->genre);

            printf("Nouvelle date de naissance : ");
            scanf("%s", courant->date_naissance);

            printf("Nouveau lieu de naissance : ");
            scanf("%s", courant->lieu_naissance);

            printf("Nouveau m�tier : ");
            scanf("%s", courant->profession);

            printf("Modification effectu�e avec succ�s.\n");
            return;
        }
        courant = courant->suivant;
    }

    printf("Aucun client trouve avec le numero %ld\n", numero);
}

Client* rechercher_client(ListeClients *liste, long numero)
{
    Client *courant = liste->debut;

    while (courant != NULL)
    {
        if (courant->numero == numero)
        {
            return courant;
        }
        courant = courant->suivant;
    }

    return NULL;
}

