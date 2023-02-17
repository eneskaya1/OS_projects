/*
 ============================================================================
 Name        : project.c
 Author      : Enes
 Version     :
 Copyright   : Your copyright notice
 Description : Memory Management Project
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define kb 1

// node structure defined to create a linked list
struct node {
	int startAddr;
	int finishAddr;
	struct node* next;
};
typedef struct node Node;

//function prototypes
void freeWithAddr (Node** root, int startAddr, int size);
void allocateWithAddr(Node** root, int startAddr, int size);
void allocateWithoutAddr (Node** root, int size);
int isEmpty ( Node* root );
void printList (Node* currentRoot);

int main(void) {

	Node* startRoot = NULL;		// there is no node initially (no memory available)

	// Test cases performed
	freeWithAddr(&startRoot, 900*kb, 5*kb);
	freeWithAddr(&startRoot, 26*kb, 3*kb);
	allocateWithAddr(&startRoot, 26*kb, 3*kb);
	freeWithAddr(&startRoot,3*kb, 1*kb);
	freeWithAddr(&startRoot, 17*kb, 1*kb);
	freeWithAddr(&startRoot, 920*kb, 10*kb);
	freeWithAddr(&startRoot,16*kb, 1*kb);
	freeWithAddr(&startRoot, 9*kb, 1*kb);
	freeWithAddr(&startRoot, 8*kb, 1*kb);
	freeWithAddr(&startRoot, 19* kb, 1*kb);
	freeWithAddr(&startRoot, 18*kb, 1*kb);
	freeWithAddr(&startRoot, 24*kb, 2*kb);
	freeWithAddr(&startRoot, 1*kb, 2*kb);
	freeWithAddr(&startRoot, 29*kb, 1*kb);
	allocateWithAddr(&startRoot, 2*kb, 1*kb);
	allocateWithAddr(&startRoot, 24*kb, 2*kb);
	allocateWithAddr(&startRoot, 18*kb, 1*kb);
	allocateWithAddr(&startRoot, 19*kb, 1*kb);
	allocateWithAddr(&startRoot, 8*kb, 1*kb);
	allocateWithAddr(&startRoot, 9*kb, 1*kb);
	allocateWithAddr(&startRoot, 16*kb, 1*kb);
	allocateWithAddr(&startRoot, 17*kb, 1*kb);
	freeWithAddr(&startRoot, 28*kb, 1*kb);
	freeWithAddr(&startRoot, 17*kb, 1*kb);
	freeWithAddr(&startRoot, 16*kb, 1*kb);
	freeWithAddr(&startRoot, 899*kb, 1*kb);
	freeWithAddr(&startRoot, 27*kb, 1*kb);
	freeWithAddr(&startRoot, 18*kb, 9*kb);
	allocateWithAddr(&startRoot, 15*kb, 5*kb);
	freeWithAddr(&startRoot, 30*kb, 50*kb);
	freeWithAddr(&startRoot, 17*kb, 1*kb);
	allocateWithAddr(&startRoot, 19*kb, 2*kb);
	allocateWithoutAddr(&startRoot, 1*kb);
	freeWithAddr(&startRoot, 90*kb, 17*kb);
	freeWithAddr(&startRoot, 18*kb, 2*kb);
	allocateWithoutAddr(&startRoot, 6*kb);
	freeWithAddr(&startRoot, 180*kb, 20*kb);
	freeWithAddr(&startRoot, 250*kb, 20*kb);
	freeWithAddr(&startRoot, 300*kb, 20*kb);
	allocateWithAddr(&startRoot, 29*kb, 3*kb);
	allocateWithoutAddr(&startRoot, 8*kb);
	allocateWithAddr(&startRoot, 303*kb, 17*kb);
	allocateWithoutAddr(&startRoot, 2*kb);
	allocateWithAddr(&startRoot, 92*kb, 15*kb);
	freeWithAddr(&startRoot, 303*kb, 20*kb);
	allocateWithoutAddr(&startRoot, 1*kb);
	freeWithAddr(&startRoot, 92*kb, 20*kb);
	allocateWithoutAddr(&startRoot, 25*kb);
	allocateWithoutAddr(&startRoot, 15*kb);
	allocateWithoutAddr(&startRoot, 22*kb);
	allocateWithoutAddr(&startRoot, 22*kb);
	allocateWithoutAddr(&startRoot, 22*kb);
	freeWithAddr(&startRoot, 25*kb, 7*kb);
	allocateWithAddr(&startRoot, 195*kb, 5*kb);
	allocateWithoutAddr(&startRoot, 1*kb);
	allocateWithoutAddr(&startRoot, 1*kb);
	freeWithAddr(&startRoot, 300*kb, 20*kb);
	allocateWithoutAddr(&startRoot, 7*kb);
	allocateWithoutAddr(&startRoot, 20*kb);
	allocateWithoutAddr(&startRoot, 20*kb);
	allocateWithoutAddr(&startRoot, 6*kb);
	allocateWithoutAddr(&startRoot, 2*kb);
	allocateWithoutAddr(&startRoot, 2*kb);
	freeWithAddr(&startRoot, 400*kb, 40*kb);
	freeWithAddr(&startRoot, 40*kb, 40*kb);
	freeWithAddr(&startRoot, 100*kb, 40*kb);
	allocateWithAddr(&startRoot, 100*kb, 5*kb);
	allocateWithAddr(&startRoot, 430*kb, 10*kb);
	allocateWithAddr(&startRoot, 70*kb, 10*kb);
	freeWithAddr(&startRoot, 430*kb, 40*kb);
	freeWithAddr(&startRoot, 70*kb, 20*kb);
	freeWithAddr(&startRoot, 950*kb, 40*kb);
	allocateWithAddr(&startRoot, 420*kb, 5*kb);
	allocateWithAddr(&startRoot, 950*kb, 5*kb);
	freeWithAddr(&startRoot, 95*kb, 5*kb);
	freeWithAddr(&startRoot, 330*kb, 40*kb);
	freeWithAddr(&startRoot, 480*kb, 40*kb);
	freeWithAddr(&startRoot, 90*kb, 4*kb);
	freeWithAddr(&startRoot, 140*kb, 40*kb);
	freeWithAddr(&startRoot, 990*kb, 40*kb);
	freeWithAddr(&startRoot, 94*kb, 1*kb);
	freeWithAddr(&startRoot, 370*kb, 30*kb);
	freeWithAddr(&startRoot, 520*kb, 435*kb);
	allocateWithAddr(&startRoot, 40*kb, 10*kb);
	allocateWithAddr(&startRoot, 322*kb, 10*kb);
	allocateWithAddr(&startRoot, 480*kb, 10*kb);
	allocateWithAddr(&startRoot, 490*kb, 540*kb);
	allocateWithAddr(&startRoot, 50*kb, 50*kb);
	allocateWithAddr(&startRoot, 110*kb, 20*kb);
	allocateWithAddr(&startRoot, 330*kb, 10*kb);
	allocateWithAddr(&startRoot, 350*kb, 10*kb);
	allocateWithAddr(&startRoot, 430*kb, 10*kb);

	return EXIT_SUCCESS;
}


void freeWithAddr(Node** root, int startAddr, int size) {
	if((*root) == NULL) {										// if there is no node, create one with the given inputs
		(*root) = (Node*)malloc(sizeof(Node));
		(*root)->next = NULL;
		(*root)->startAddr = startAddr;
		(*root)->finishAddr = startAddr + size;
	}
	else {														// there is one or more nodes
		if((*root)->startAddr > startAddr+size) {					// checking the left of the first node (memory to free is at the left)
			// add a new node pointing the root node
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->startAddr = startAddr;
			temp->finishAddr = startAddr + size;
			temp->next = (*root);
			(*root) = temp;												// added node is the new root
		}
		else if((*root)->startAddr == startAddr + size) {			// checking the left of the first node (memory to free is next to the root node)
			// extend the beginning of the memory
			(*root)->startAddr = startAddr;
		}
		else {														// checking the right of the iter node
			Node* iter = (*root);										//starting from the root node
			while(iter->next != NULL) {									// exit while loop when the end of the list reached
				if(iter->finishAddr <= startAddr && iter->next->startAddr >= startAddr+size) {
					break;												// exit while loop when memory to free is between the iter and iter->next
				}
				iter = iter->next;
			}


			if(iter->finishAddr == startAddr && iter->next != NULL) {
				if(iter->next->startAddr == startAddr + size) {			// if memory to free fits between the two nodes
					Node* temp = iter->next;
					iter->next = iter->next->next;
					iter->finishAddr = temp->finishAddr;
					free(temp);												// delete iter->next
				}
				else if (iter->next->startAddr > startAddr + size){		// if memory to free is next to the finish address of iter
					iter->finishAddr += size;								// update the finish address
				}
				else {
					// no operation
				}
			}
			else if(iter->finishAddr < startAddr  && iter->next != NULL) {
				if(iter->next->startAddr > startAddr + size) {			// if memory to free needs to be created between the two nodes (not fitting)
					Node* temp = (Node*)malloc(sizeof(Node));				// create a new node and update data
					temp->next = iter->next;
					iter->next = temp;
					temp->startAddr = startAddr;
					temp->finishAddr = startAddr + size;
				}
				else if(iter->next->startAddr == startAddr + size) {	// if memory to free is next to the start address of iter->next
					iter->next->startAddr = startAddr;						// update the start address
				}
				else {
					// no operation
				}
			}
			else if(iter->finishAddr == startAddr && iter->next == NULL){
				iter->finishAddr += size;
			}
			else if(iter->finishAddr < startAddr && iter->next == NULL) {
				Node* temp = (Node*)malloc(sizeof(Node));
				temp->next = NULL;
				iter->next = temp;
				temp->startAddr = startAddr;
				temp->finishAddr = startAddr + size;
			}
			else {
				// no operation
			}
		}
	}
	printf("freeWithAddr(&startRoot, %d*kb, %d*kb);\n", startAddr, size);
	printList((*root));													// print the linked list after the operation
}

void allocateWithAddr (Node** root, int startAddr, int size) {
	if(isEmpty((*root))) {																// there is no node
		// no memory to allocate
		// no operation!
	}
	else {
		if((*root)->next == NULL) {														// there is only one node
			if((*root)->startAddr <= startAddr && (*root)->finishAddr >= startAddr+size) {		// the range available to allocate
				if((*root)->startAddr == startAddr && (*root)->finishAddr == startAddr+size) {		// if memory to allocate fits the range
					free((*root));																		// delete the root node
				}
				else if((*root)->startAddr == startAddr && (*root)->finishAddr > startAddr+size) {	// if memory to allocate is next to the start address of the root node
					(*root)->startAddr = startAddr+size;												// update the start address
				}
				else if((*root)->startAddr < startAddr && (*root)->finishAddr == startAddr+size) {	// if memory to allocate is next to the finish address of the root node
					(*root)->finishAddr = startAddr;													// update the finish address
				}
				else {																				// if memory to allocate is in the middle
					Node* temp = (Node*)malloc(sizeof(Node));											// create a new node and update data
					temp->next = NULL;
					(*root)->next = temp;
					temp->startAddr = startAddr+size;
					temp->finishAddr = (*root)->finishAddr;
					(*root)->finishAddr = startAddr;
				}
			}
			else {
				// range is exceeded
				// no operation
			}
		}
		else {																			// there are more than one node
			if((*root)->startAddr <= startAddr && (*root)->finishAddr >= startAddr+size){		// check the root node first (the range available to allocate)
				if((*root)->startAddr == startAddr && (*root)->finishAddr == startAddr+size) {		// if memory to allocate fits the range
					Node* temp = (*root);
					(*root) = (*root)->next;														// update the root node
					free(temp);
				}
				else if((*root)->startAddr == startAddr && (*root)->finishAddr > startAddr+size) {	// if memory to allocate is next to the start address of the root node
					(*root)->startAddr = startAddr+size;												// update the start address
				}
				else if((*root)->startAddr < startAddr && (*root)->finishAddr == startAddr+size) {	// if memory to allocate is next to the finish address of the root node
					(*root)->finishAddr = startAddr;													// update the finish address
				}
				else {																				// if memory to allocate is in the middle of the root memory range
					Node* temp = (Node*)malloc(sizeof(Node));											// create a new node and update data
					temp->next = (*root)->next;
					(*root)->next = temp;
					temp->startAddr = startAddr+size;
					temp->finishAddr = (*root)->finishAddr;
					(*root)->finishAddr = startAddr;
				}
			}
			else {																				// start checking the nodes behind the root node
				Node* iter = (*root);
				while(iter->next->next != NULL) {													// exit while loop when the end of the list reached
					if(iter->next->startAddr <= startAddr && iter->next->finishAddr >= startAddr+size) {
						break;																		// exit while loop when memory to allocate is in the range of iter->next node
					}
					iter = iter->next;
				}
				if(iter->next->startAddr <= startAddr && iter->next->finishAddr >= startAddr+size) {		// the range available to allocate
					if(iter->next->startAddr == startAddr && iter->next->finishAddr == startAddr+size) {		// if memory to free fits the range
						Node* temp = iter->next;																	// iter->next will be deleted
						iter->next = iter->next->next;																// now iter points iter->next->next
						free(temp);
					}
					else if(iter->next->startAddr == startAddr && iter->next->finishAddr > startAddr+size) {	// if memory to allocate is next to the start address of iter->next
						iter->next->startAddr = startAddr+size;														// update the start address
					}
					else if(iter->next->startAddr < startAddr && iter->next->finishAddr == startAddr+size) {	// if memory to allocate is next to the finish address of iter->next
						iter->next->finishAddr = startAddr;															// update the finish address
					}
					else {																						// if memory to allocate is in the middle of the iter->next memory range
						Node* temp = (Node*)malloc(sizeof(Node));													// create a new node and update data
						temp->next = iter->next->next;
						iter->next->next = temp;
						temp->startAddr = startAddr+size;
						temp->finishAddr = iter->next->finishAddr;
						iter->next->finishAddr = startAddr;
					}
				}
				else {
					// no operation
				}
			}
		}
	}
	printf("allocateWithAddr(&startRoot, %d*kb, %d*kb);\n", startAddr, size);
	printList((*root));													// print the linked list after the operation
}

void allocateWithoutAddr (Node** root, int size) {
	//Node** temp_root = root;
	if(isEmpty((*root))) {													// there is no node
		// no memory to allocate
		// no operation!
	}
	else {
		if((*root)->next == NULL) {											// there is only one node
			if(((*root)->finishAddr - (*root)->startAddr) == size) {				// if memory to allocate fits the root memory range
				free((*root));															// delete the root node
			}
			else if(((*root)->finishAddr - (*root)->startAddr) > size) {			// if memory to allocate is smaller than the root memory range
				(*root)->startAddr += size;												// update the start address
			}
			else {																	// otherwise (the root memory range is not enough)
				// no memory to allocate
				// no operation!
			}
		}
		else {																// there are more than one node
			Node* bestFitNode = (Node*)malloc(sizeof(Node));
			bestFitNode = NULL;														// keeps the best-fit node for given input data
			int bestFitNodeFound = 0;												// true if the root memory range fits the memory to allocate
			int bestFitIndex = 0;													// keeps the index of the bestFitNode
			int countIndex = 1;														// counts the indexes in the linked list
			if(((*root)->finishAddr - (*root)->startAddr) >= size){				// if the root node has enough memory size
				bestFitIndex = countIndex;											// update bestFitIndex
				if(((*root)->finishAddr - (*root)->startAddr) == size) {			// if the root memory size is the same as the input size
					Node* temp = (*root);
					(*root) = (*root)->next;
					free(temp);															// delete the root node
					bestFitNodeFound = 1;													// root is definitely the bestFitNode
				}
				else {																// otherwise (the root memory size is bigger than the input size)
					bestFitNode = (*root);												// bestFitNode is the root node for now
				}
			}

			if(bestFitNodeFound) {													// if root is definitely the bestFitNode
				// best fit node is already found, no need to search for it anymore
				// no operation
			}
			else {																	// otherwise continue searching
				Node* iter = (*root);
				while(iter->next != NULL) {												// exit while loop when the end of the list reached
					countIndex++;															// increment the index counter
					if((iter->next->finishAddr - iter->next->startAddr) >= size) {			// if iter node has enough memory size
						if(bestFitNode == NULL) {												// if bestFitNode is null
							bestFitNode = iter->next;												// update bestFitNode
							bestFitIndex = countIndex;												// update bestFitIndex
						}
						else {																	// otherwise (there is a potential bestFitNode)
							if((iter->next->finishAddr - iter->next->startAddr) < (bestFitNode->finishAddr - bestFitNode->startAddr)) {	// if iter->next is the new bestFitNode
								bestFitNode = iter->next;											// update bestFitNode
								bestFitIndex = countIndex;											// update bestFitIndex
							}
							else {																										// otherwise
								// bestFitNode does not change
							}
						}
					}
					iter = iter->next;
				}
				if(bestFitIndex) {					// if a best fit node exists for input size
					Node* iter = (*root);
					int i=1;
					for(i=1; i<bestFitIndex-1; i++) {		// find the node pointing bestFitNode in the root linked list
						iter = iter->next;
					}

					if((iter->next->finishAddr - iter->next->startAddr) == size) {		// if bestFitNodeSize == size
						Node* temp = iter->next;
						iter->next = iter->next->next;
						free((temp));														// delete the bestFitNode from the linked list
					}
					else {																// otherwise (bestFitNodeSize > size)
						iter->next->startAddr += size;										// update the start address of the bestFitNode
					}
				} else {
					// best fit does not exist for memory size
					// no operation!
				}
			}
		}
	}
	printf("allocateWithoutAddr(&startRoot, %d*kb);\n", size);
	printList((*root));													// print the linked list after the operation
}

int isEmpty(Node* root) {
	return root == NULL;
}

void printList(Node* currentRoot) {
	//if startRoot == NULL
	if(isEmpty(currentRoot)) {
		puts("No memory to allocate!");
	}
	else {
		puts("Free Memory:");
		while(currentRoot != NULL) {
			printf("%dK-%dK\t", currentRoot->startAddr, currentRoot->finishAddr);
			currentRoot = currentRoot->next;
		}
		puts("\n---------------------------------------------------------------------------------------------------------------------"
						"----------------");
	}
}
