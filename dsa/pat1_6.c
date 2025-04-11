#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;

};
struct node* create(){
    int x;
    struct node* newnode=(struct node*)malloc(sizeof(node));
    printf("enter the dat and -1 for no new node\n");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    newnode->data=x;
    printf("enter the left child of the %d\n",x);
    newnode->left=create();
    printf("entert the right child of the %d\n",x);
    newnode->right=create();

    return newnode;
}

void preorder(struct node* root){
    if(root==0){
        return;
    }
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root){
    if(root==0){
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==0) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}
int main(){
    struct node* root;
    root=create(); 
    inorder(root);
    printf("\n the preorder is:");
    preorder(root);
    printf("\n now the post order one is: ");
    postorder(root);
}