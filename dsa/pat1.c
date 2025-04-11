#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to print the linked list
void printing(struct Node* head) {
    struct Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
        
    }
    printf("\n");
}

void searching(struct Node* head, int target){
    struct Node* curr=head;
    while(curr!= NULL){
        if(curr->data==target){
            
             
        curr=curr->next; printf("it is here \n");return; 
        }
        curr=curr->next; printf("it not is here \n");
}
}

struct Node* addf(struct Node* head,int val){
    struct Node* lol=newNode(val);
    lol->data=val;
    lol->next =head;
    // head=lol;
    return lol;
}

void addone(struct Node* head,int val){
    struct Node* lol=newNode(val);
    struct Node* curr=head;
    while(curr->next !=NULL){
        curr=curr->next;

    }
    curr->next=lol;

}
int main() {
    // Create nodes using the newNode function
    struct Node* head = newNode(34);
    struct Node* second = newNode(99);
    struct Node* third = newNode(58);
    struct Node* forth = newNode(88);
    struct Node* fifth = newNode(22);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;

    // Print the linked list
    printing(head);

   head= addf(head, 22);

    printing(head);

    return 0;
}
