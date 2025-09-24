#include <stdio.h>

int main() {
    int n, x;
    printf("Taille du tableau : ");
    scanf("%d", &n);

    int tab[n];
    for (int i = 0; i < n; i++) {
        printf("tab[%d] = ", i);
        scanf("%d", &tab[i]);
    }

    printf("Valeur à rechercher : ");
    scanf("%d", &x);

    int trouve = -1;
    for (int i = 0; i < n; i++) {
        if (tab[i] == x) {
            trouve = i;
            break;
        }
    }

    if (trouve != -1) printf("Valeur trouvée à l’indice %d\n", trouve);
    else printf("Valeur non trouvée\n");

    return 0;
}