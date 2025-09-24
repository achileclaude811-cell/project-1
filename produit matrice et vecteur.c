#include <stdio.h>
#include <stdlib.h>

// Fonction pour calculer le produit d'un vecteur par une matrice
void produitVecteurMatrice(int *vecteur, int lignes, int **matrice, int colonnes, int *resultat) {
    // Parcourir chaque colonne de la matrice
    for (int j = 0; j < colonnes; j++) {
        resultat[j] = 0; // Initialiser le résultat pour la j-ème composante
        // Calculer la somme des produits vecteur[i] * matrice[i][j]
        for (int i = 0; i < lignes; i++) {
            resultat[j] += vecteur[i] * matrice[i][j];
        }
    }
}

int main() {
    int lignes, colonnes;

    // Demander les dimensions
    printf("Entrez le nombre de lignes (et taille du vecteur) : ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes : ");
    scanf("%d", &colonnes);

    // Vérifier les dimensions
    if (lignes <= 0 || colonnes <= 0) {
        printf("Erreur : dimensions invalides.\n");
        return 1;
    }

    // Allouer le vecteur
    int *vecteur = (int *)malloc(lignes * sizeof(int));
    if (vecteur == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    // Saisir les éléments du vecteur
    printf("Saisissez les éléments du vecteur :\n");
    for (int i = 0; i < lignes; i++) {
        printf("Vecteur[%d] : ", i);
        scanf("%d", &vecteur[i]);
    }

    // Allouer la matrice (tableau de pointeurs)
    int **matrice = (int **)malloc(lignes * sizeof(int *));
    if (matrice == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        free(vecteur);
        return 1;
    }
    for (int i = 0; i < lignes; i++) {
        matrice[i] = (int *)malloc(colonnes * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Erreur d'allocation mémoire.\n");
            // Libérer ce qui a déjà été alloué
            for (int k = 0; k < i; k++) free(matrice[k]);
            free(matrice);
            free(vecteur);
            return 1;
        }
    }

    // Saisir les éléments de la matrice
    printf("Saisissez les éléments de la matrice :\n");
    for (int i = 0; i < lignes; i++) {
        for (int j = 0; j < colonnes; j++) {
            printf("Matrice[%d][%d] : ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    // Allouer le vecteur résultat
    int *resultat = (int *)malloc(colonnes * sizeof(int));
    if (resultat == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        // Libérer la matrice et le vecteur
        for (int i = 0; i < lignes; i++) free(matrice[i]);
        free(matrice);
        free(vecteur);
        return 1;
    }

    // Calculer le produit
    produitVecteurMatrice(vecteur, lignes, matrice, colonnes, resultat);

    // Afficher le résultat
    printf("Résultat du produit (vecteur) : ");
    for (int j = 0; j < colonnes; j++) {
        printf("%d ", resultat[j]);
    }
    printf("\n");

    // Libérer la mémoire
    free(vecteur);
    for (int i = 0; i < lignes; i++) free(matrice[i]);
    free(matrice);
    free(resultat);

    return 0;
}