#include <stdio.h>

int main() {
    int lA, cA, lB, cB;
    printf("Taille de A (lignes colonnes) : ");
    scanf("%d %d", &lA, &cA);
    printf("Taille de B (lignes colonnes) : ");
    scanf("%d %d", &lB, &cB);

    if (cA != lB) {
        printf("Multiplication impossible (dimensions incompatibles).\n");
        return 1;
    }

    int A[lA][cA], B[lB][cB], P[lA][cB];

    printf("Saisir A :\n");
    for (int i = 0; i < lA; i++)
        for (int j = 0; j < cA; j++)
            scanf("%d", &A[i][j]);

    printf("Saisir B :\n");
    for (int i = 0; i < lB; i++)
        for (int j = 0; j < cB; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < lA; i++)
        for (int j = 0; j < cB; j++) {
            P[i][j] = 0;
            for (int k = 0; k < cA; k++)
                P[i][j] += A[i][k] * B[k][j];
        }

    printf("A × B = \n");
    for (int i = 0; i < lA; i++) {
        for (int j = 0; j < cB; j++)
            printf("%d\t", P[i][j]);
        printf("\n");
    }
    return 0;
}