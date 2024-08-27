#include<stdio.h>
int main(){
    int arr[]={5,6,1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int l=0,r=size-1;
    while(l<r){
        int m=(l+r)/2;
        if(arr[m]>arr[r]){
            l=m+1;
        }else if(arr[m]<arr[r]){
            r=m;
        }
    }
    printf("%d",arr[r]);
    return 0;
}