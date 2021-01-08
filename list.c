
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

void AddStart(struct node **LLH,int number)
{
	struct node *new_node;
	
	new_node = malloc(sizeof(struct node));
	new_node->data = number;
	new_node->next = NULL;
	
	if(*LLH == NULL)
	{
		*LLH = new_node;
	}
}

void AddEnd(struct node *LLH, int number)
{
	struct node *tempPtr;
	struct node *new_node;
	
	new_node = malloc(sizeof(struct node));
	new_node->data = number;
	new_node->next = NULL;
	
	tempPtr = LLH;
	
	while(tempPtr->next != NULL)
	{
		tempPtr = tempPtr->next;
	}
	tempPtr->next = new_node;
}

void DisplayList(struct node *LLH)
{
	
	struct node *tempPtr;
	tempPtr = LLH;
	
	while (tempPtr != NULL)
	{
		printf("\nNode Number: %d\nNode address %p ---- Node's next ptr %p\n", tempPtr->data, tempPtr, tempPtr->next);
		tempPtr = tempPtr->next;
	}
	printf("\n\n");
}

void DisplayList1(struct node *LLH)
{
	
	struct node *tempPtr;
	tempPtr = LLH;
	
	while (tempPtr != NULL)
	{
		printf("\nNode Number: %d\nNode address %p\n", tempPtr->data, tempPtr);
		tempPtr = tempPtr->next;
	}
	printf("\n\n");
}

int CountNodes(struct node *LLH)
{
	struct node *tempPtr;
	int counter = 0;
	tempPtr = LLH;
	
	while (tempPtr != NULL)
	{
		tempPtr = tempPtr->next;
		counter++;
	}
	return counter;
}

void DeleteNode(struct node *LLH,int number)
{
	struct node *tempPtr = LLH; 
	struct node *PrevPtr = NULL;
	
	while (tempPtr->next != NULL && tempPtr->data != number)
	{
		PrevPtr = tempPtr;
		tempPtr = tempPtr->next;
	}
	if (tempPtr->data == number)
	{
		if (tempPtr == LLH)
		{
			LLH = tempPtr->next;
		}
		else
		{
			PrevPtr->next = tempPtr->next;
		}
		free(tempPtr);
	}
	else
	{
		printf("");
	}
}

void AddNode(struct node **LLH, int number)
{
	struct node *tempPtr;
	struct node *new_node;
	
	new_node = malloc(sizeof(struct node));
	new_node->data = number;
	new_node->next = NULL;
	
	if(*LLH == NULL)
	{
		*LLH = new_node;
	}
	else
	{
		tempPtr = *LLH;
		
		while(tempPtr->next != NULL)
		{
			tempPtr = tempPtr->next;
		}
		tempPtr->next = new_node;
	}
}

void InsertNode(struct node **LLH, int number)
{
	struct node * TempPtr = *LLH; 
	struct node * NewNode = malloc(sizeof(struct node));
	NewNode->data = number;
	NewNode->next = TempPtr;
	struct node * PrevPtr = NULL;
	
	while(TempPtr != NULL && TempPtr->data < number)
	{
		PrevPtr = TempPtr; 
		TempPtr = TempPtr->next;
	}
	if(PrevPtr == NULL)
	{
		*LLH == NewNode;
	}
	else 
	{
		PrevPtr->next = NewNode;
	}

}

FILE* OpenFile(char filename[], char mode[])
{
	FILE* FH = NULL;
	FH = fopen(filename,mode);
	char UFile[100];
	while(FH == NULL)
	{
		printf("\nA File you entered does not exist. Enter valid filename: ");
		scanf("%s", UFile);
		getchar();
		
		FH = fopen(UFile,mode);
	}
	return FH;
}

