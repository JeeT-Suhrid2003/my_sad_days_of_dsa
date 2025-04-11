#include<stdio.h>

int main(){
    int opt;
    int temp,count=0;
    float mean=0;
    scanf("%d",&opt);
    int arr[1000];
    while(1){
        
        if(opt==1){
            scanf("%d",&temp);
            arr[count]=temp;
            count++;
        }
        if(opt==2){
            if(count>0){
            for(int i=0;i<count-1;i++){
                arr[i]=arr[i+1];
            }
            count--;
            }
        }
        if(opt==3){
            if(count<=0){
                printf("this is empty");
                break;
                }
            for(int i=0;i<count;i++){
                printf("%d ",arr[i]);
                mean+=arr[i];
                
            }
            mean=mean/count;
            printf("the mean= %.2f",mean);
        }
        if(opt==4){
            break;
        }
        
        scanf("%d",&opt);

    }
}