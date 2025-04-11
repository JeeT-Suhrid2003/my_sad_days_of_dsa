#include <stdio.h>

int sumofdig(int num){
    int res=0;
    while(num>0){
        res+=num%10;
        num/=10;
    }
    return res;
}

int main(){
    int res=0;
    int temp;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        res+=sumofdig(temp);
    }
    printf("%d ",res);
} 