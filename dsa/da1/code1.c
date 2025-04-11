#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

typedef TreeNode DLLNode;

DLLNode* treeToDoublyList(TreeNode* root) {
    if (root == NULL) return NULL;

    DLLNode *head = NULL, *prev = NULL;
    TreeNode* stack[100];
    int top = -1;
    TreeNode* curr = root;

    while (curr != NULL || top != -1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left;
        }

        curr = stack[top--];
        DLLNode* dllNode = curr;

        if (prev == NULL) {
            head = dllNode;
        } else {
            prev->right = dllNode;
            dllNode->left = prev;
        }

        prev = dllNode;
        curr = curr->right;
    }

    return head;
}

void printDoublyLinkedList(DLLNode* head) {
    DLLNode* curr = head;
    while (curr != NULL) {
        printf("%d", curr->val);
        if (curr->right != NULL) {
            printf(" <-> ");
        }
        curr = curr->right;
    }
    printf("\n");
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Creating the binary tree:
    TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);

    // Convert to doubly linked list
    DLLNode* head = treeToDoublyList(root);

    // Print the result
    printDoublyLinkedList(head);
    
    return 0;
}
