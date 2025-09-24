# project-1






               Collection de Programmes sur les Tableaux, Matrices et Vecteurs

Ce projet regroupe une série de neuf programmes implémentant des opérations fondamentales en mathématiques et algorithmique sur les tableaux, matrices et vecteurs. Chaque programme est indépendant et peut être utilisé pour l’apprentissage ou comme base pour des projets plus complexes.

1.  Somme de Matrices

Additionne deux matrices de mêmes dimensions en additionnant élément par élément.

- Entrée : Deux matrices A et B de dimensions (m × n)
- Sortie : Une matrice C = A + B

2. Produit de Matrices

Multiplie deux matrices selon la règle de multiplication matricielle.

- Entrée : Matrice A (m × n) et Matrice B (n × p)
- Sortie : Matrice C (m × p) telle que C[i][j] = somme(A[i][k] × B[k][j])

3. Recherche Séquentielle dans un Tableau

Parcourt un tableau séquentiellement pour rechercher une valeur donnée.

- Entrée : Tableau T[n], élément x à chercher
- Sortie : Index de x s’il est présent, sinon -1

4. Multiplication a × b (avec a, b > 0)

Calcule le produit de deux entiers strictement positifs sans utiliser l’opérateur `*`.

- Entrée : Deux entiers a et b > 0
- Sortie : Produit a × b (via additions successives ou autre méthode récursive/itérative)

5.  Tester si un Tableau est Trié

Vérifie si un tableau est trié dans l’ordre croissant.

- Entrée : Tableau T[n]
- Sortie : Booléen (vrai si trié, faux sinon)

6. Trouver la Médiane dans un Tableau

Calcule la médiane d’un tableau (élément central ou moyenne des deux centraux si n est pair).

- Entrée : Tableau T[n]
- Sortie : Médiane

7. Inverser un Tableau

Inverse l’ordre des éléments d’un tableau.

- Entrée : Tableau T[n]
- Sortie : Tableau T inversé (in-place ou nouveau tableau)

8. Produit Vectoriel (Vecteurs 3D)

Calcule le produit vectoriel entre deux vecteurs 3D.

- Entrée : Vecteurs A = (a1, a2, a3), B = (b1, b2, b3)
-  Sortie : Vecteur C = A × B = (a2*b3 - a3*b2, a3*b1 - a1*b3, a1*b2 - a2*b1)



9. Produit Vecteur × Matrice

Multiplie un vecteur ligne avec une matrice.

- Entrée : Vecteur V[n], Matrice M[n × p]
- Sortie : Vecteur R[p] tel que R[j] = somme(V[i] × M[i][j])

📁 Structure recommandée des fichiers

/projet-1 │ ├── 1_somme_matrices.c ├── 2_produit_matrices.c ├── 3_recherche_sequentielle.c ├── 4_multiplication.c ├── 5_test_tri_tableau.c ├── 6_mediane_tableau.c ├── 7_inverser_tableau.c ├── 8_produit_vectoriel.c ├── 9_vecteur_fois_matrice.c└── README.md




