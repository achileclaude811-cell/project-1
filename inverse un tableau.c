#include <stdio.h>

int main() {
    int tab[5] = {2 , 4, 6 , 8 , 10};
    int n = 5;
    int tmp;

    for(int i=0; i<n/2; i++) {
        tmp = tab[i];
        tab[i] = tab[n-1-i];
        tab[n-1-i] = tmp;
    }

    printf("Tableau inversé: ");
    for(int i=0; i<n; i++)
        printf("%d ", tab[i]);

    return 0;
}