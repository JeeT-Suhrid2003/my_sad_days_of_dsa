#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createn(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int val){
    if(root==NULL) return createn(val);

    if(root->data>val){
        root->left= insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

void levelorder(struct node* root){
    if(root==NULL) return;

    struct node* queue[100];

    int front=0,rear=0;

    queue[rear++]=root;
    while(rear>front){
        struct node* curr=queue[front++];
        printf("%d ",curr->data);

        if(curr->left!=NULL){
            queue[rear++]=curr->left;
        }
        if(curr->right!=NULL){
            queue[rear++]=curr->right;
        }
        
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int temp;
    struct node* root=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        root= insert(root,temp);

    }

    levelorder(root);
}