#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;

};

struct node* createnode(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));

    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insert(struct node* root,int val){
    if(root==NULL){
        return createnode(val);
    }
    if(val <root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

void preorder(struct node* root){
    if(root==NULL) return;

    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
    
}
void leafing(struct node* root){
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL){
        printf("%d ",root->data);
        return;
    }

    leafing(root->left);
    leafing(root->right);
}


int main(){
    int n;
    scanf("%d",&n);
    struct node* root=NULL;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        root= insert(root,temp);
    }

    preorder(root);
    printf("\n");
    leafing(root);
}