void LoadFile(FILE *filename,struct node **LLH1, struct node **LLH2)
{
	char index[100];
	int i;
	int w;
	int x;
	char *token;
	int size;
	int *nums;
	
	// L1
	for(i = 0; i < 2; i++)
	{
		struct node *list;
		int value;
		
		fgets(index,100,filename);
		size = atoi(strtok(index," "));
		nums = malloc(sizeof(int) *size);
		for(x = 0; x<size; x++)
		{
			token = strtok(NULL, " ");
			
			nums[x] = atoi(token);
		}
		
		if(i == 0)
		{
			for(w = 0; w < size; w++)
			{
				if(w == 0)
				{
					AddStart(LLH1,nums[w]);
				}
				else
				{
					AddNode(LLH1,nums[w]);
				}
			}
		}
		else if(i == 1)
		{
			for(w = 0; w < size; w++)
			{
				if(w == 0)
				{
					AddStart(LLH2,nums[w]);
				}
				else
				{
					AddNode(LLH2,nums[w]);
				}
			}
		}
		else
		{
			printf("");
		}
	}
	
	/*char index[100];
	int count = 0;
	
	while(fgets(index, sizeof(index)-1,filename))
	{
		if(index[strlen(index)-1] == '\n')
		{
			index[strlen(index)-1] = '\0';
		}
		mklist(index,LLH1,LLH2,count);
		count++;
	}
	*/
	fclose(filename);
}

void mklist(char index[],struct node **L1,struct node **L2, int count)
{
	int i;
	int size1;
	int size2;
	if(count == 0)
	{
		size1 = (int)index[0];
		for(i = 0; i <5; i+2)
		{
			AddNode(L1, (int)index[i+1]);
			DisplayList(*L1);
		}
	}
	else if(count == 1)
	{
		size2 = (int)index[0];
		
		for(i = 0; i <size2; i++)
		{
			AddNode(L2, (int)index[i+1]);
		}
	}
		
}

void destroy_list(struct node * LLH) 
{
	struct node * tempPtr = LLH;
    struct node * temp;
	
    while (tempPtr != NULL) {
    struct node* temp = tempPtr;
    tempPtr = tempPtr->next; 
    free(temp);
    }    
	
	/*
	while(tempPtr!=NULL){ 
                struct node* temp = tempPtr;
                tempPtr = tempPtr->next; 
                free(temp); 
        }
	*/
}

void CheckSort(struct node *LLH)
{
	struct node *m;
	struct node *n;
	m = LLH;
	int temp;
	
	//starting sort
	for(m = LLH; (m != NULL); m = m->next)
	{
		for(n = m->next; (n != NULL); n = n->next)
		{
			if(m->data > n->data)
			{
				temp = m->data;
				m->data = n->data;
				n->data = temp;
			}
		}
	}
}

struct node* MergeList(struct node *L1, struct node *L2)
{
	
	if(L1 == NULL)
	{
		return L2;
	}
	if(L2 == NULL)
	{
		return L1;
	}
	
	struct node *tempPtr;
	
	tempPtr = L1;
	
	while(tempPtr->next != NULL)
	{
		tempPtr = tempPtr->next;
	}
	tempPtr->next = L2;
    return tempPtr;
    
}

void RemoveDuplicate(struct node *LLH)
{
	CheckSort(LLH);
	
	struct node *current = LLH;
	struct node *tempPtr;
	
	if(current == NULL)
		return;
	
	while(current->next !=NULL)
	{
		if(current->data == current->next->data)
		{
			tempPtr = current->next->next;
			free(current->next);
			current->next = tempPtr;
		}
		else
		{
			current = current->next;
		}
	}
}

void PrintMenu(int *choice, char UFile[])
{
	printf(" 1 - load from file. It will read from file and create 2 linked lists, L1 and L2. If L1 and L2 exist, they are first destroyed and then they are recreated with data from the file  .");
	printf("\n 2 - check that list L1 is sorted in increasing order.");
	printf("\n 3 - merge L1 with L2 and print the resulting list, L1. The result list will be referenced from variable L1. It should check that BOTH lists are sorted in increasing order in order for the merge to work.");
	printf("\n 4 - remove duplicates from L1. (this method will assumes L1 is sorted in increasing order.)");
	printf("\n 5 - print lists L1 and L2.");
	printf("\n 6 - destroy L1 and L2 (and free the memory). If L1 and L2 are NULL it should not crash.");
	printf("\n 0 - exit.");
	
	printf("\n Enter your choice (1-6): ");
	scanf("%d", choice);
	
	if(*choice != 0 && *choice == 1)
	{
		printf("\nEnter the name of the file with data: ");
		scanf("%s", UFile);
	}
}

