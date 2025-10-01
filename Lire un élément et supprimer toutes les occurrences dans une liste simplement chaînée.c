#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = head;
    return newNode;
}

Node* deleteOccurrences(Node* head, int x) {
    Node *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->data == x) {
            if (prev == NULL) head = temp->next;
            else prev->next = temp->next;
            free(temp);
            if (prev == NULL) temp = head;
            else temp = prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) { printf("%d -> ", head->data); head = head->next; }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int n, val, x;

    printf("Combien d'elements ? ");
    scanf("%d", &n);

    printf("Entrez %d entiers :\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = insert(head, val);
    }

    printf("Liste avant suppression : ");
    printList(head);

    printf("Entrez l'element a supprimer : ");
    scanf("%d", &x);

    head = deleteOccurrences(head, x);

    printf("Liste apres suppression : ");
    printList(head);

    return 0;
}