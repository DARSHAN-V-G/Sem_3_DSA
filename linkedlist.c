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

Node* split(Node *head){
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        if(fast!=NULL){
            slow = slow->next;
        }
    }
    Node* temp = slow->next;
    slow->next=NULL;
    return temp;
}

int checkOrder(int flag, int first,int second){
    if(flag==1){
        if(first<second){
            return 1;
        }else{
            return 0;
        }
    }else{
        if(first>second){
            return 1;
        }else{
            return 0;
        }
    }
}

Node* mergeList(Node* first, Node* second, int flag){
    if(first==NULL) return second;
    if(second==NULL) return first;

    if(checkOrder(flag,first->val,second->val)){
        first->next = mergeList(first->next,second,flag);
        return first;
    }else{
        second->next=mergeList(second->next,first,flag);
        return second;
    }
}


Node* merge(Node *head,int flag){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node *first = head;
    Node *second = split(head);
    first = merge(first,flag);
    second = merge(second,flag);

    return mergeList(first,second,flag);
}

//Insert,Delete,Search,update,swap,merge,split,copy,rotate,
void search(Node* head,int value){
    int count = 0 ;
    while(head!=NULL){
        if(value==head->val){
            printf("Value found at index %d",count);
            return;
        }
        count++;
        head=head->next;
        
    }
    printf("Element Not found !");
}

Node* rotate(Node* head,int count){
    int num=1;
    Node* start = head;
    while(num!=count){
        if(num!=count){
            start=start->next;
        }
        num++;
    }
    Node* temp = start->next;
    start->next=NULL;
    start=temp;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head;
    return start;
}

Node* reverse(Node* head){
    Node* next = NULL;
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main()
{
    printf("Enter Size : ");
    int size,choice;
    Node* head = (Node*)malloc(sizeof(Node));
    menu:
    printf("\n\n1. Create Linked List\n2. Insert\n3. Delete\n4. Sort\n5. Search\n6. Swap Two nodes\n7. Rotate Linked List\n8. Reverse");
    printf("\n\nEnter your choice : ");
    scanf("%d",&choice);
    int pos,value,flag;
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
    case 4:
        printf("1.Ascending order.\n2.Descending order.\n");
        printf("Enter your choice : ");
        scanf("%d",&pos);
        if(pos==1){
            flag=1;
        }else{
            flag=0;
        }
        head = merge(head,flag);
        print(head);
        break;
    case 5:
        printf("Enter element to be searched : ");
        scanf("%d",&pos);
        search(head,pos);
        break;
    case 6:
        printf("Enter two positions of node to be swapped : ");
        scanf("%d %d",&pos,&value);
        swap(head,pos,value);
        print(head);
        break;
    case 7:
        printf("1.Left rotation\n2.Right rotation.\n");
        printf("Enter your choice : ");
        scanf("%d",&pos);
        printf("Number of times of rotation : ");
        scanf("%d",&flag);
        if(pos==1){
            head = rotate(head,flag%size);
        }else{
            head = rotate(head,size - (flag%size));
        }
        print(head);
        break;
    case 8:
        head = reverse(head);
        print(head);
        break;
    default:
        printf("Invalid choice");

    }
    goto menu;
    return 0;
}
