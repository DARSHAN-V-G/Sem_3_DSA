#include <stdio.h>
#include <stdlib.h>
int size;

void print(int *arr){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

void deleteItem(int *arr,int item){
    int j=0,temp;
    int dummy=size;
    for(int i=0;i<dummy;i++){
        if(arr[i]!=item){
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            j++;
        }else{
            size--;
        }
    }
    return;
}

int search(int *arr,int item){
    for(int i=0;i<size;i++){
        if(arr[i]==item){
            return i;
        }
    }
    return -1;
}

void sort(int *arr){
    int swap;
    for(int i=0;i<size;i++){
        for(int j=i;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    print(arr);
    return;
}

void insert(int *arr,int item,int pos){
    printf("\n%d\n",size);
    for(int i=size;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=item;
    return;
}

void update(int *arr,int pos,int item){

    arr[pos]=item;

}

void exchange(int *arr1,int *arr2,int size2){
    for(int i=0;i<size2;i++){
        arr[size+i]=arr[size2];
    }
    size+=size2;
}

void exchange(int *arr,int p1,int p2){
    int temp=arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
    print(arr);
}

int main()
{
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *arr1;
    arr1=(int*)malloc(sizeof(int)*size);
    printf("Enter elements of the array : ");
    for(int i=0;i<size;i++){
        scanf("%d",&arr1[i]);
    }
    int choice;
    menu:
    printf("\n\nUSER MENU\n\n1.Deleting\n2.Inserting\n3.Sorting\n.Searching\n5.Updating\n6.Exchanging of array\n7.Merging of arra\n8.Splitting of array\n9.Rotating of array\n10.Traversing\n11.Displaying\n12.Copying of elemnents\n13.Exit\n");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    int size2,item,pos;
    int *arr2;
    switch(choice){
    case 1:
        printf("\nEnter element to be deleted : ");
        scanf("%d",&item);
        deleteItem(arr1,item);
        printf("\nAfter deleting : ");
        print(arr1);
        break;
    case 2:
        printf("\nEnter element to inserted : ");
        size+=1;
        arr1 = realloc(arr1,sizeof(int)*(size+1));
        scanf("%d",&item);
        printf("Enter at which position the given item is to be inserted : ");
        scanf("%d",&pos);
        insert(arr1,item,pos);
        print(arr1);
        break;
    case 3:
        printf("\nSorted array : ");
        sort(arr1);
        break;
    case 4:
        printf("Enter element to be searched : ");
        scanf("%d",&item);
        printf("Element found at index %d",search(arr1,item));
        break;
    case 6:
        printf("Enter the two index position which is to be exchanged : ");
        scanf("%d %d",&item,&pos);
        exchange(arr1,item,pos);
        break;
    case 5:
        printf("Enter the element index which is to updated : ");
        scanf("%d",&pos);
        printf("Enter the value : ");
        scanf("%d",&item );
        update(arr1,pos,item);
        break;
    case 7:
        size2;
        printf("Enter size of array 2 : ");
        scanf("%d",&size2);
        arr2=(int*)malloc(sizeof(int)*size2);
        printf("Enter elements of array 2 :");
        for(int k=0;k<size2;k++){
            scanf("%d",&arr2[k])
        }
        arr1=realloc(arr1,(sizeof(int)*(size+size2)));
        merge(arr1,arr2,size2);
        break;
    case 8:
        printf("Enter the number of splitting positions : ");
        scanf("%d",&item);
        for(int i=0;i<item;i++){
            scanf("%d",&arr2[i]);
        }
        spilt(arr1,arr2);
        break;
    case 9:
        printf("Enter the position of rotation : ");
        scanf("%d",&item);
        break;
    default:
        printf("Invalid choice.");
    }
    goto menu;
    return 0;
}
