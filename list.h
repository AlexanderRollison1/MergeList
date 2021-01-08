/* 
 * Updated 2/11/2020 - Alexandra Stefan
 */


#ifndef LIST_H
#define	LIST_H

struct node {
    int data;
    struct node * next;
};

void AddStart(struct node **LLH,int number);

void AddEnd(struct node *LLH, int number);

void DisplayList(struct node *LLH);

void DisplayList1(struct node *LLH);

int CountNodes(struct node *LLH);

void DeleteNode(struct node *LLH,int number);

void AddNode(struct node **LLH, int number);

void InsertNode(struct node **LLH, int number);

FILE* OpenFile(char filename[], char mode[]);

void LoadFile(FILE *filename,struct node **LLH1, struct node **LLH2);

void mklist(char index[],struct node **L1,struct node **L2, int count);

void destroy_list(struct node * LLH); 

void CheckSort(struct node *LLH);

struct node* MergeList(struct node *L1, struct node *L2);

void RemoveDuplicate(struct node *LLH);

void PrintMenu(int *choice, char UFile[]);

#endif	/* LIST_H */
