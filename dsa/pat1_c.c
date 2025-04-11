//the code for the queue in array linear
//
//
#include <stdio.h>

    int queue[5];
    int rar= -1,fro= -1;
void enqueue(int x){
        if(rar> 4)
            {
                printf("htis is overflow");
            
        }
        else if( rar==-1&&fro==-1){
            rar=0,fro=0;
            queue[rar]=x;
        }
        else{
            rar++;
            queue[rar]=x;
        }
    }
void dequeue(){
    if(rar==-1&&fro==-1){
        printf("the underflow error occured");

    }
    else if(fro==rar){
        rar=-1,fro=-1;
    }
    else{
        fro++;
        printf("the removed element is %d \n",queue[fro-1]);
    }

}

void dispaly(){
    for(int i=fro;i<=rar;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void peek(){
    printf("%d is the front val \n",queue[fro]);
}
int  main(){
    
    enqueue(3);
    enqueue(54);
    enqueue(98);
    peek();
    dispaly();
    dequeue();
    dequeue();
    dispaly();
    
}