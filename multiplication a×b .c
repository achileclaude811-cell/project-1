#include <stdio.h>

int main() {
    int a, b;
    printf("Entrer a et b (positifs) : ");
    scanf("%d %d", &a, &b);

    int produit = 0;
    for (int i = 0; i < b; i++)
        produit += a;

    printf("%d × %d = %d\n", a, b, produit);
    return 0;
}