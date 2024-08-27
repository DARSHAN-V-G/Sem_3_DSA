#include<stdio.h>
int main(){
    int arr[]={1,2,3,4,5,6,7,6,5,4,1,1,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min;
    printf("%d\n",size);
    for(int i=0;i<size;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(arr[min]<arr[i]){
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }
    }
    int i=1;
    int c=1;
    int countsize=0;
    int count[size];
    int countarray[size];
    for(int k=0;k<size;k++){
        printf("%d ",arr[k]);
    }
    printf("\n");
    while(i<size){
        c=1;
        while(i<size && arr[i]==arr[i-1]){
            c+=1;
            i++;
        }
        if(c%2==1){
            count[countsize]=arr[i-1];
            countarray[countsize++]=c;
        }
        if(i==size-1){
            count[countsize]=arr[i];
            countarray[countsize++]=1;
        }
        i++;
    }
    for(i=0;i<countsize;i++){
        printf("%d - %d times\n",count[i],countarray[i]);
    }

    return 0;
}