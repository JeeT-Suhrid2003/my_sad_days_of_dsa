#include <stdio.h>

int countdiv(int num){
    int count=0;
    for(int i=1;i<=num;i++){
        if(num%i==0){
            count++;
            
        }
    }
    return count;
}

int main()
{
    int temp=countdiv(25);
    printf("%d",temp);
}
