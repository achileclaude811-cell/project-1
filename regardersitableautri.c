#include <stdio.h>

int main() {
    int n;
    printf("Taille du tableau : ");
    scanf("%d", &n);

    int tab[n];
    for (int i = 0; i < n; i++) scanf("%d", &tab[i]);

    int croissant = 1, decroissant = 1;
    for (int i = 1; i < n; i++) {
        if (tab[i] < tab[i-1]) croissant = 0;
        if (tab[i] > tab[i-1]) decroissant = 0;
    }

    if (croissant) printf("Tableau trié croissant\n");
    else if (decroissant) printf("Tableau trié décroissant\n");
    else printf("Tableau non trié\n");

    return 0;
}