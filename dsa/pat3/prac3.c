#include <stdio.h>

int countone(int num){
    int count=0;
    while(num>0){
        count+=num&1;
        num>>=1;
    }
    return count;
}

int main(){
    int maxn=0,count=-1;
    int maxcount=-1;
    int test;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&test);
        count=countone(test);
        if(count>maxcount){
            maxcount=count;
            maxn=test;
        }
    }
    printf("%d ",maxn);
}


