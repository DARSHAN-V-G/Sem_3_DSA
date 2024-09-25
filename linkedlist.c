#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;


Node* createLinkedList(int size){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *start = (Node*)malloc(sizeof(Node));
    printf("Node Values = ");
    scanf("%d",&head->val);
    start=head;
    for(int i=1;i<size;i++){
        head->next = (Node*)malloc(sizeof(Node));
        scanf("%d",&head->next->val);
        head=head->next;
    }
    head->next=NULL;
    return start;

}

void print(Node* head){
    while(head!=NULL){
        printf("%d-->",head->val);
        head=head->next;
    }
}

void insertNode(Node *head,int pos,int value){

    for(int i=0;i<pos-1;i++){
        head=head->next;
    }
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->val=value;
    newNode->next=head->next;
    head->next=newNode;
}

void deleteNode(Node* head,int pos){
for(int i=0;i<pos-1;i++){
    head=head->next;
}
head->next=head->next->next;
}
void swap(Node* head,int pos1,int pos2){
    Node *ptr1=(Node*)malloc(sizeof(Node));
    Node *ptr2=(Node*)malloc(sizeof(Node));
    for(int i=0;head!=NULL;i++){
        if(i==pos1-1){
            ptr1=head;
        }else if(i==pos2-1){
            ptr2 = head;
        }
        head=head->next;
    }
    Node* temp = (Node*)malloc(sizeof(Node));
    head=ptr1->next;
    ptr1->next=ptr2->next;
    ptr1=ptr1->next;
    temp=ptr1->next;
    ptr1->next=head->next;
    ptr2->next=head;
    head->next=temp;
}

void sort(Node *head,int flag){
    
}

//Insert,Delete,Search,update,swap,merge,split,copy,rotate,

int main()
{
    printf("Enter Size : ");
    int size,choice;
    Node* head = (Node*)malloc(sizeof(Node));
    menu:
    printf("\n\n1. Create Linked List\n2. Insert\n3. Delete\n4. Sort\n5. Search\n6. Swap Two nodes\n7. Rotate Linked List");
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);
    int pos,value;
    switch(choice){

    case 1:
        printf("Enter size : ");
        scanf("%d",&size);
        head=createLinkedList(size);
        printf("Linked List created successfully...\n");
        print(head);
        break;
    case 2:
        printf("Enter position of node to be inserted : ");
        scanf("%d",&pos);
        if(pos>=size){
            printf("Invalid position.\n");
        }else{
            printf("Enter value : ");
            scanf("%d",&value);
            insertNode(head,pos,value);
            print(head);
        }
        break;
    case 3:
        printf("Enter position of node to be deleted : ");
        scanf("%d",&pos);
        if(pos==0){
            head=head->next;
        }else{
        deleteNode(head,pos);
        }
        print(head);
        break;

    case 6:
            printf("Enter two positions of node to be swapped : ");
            scanf("%d %d",&pos,&value);
            swap(head,pos,value);
            print(head);
    default:
        printf("Invalid choice");

    }
    goto menu;
    return 0;
}
