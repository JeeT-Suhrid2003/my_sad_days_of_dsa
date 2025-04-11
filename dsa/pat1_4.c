#include <stdio.h>

    int queue[5];
    int rar= -1,fro= -1;

void enqueue(int x){
    if(rar==-1,fro==-1){
        rar=0,fro=0;
        queue[rar]=x;

    }
    else if((rar+1)%5==fro){
        printf("the full \n");

    }
    else{
        rar=(rar+1)%5;
        queue[rar]=x;

    }
}

void dequeue(){
            if(rar==-1&&fro==-1){
                printf("the this is empty \n");

            }
            else if(rar==fro){

                printf("%d the alst elemnet is ded\n",queue[fro]);
                rar=-1,fro=-1;
            }
            else{
                printf("%d the alst elemnet is ded\n",queue[fro]);
                fro=(fro+1)%5;

            }
}

void dispaly(){
    if (fro == -1 && rar == -1) { // Queue is empty
        printf("The queue is empty.\n");
        return;
    }
    int i=fro;

    while(i!=rar){
        printf("%d ",queue[i]);
        i=(i+1)%5;
    }

    printf("%d \n",queue[i]);
}
void peek(){ 
    printf("the first element is %d \n",queue[fro]); 
}

int main(){
    enqueue(3);
    enqueue(54);
    enqueue(8);
    enqueue(36);
    enqueue(4);
    peek();
    dispaly();
    dequeue();
    dequeue();
        enqueue(7); // Add after dequeuing
    dispaly();
}