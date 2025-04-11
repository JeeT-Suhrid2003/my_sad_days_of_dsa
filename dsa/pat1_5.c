#include <stdio.h>
int s1[5],s2[5];
int top1=-1, top2=-1;
int count=0;
void push1(int x){
    if(top1==4){
        printf("thid is overflow condition");
    }
    else{
        top1++;
        s1[top1]=x;
    }
}


void push2(int x){
    if(top2==4){
        printf("thid is overflow condition");
    }
    else{
        top2++;
        s2[top2]=x;
    }
}

int pop1(){
   int temp=s1[top1];
   top1--;
   return temp; 
}

int pop2(){
    int temp=s2[top2];
    top2--;
    return temp;
}


 void dequeue(){
    if(top2==-1&&top1==-1){
        printf("there is nothing to dequueue");
    }
    else{
        for(int i=0;i<count;i++){
            push2(pop1());
        }
        printf("the dequeued element is %d\n",pop2());
        count--;
        for(int i=0;i<count;i++){
            push1(pop2());
        }
    }
 }
void enqueue(int x){
    push1(x);
    count++;
}

void dispaly(){
    for(int i=0;i<count;i++){
        printf("%d ",s1[i]);
    }
}
int main(){
    enqueue(5);
    enqueue(3);
    enqueue(-1);
     dispaly();
    dequeue();
    dispaly();
}