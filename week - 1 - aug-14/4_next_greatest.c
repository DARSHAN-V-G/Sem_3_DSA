#include<stdio.h>
int main(){
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int arr[size];
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int stack[size];
    int stacksize=1;
    stack[0]=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<stack[stacksize-1]){
            stack[stacksize]=arr[i];
            stacksize++;
        }else if(arr[i]>stack[stacksize-1]){
            for(int k=0;k<stacksize;k++){
                printf("%d - next bigger - %d\n",stack[k],arr[i]);
            }
            stacksize=1;
            stack[0]=arr[i];
        }
    }
    for(int i=0;i<stacksize;i++){
        printf("%d - next bigger -  -1\n",stack[i]);
    }
    return 0;
}