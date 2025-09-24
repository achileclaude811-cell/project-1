#include <stdio.h>

int main() {
    int tab[5] = {3, 1, 5, 2, 4};
    int n = 5;
    int tmp;

    // Tri simple par échange (bubble sort)
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(tab[i] > tab[j]) {
                tmp = tab[i];
                tab[i] = tab[j];
                tab[j] = tmp;
            }
        }
    }

    if(n % 2 == 1)
        printf("Médiane = %d\n", tab[n/2]);
    else
        printf("Médiane = %.1f\n", (tab[n/2 - 1] + tab[n/2])/2);

    return 0;
}