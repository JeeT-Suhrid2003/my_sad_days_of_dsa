#include <stdio.h>



int gcd(int a,int b){
    while(b!=0){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}


int lcm(int a,int b){
    return (a/gcd(a,b))*b;
}

int lcmof(int arr[],int n){
    int res=arr[0];
    for(int i=1;i<n;i++){
        res=lcm(res,arr[i]);
    }
    return res;
}



int main(){
    int arr[]={12,15,20};
    int n=3;
    printf("%d",lcmof(arr,n));
}