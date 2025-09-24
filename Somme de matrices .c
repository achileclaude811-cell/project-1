#include <stdio.h>
#include <stdlib.h>

int main() {
    int l, c;
    printf("Somme de deux matrices\n");
    printf("Nombre de lignes : "); 
    scanf("%d", &l);
    printf("Nombre de colonnes : ");
     scanf("%d", &c);

    int A[l][c], B[l][c], S[l][c];

    printf("Saisir la matrice A:\n");
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &A[i][j]);

    printf("Saisir la matrice B:\n");
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &B[i][j]);

    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
            S[i][j] = A[i][j] + B[i][j];

    printf("Somme A + B = \n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++)
            printf("%d\t", S[i][j]);
        printf("\n");
    }

    return 0;
}