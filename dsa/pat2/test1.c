#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* createlist(struct node* root,int val){

    struct node* curr=NULL;
    struct node* temp=root;
    int dex=0;
    for(int i=0;i<val;i++){
        scanf("%d",&dex);
        
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=dex;
        temp->link=NULL;
        if(root==NULL){
            root=temp;
            curr=temp;
        }else{
        curr->link=temp;
        curr=temp;
    }
    }
    
    return root;
}

struct node* push(struct node* head,int val){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->link=head;
    head=temp;
    return head;
}

int main(){
    int num;
    struct node* head=NULL;
    scanf("%d",&num);

    head=createlist(head,num);

    head= push(head,69);
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->link;
    }
    

}