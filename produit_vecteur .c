#include <stdio.h>

int main() {
    int a[3], b[3], r[3];

    printf("Entrez les 3 composantes de A (séparées par des espaces) : ");
    for(int i=0; i<3; i++) scanf("%d", &a[i]);

    printf("Entrez les 3 composantes de B (séparées par des espaces) : ");
    for(int i=0; i<3; i++) scanf("%d", &b[i]);

    // Produit vectoriel
    r[0] = a[1]*b[2] - a[2]*b[1];
    r[1] = a[2]*b[0] - a[0]*b[2];
    r[2] = a[0]*b[1] - a[1]*b[0];

    printf("A × B = (%d, %d, %d)\n", r[0], r[1], r[2]);

    return 0;
}
