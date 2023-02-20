/*
 ============================================================================
 Name        : binary_search_tree.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode *leftPtr, *rightPtr;
};
typedef struct treeNode TreeNode;
typedef TreeNode* TreeNodePtr;

// prototypes
void insert(TreeNodePtr* treePtr, int data);
void travInOrder(TreeNodePtr treePtr);
void travPreOrder(TreeNodePtr treePtr);
void travPostOrder(TreeNodePtr treePtr);
void findMax(TreeNodePtr treePtr);
void findMin(TreeNodePtr treePtr);

int main() {
    // Sample code to test the search tree functions
	TreeNodePtr treePtr = NULL;
	insert(&treePtr, 12);
	insert(&treePtr, 200);
	insert(&treePtr, 190);
	insert(&treePtr, 213);
	insert(&treePtr, 56);
	insert(&treePtr, 10);
	insert(&treePtr, 24);
	insert(&treePtr, 18);
	insert(&treePtr, 27);
	insert(&treePtr, 28);
	travInOrder(treePtr);
	//travPreOrder(treePtr);
	//travPostOrder(treePtr);
	findMax(treePtr);
	findMin(treePtr);

    return 0;
}

void insert(TreeNodePtr* treePtr, int data) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TreeNode));
        (*treePtr)->data = data;
        (*treePtr)->leftPtr = NULL;
        (*treePtr)->rightPtr = NULL;
    }
    else {
        if(data < (*treePtr)->data)
            insert(&((*treePtr)->leftPtr), data);
        else if(data > (*treePtr)->data)
            insert(&((*treePtr)->rightPtr), data);
        else
            printf("%s", "Duplicate value, no operation.");
    }
}

// Left - Node - Right ****** OR ****** Right - Node - Left
void travInOrder(TreeNodePtr treePtr) {
	// if tree is not empty
	if(treePtr != NULL) {
		travInOrder(treePtr->leftPtr);
		printf("%d ", treePtr->data);
		travInOrder(treePtr->rightPtr);
	}
}

// Node - Left - Right ****** OR ****** Node - Right - Left
void travPreOrder(TreeNodePtr treePtr) {
	// if tree is not empty
	if(treePtr != NULL) {
		printf("%d ", treePtr->data);
		travPreOrder(treePtr->leftPtr);
		travPreOrder(treePtr->rightPtr);
	}
}

// Left - Right - Node ****** OR ****** Right - Left - Node
void travPostOrder(TreeNodePtr treePtr) {
	// if tree is not empty
	if(treePtr != NULL) {
		travPostOrder(treePtr->leftPtr);
		travPostOrder(treePtr->rightPtr);
		printf("%d ", treePtr->data);
	}
}


void findMax(TreeNodePtr treePtr) {
	while(treePtr->rightPtr != NULL) {
		treePtr = treePtr->rightPtr;
	}
	printf("\nMax number in the tree: %d", treePtr->data);
}

void findMin(TreeNodePtr treePtr) {
	while(treePtr->leftPtr != NULL) {
		treePtr = treePtr->leftPtr;
	}
	printf("\nMax number in the tree: %d", treePtr->data);
}

