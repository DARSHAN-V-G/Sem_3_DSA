#include<stdio.h>

int main(){
    int arr[]={1,2,3,-1,11,-5,3,-5,8,0};
    int sum=0;
    int max=arr[0];
    int size=sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",size);
    for(int i=0;i<size;i++){
        sum+=arr[i];
        if(max<sum){
            max=sum;
        }
        if(sum<0){
            sum=0;
        }
        
    }
    printf("%d",max);
    return 0;
}