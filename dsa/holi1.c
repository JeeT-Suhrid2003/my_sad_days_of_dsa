#include<stdio.h>
#include <cstdlib>

struct node{
    int data;
    struct node *next;
};
void linked(struct node *ptr){
    while(ptr!=NULL){
    printf("%d \n",ptr->data);
    ptr=ptr->next;
     }
}

struct node* addone(struct node *head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
struct node * inbet(struct node *head , int data,int index){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;

    int count=0;
    while(count!=index-1){
        p=p->next;
        count++;

    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}
struct node * ending(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node* deleting(struct node *head){
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct node *delbet(struct node *head,int index){
    struct node *ptr=head;
    int count=0;

    while(count!=index-1){
        ptr=ptr->next;
        count++;
    }
        struct node *p;
        p=ptr->next;
        ptr->next=p->next;
        free(p);


    return head;
}

int main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *forth;
    struct node *fifth;
    
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));
    fifth=(struct node*)malloc(sizeof(struct node));

    head->data=34;
    head->next=second;

    second->data=99;
    second->next=third;
    third->data=58;
    third->next=forth;

    forth->data=88;
    forth->next=fifth;

    fifth->data=22;
    fifth->next=NULL;

    linked(head);
    printf("%d \n",head->next->data);
    head=delbet(head,2);
    linked(head);

    return 0;
}