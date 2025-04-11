// 
#include <stdio.h>

void merge(int arr[],int left,int mid, int right){
    int i,j,k;
    int n1=mid-left+1;
    int n2=right-mid;
    
    int larr[n1],rarr[n2];
    
    for(i=0;i<n1;i++){
        larr[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        rarr[j]=arr[mid+1+j];
    }
    i=0;j=0;k=left;
     while(i<n1&&j<n2){
         if( larr[i]<=rarr[j]){
             arr[k]=larr[i++];
             }
         else{
            arr[k]=rarr[j++];
         }
         k++;
     }
    while(i<n1){
        arr[k]=larr[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=rarr[j];
        j++;
        k++;
    }
}
void mergsort(int arr[],int left,int right){
        if(left<right){
            int mid=left+(right-left)/2;
            
            mergsort(arr,left,mid);
            mergsort(arr,mid+1,right);
            
            merge(arr,left,mid,right);
        }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        
    }
    mergsort(arr,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
}