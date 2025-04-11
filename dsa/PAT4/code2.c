#include<stdio.h>
#include<stdlib.h>
int n;

struct node{
    int data;
    struct node* next;
};

void readgraph(int struct node* adj[]){
    struct node* newnode;
    int k,data;
    for(int i=0;i<n;i++){

        struct node* last=NULL;
        printf("no of adjacent to %d",i);
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("tell the neighbour");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=NULL;
            if(adj[j]==NULL){
                adj[j]=newnode;
            }
            else{
                last->next=newnode;
            }
            last=newnode;
        }
    }
}
void printGraph


int main(){
    printf("enter the no of vertices:");
    scanf("%d",&n);
    struct node *adj[n];

    for(int i=0;i<n;i++){
        adj[i]=NULL;
    }
    readgraph(adj);

}