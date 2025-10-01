#include <stdio.h>
#include <stdlib.h>

// Définition de la structure Cellule
typedef struct Cellule {
    int i;   // Donnée de la cellule
    struct Cellule* suivant; // Pointeur vers la cellule suivante
} Cellule;

// Fonction pour afficher la liste
void afficherListe(Cellule* tete) {
    Cellule* courant = tete;
    while (courant != NULL) {
        printf("%d -> ", courant->i);
        courant = courant->suivant;
    }
    printf("NULL\n");
}

// Fonction pour insérer un élément dans une liste triée
Cellule* insererTrie(Cellule* tete, int val) {
    Cellule* P = (Cellule*)malloc(sizeof(Cellule)); // Nouvelle cellule
    if (P == NULL) {
        printf("Erreur d'allocation mémoire !\n");
        exit(1);
    }
    P->i = val;
    P->suivant = NULL;

    // Cas 1 : Liste vide (tête est NULL)
    if (tete == NULL) {
        return P;
    }

    // Cas 2 : Insertion en tête (si la nouvelle valeur est plus petite)
    if (val < tete->i) {
        P->suivant = tete;
        return P;
    }

    // Cas général : Recherche de la position d'insertion
    Cellule* courant = tete;
    while (courant->suivant != NULL && courant->suivant->i < val) {
        courant = courant->suivant;
    }

    // Insertion après courant
    P->suivant = courant->suivant;
    courant->suivant = P;
    return tete;
}

int main() {
    Cellule* tete = NULL; // Liste initialement vide
    int val;
    char entree[100];

    // Saisie des éléments initiaux de la liste
    printf("Entrez les éléments initiaux de la liste triée (entiers, tapez 'fin' pour terminer) :\n");
    while (1) {
        printf("Val : ");
        scanf("%s", entree);
        if (strcmp(entree, "fin") == 0) {
            break;
        }
        
        // Vérification si l'entrée est un entier
        if (sscanf(entree, "%d", &val) != 1) {
            printf("Veuillez entrer un entier ou 'fin' pour terminer.\n");
            continue;
        }

        tete = insererTrie(tete, val);
    }

    // Affichage de la liste initiale
    printf("\nListe actuelle : ");
    afficherListe(tete);

    // Saisie de l'élément à insérer
    printf("\nEntrez l'élément à insérer (entier) : ");
    if (scanf("%d", &val) != 1) {
        printf("Entrée invalide. Veuillez entrer un entier.\n");
        return 1;
    }

    // Insertion et affichage du résultat
    tete = insererTrie(tete, val);
    printf("Liste après insertion : ");
    afficherListe(tete);

    // Libération de la mémoire (optionnel pour cet exemple)
    Cellule* courant = tete;
    while (courant != NULL) {
        Cellule* temp = courant;
        courant = courant->suivant;
        free(temp);
    }

    return 0;
}