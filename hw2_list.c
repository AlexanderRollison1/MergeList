//Alexander Rollison
//Credit some of the code to Donna French and Alexandra Stefan.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main()
{
	int choice;
	char filename[20];
	FILE *FH = NULL;
	char mode[2] = "r+";
	struct node *L1 = NULL;
	struct node *L2 = NULL;
	struct node *Sorted = NULL;
	
	do
	{
		PrintMenu(&choice, filename);
		
		switch(choice)
		{
			case 0:
				printf("Exiting. . .");
				destroy_list(L1);
				destroy_list(L2);
				break;
				
			case 1:
				FH = OpenFile(filename, mode);
				
				if(L1 != NULL ||L2 != NULL)
				{
					destroy_list(L1);
					destroy_list(L2);
				}
				
				LoadFile(FH, &L1, &L2);
				
				break;
				
			case 2:
				CheckSort(L1);
				CheckSort(L2);
				
				break;
				
			case 3:
				Sorted = MergeList(L1, L2);
				printf("\n\nPrinting Linked List 1 with memory address\n");
				DisplayList(L1);
				printf("\n\nPrinting Linked List 2 with memory address\n");
				DisplayList(L2);
				break;
				
			case 4:
				RemoveDuplicate(L1);
				RemoveDuplicate(L2);
				printf("\n\nPrinting Linked List 1 with memory address\n");
				DisplayList(L1);
				printf("\n\nPrinting Linked List 2 with memory address\n");
				DisplayList(L2);
				break;
				
			case 5:
				printf("\n\nPrinting Linked List 1\n");
				DisplayList1(L1);
				printf("\n\nPrinting Linked List 2\n");
				DisplayList1(L2);
				break;
				
			case 6:
				while(L1 != NULL && L2 != NULL)
				{
					destroy_list(L1);
					destroy_list(L2);
				}
				break;
				
			default:
				printf("\nInvalid input\n");
		}
	}
	while(choice != 0);
	return 0;
}


/*
Compilation instructions to run my code:
gcc .........
(or include a makefile)There is a makefile included.

I ran my code on:
- omega

My code runs with the input files (select what applies to you):
- Unix version (If omega is the unix version?) It runs with the windows text files that I enter, so both? I ran this on omega.
*/
