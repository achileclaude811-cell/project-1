#include <stdio.h>   
#include <stdlib.h>

// Définition de la structure d'un noeud de la liste doublement chaînée
typedef struct Node {
    int data;           
    struct Node* prev;  
    struct Node* next;  
} Node;

// Fonction pour créer un nouveau noeud
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = value;  
    newNode->prev = NULL;   
    newNode->next = NULL;  
    return newNode;         
}

// Fonction pour insérer un élément dans une liste triée
void insertSorted(Node** head, int value) {
    Node* newNode = createNode(value); // Créer le noeud à insérer
    Node* current;

    // Cas où la liste est vide
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Cas où l'élément doit être inséré au début
    if (value < (*head)->data) {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Parcourir la liste pour trouver la position d'insertion
    current = *head;
    while (current->next != NULL && current->next->data < value) {
        current = current->next;
    }

    
    newNode->next = current->next; 
    if (current->next != NULL) {
        current->next->prev = newNode; 
    current->next = newNode; 
    newNode->prev = current; 
}


void printList(Node* head) {
    Node* temp = head;
    printf("Liste: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL; 
    insertSorted(&head, 10);
    insertSorted(&head, 5);
    insertSorted(&head, 20);
    insertSorted(&head, 15);

    printList(head); 

    return 0;
}