#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printList(Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

Node* createNode(int x) {
    Node* newNode = 
      (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Node* MergeSort(){

}

int main() {
    Node* head = createNode(9);
    head->next = createNode(8);
    head->next->next = createNode(5);
    head->next->next->next = createNode(2);
    head = MergeSort(head);
    printList(head);
    return 0;
}