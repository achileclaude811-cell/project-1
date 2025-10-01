#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour insérer en tête dans une liste circulaire
void insertAtHead(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;  // Le nœud pointe sur lui-même
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;  // Le nouveau nœud devient la tête
    }
}

// Fonction pour insérer en queue dans une liste circulaire
void insertAtTail(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

// Fonction pour afficher la liste
void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Fonction principale
int main() {
    Node* head = NULL;
    int value;

    // Insertion en tête
    printf("Entrez un élément à insérer en tête: ");
    scanf("%d", &value);
    insertAtHead(&head, value);

    // Insertion en queue
    printf("Entrez un élément à insérer en queue: ");
    scanf("%d", &value);
    insertAtTail(&head, value);

    // Affichage de la liste
    printf("Liste circulaire après insertions: ");
    display(head);

    return 0;
}