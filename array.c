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
    printf("1.Ascending order \n2.Descending Order\n\nEnter your choice : ");
    int c;
    scanf("%d",&c);
    switch(c){
    case 1:
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    print(arr);
    break;
    case 2:
        for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]<arr[j+1]){
                swap=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=swap;
            }
        }
    }
    print(arr);
    break;
    default:
        printf("Invalid choice ");
    }
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

int* split(int *arr1,int size2){
    int i;
    int *arr2 = (int*)malloc(sizeof(int)*(size-size2));
    for(i=0;i<size2;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for(int j=i;j<size;j++){
        arr2[j-i]=arr1[j];
        printf("%d ",arr2[j-i]);
    }
    size=size2;
    return arr2;
}

void merge(int *arr1,int *arr2,int size2){
    for(int i=0;i<size2;i++){
        arr1[size+i]=arr2[i];
    }

    size+=size2;
    printf("\n");
}

void exchange(int *arr,int p1,int p2){
    int temp=arr[p1];
    arr[p1]=arr[p2];
    arr[p2]=temp;
    print(arr);
}

void rotate(int *arr,int num){

    printf("\n1.Left rotation\n2.Right rotation\n\nEnter your choice :");
    int c;
    int temp;
    scanf("%d",&c);
    switch(c){
    case 1:
        for(int i=0;i<num%size;i++){
            int temp=arr[0];
            for(int j=1;j<size;j++){
                arr[j-1]=arr[j];
            }
            arr[size-1]=temp;
        }
        break;
    case 2:
        for(int i=0;i<num%size;i++){
            temp=arr[size-1];
            for(int j=size-1;j>0;j--){
                arr[j]=arr[j-1];
            }
            arr[0]=temp;
        }
        break;
    default:
        printf("\nInvalid choice");
    }

}

int main()
{
    int *arr1;

    int *arr3=NULL;

    int size3=0;
    int choice;
    menu:
    printf("\n\nUSER MENU\n\n0.Initialize an array\n1.Deleting\n2.Inserting\n3.Sorting\n4.Searching\n5.Updating\n6.Exchanging of array\n7.Merging of array\n8.Splitting of array\n9.Rotating of array\n10.Traversing\n11.Displaying\n12.Copying of elements\n13.Exit\n");
    printf("\nEnter your choice : ");
    -  0
    scanf("%d",&choice);
    int size2,item,pos;
    int *arr2;
    int h=0;
    switch(choice){
    case 0:
        printf("Enter size of array : ");
        scanf("%d",&size);
        arr1=(int*)malloc(sizeof(int)*size);
        printf("Enter elements of the array : ");
            for(int i=0;i<size;i++){
        scanf("%d",&arr1[i]);
    }
    break;
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
        print(arr1);
        break;
    case 7:
        if(arr3!=NULL){
    printf("%d",size3);
        arr1=realloc(arr1,(sizeof(int)*(size+size3)));
        merge(arr1,arr3,size3);
        }else{
        printf("Enter size of array 2 : ");
        scanf("%d",&size2);
        arr2=(int*)malloc(sizeof(int)*size2);
        printf("Enter elements of array 2 :");
        for(int k=0;k<size2;k++){
            scanf("%d",&arr2[k]);
        }
        arr1=realloc(arr1,(sizeof(int)*(size+size2)));
        merge(arr1,arr2,size2);                                                                                                                                                                                                                                                                                      
        }
        free(arr3);
        arr3=NULL;
        print(arr1);
        break;
    case 8:
        printf("Enter the splitting position : ");
        scanf("%d",&item);
        size3=size-item;
        arr3=(int*)malloc(sizeof(int)*(size-item));
        arr3 = split(arr1,item);
        break;
    case 9:
        printf("Enter the number of rotation : ");
        scanf("%d",&item);
        rotate(arr1,item);
        print(arr1);
        break;
    case 10:
        printf("Traversing the array :");
        print(arr1);
        break;
    case 11:
        printf("Displaying the array :");
        print(arr1);
        break;
    case 12:
        printf("Elements Copied : ");
        print(arr1);
        break;
    case 13:
        return 0;
    default:
        printf("Invalid choice.");
    }
    goto menu;
    return 0;
}
