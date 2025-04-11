#include<stdio.h>
#include <cstdlib>
struct node{
    int data;
    struct node *link;
};
struct node* top=0;
void push(int data){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->link=top;
    top=newnode;
}
void disp(){
    struct node*temp;
    temp=top;
    if(top==0){
        printf("there was nothing");
    }
    else{
        printf("the display: \n");
        while(temp!=0){
            printf("%d ",temp->data);
            temp=temp->link;
        }
    }
}
void peek(){
    top==0 ? printf("there was nothing") : printf("the peek is %d",top->data);
}
void pop(){
    struct node* temp;
    temp=top;
    if(top==0){
        printf("there was nothing");
    }
    else{
        printf("the removed top: %d",top->data);
        top=top->link;
            //free(temp);

    }

}

int main(){
    push(49);
    push(2);
    push(43);
    disp();
    pop();
    disp();
    pop();
    peek();
    disp();
    return 0;
}