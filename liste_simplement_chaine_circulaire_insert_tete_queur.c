#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef Node* Liste;

// Fonction pour créer un nouveau noeud
Node* creerNoeud(int val) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = val;
    nouveau->next = NULL;
    return nouveau;
}

// Insertion en tête
void insererTete(Liste *liste, int val) {
    Node* nouveau = creerNoeud(val);

    if (*liste == NULL) {
        *liste = nouveau;
        nouveau->next = *liste;
    } else {
        Node* temp = *liste;
        while (temp->next != *liste) {
            temp = temp->next;
        }
        nouveau->next = *liste;
        temp->next = nouveau;
        *liste = nouveau;
    }
}

// Insertion en queue
void insererQueue(Liste *liste, int val) {
    Node* nouveau = creerNoeud(val);

    if (*liste == NULL) {
        *liste = nouveau;
        nouveau->next = *liste;
    } else {
        Node* temp = *liste;
        while (temp->next != *liste) {
            temp = temp->next;
        }
        temp->next = nouveau;
        nouveau->next = *liste;
    }
}

// Affichage
void afficherListe(Liste liste) {
    if (liste == NULL) {
        printf("Liste vide\n");
        return;
    }
    Node* temp = liste;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != liste);
    printf("(retour au debut)\n");
}

int main() {
    Liste maListe = NULL;
    int choix, val;

    do {
        printf("\n=== Menu ===\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("Valeur a inserer en tete : ");
                scanf("%d", &val);
                insererTete(&maListe, val);
                break;
            case 2:
                printf("Valeur a inserer en queue : ");
                scanf("%d", &val);
                insererQueue(&maListe, val);
                break;
            case 3:
                afficherListe(maListe);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}