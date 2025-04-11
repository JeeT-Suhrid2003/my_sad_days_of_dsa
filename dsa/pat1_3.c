//the code for the linked list queue and this is linea but no case for error
//
//


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    Node* next;
};
struct Node* front=0;
struct Node* rare=0;

void enqueue(int val){
    struct Node* newnode= (struct Node*)malloc(sizeof(struct Node));
    newnode->data=val;
    newnode->next=0;

    if(front==0&&rare==0){
        front=newnode,rare=newnode;
    }
    else{
        rare->next=newnode;
        rare=newnode;
    }
}

void dequeue(){
    struct Node* temp;
    temp=front;
    front=front->next;
    free(temp);

}
void peek(){
    printf("%d",front->data);
}
void display(){
    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d " ,temp->data);
        temp=temp->next;
    }

}

int main(){
    enqueue(43);
    enqueue(41);
    enqueue(67);
    display();
}