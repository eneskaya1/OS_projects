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
void searchPath(TreeNodePtr treePtr, int path[], int data);
void printPath(int arr[], int len);

static int cnt = 0;

int main() {
    // Sample code to test the search tree functions
	TreeNodePtr treePtr = NULL;
	insert(&treePtr, 14);
	insert(&treePtr, 150);
	insert(&treePtr, 125);
	insert(&treePtr, 190);
	insert(&treePtr, 65);
	insert(&treePtr, 7);
	insert(&treePtr, 36);
	insert(&treePtr, 27);
	insert(&treePtr, 51);
	insert(&treePtr, 66);
	travInOrder(treePtr);
	//travPreOrder(treePtr);
	//travPostOrder(treePtr);
	findMax(treePtr);
	findMin(treePtr);

	int path[10];
	int data = 36;
	//printf("\nEnter a number to search in the tree: ");
	//scanf("%d", &data);
	searchPath(treePtr, path, data);
	data = 70;
	searchPath(treePtr, path, data);
	data = 66;
	searchPath(treePtr, path, data);

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
	printf("\nMin number in the tree: %d", treePtr->data);
}

void searchPath(TreeNodePtr treePtr, int path[], int data) {
	if(treePtr == NULL) {
		printf("Path to %d:\n", data);
		printf("Data not found!");
	}
	else {
		path[cnt] = treePtr->data;

		if(treePtr->data == data) {
			//no operation
			printf("\nPath to %d:\n", data);
			printPath(path, cnt+1);
			cnt = 0;
		}
		else if(data < treePtr->data) {
			cnt++;
			searchPath(treePtr->leftPtr, path, data);
		}
		else {
			// (data > treePtr->data)
			cnt++;
			searchPath(treePtr->rightPtr, path, data);
		}
	}
}

void printPath(int arr[], int len) {
	printf("%d", arr[0]);
	int k;
	for(k=1; k<len; k++)
	{
		printf("->%d", arr[k]);
	}
	printf("%s", "\n");
}
