#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	char Key;
	int Count;
	Node *pLeft;
	Node *pRight;
};
typedef struct Node NODE; 
typedef NODE *TREE; 

void CreateTree(TREE &T)
{
	T=NULL;
}

Node *CreateNode(char x);
int InsertNode(TREE &T, char x);
void CreateTree(TREE &T, char S[]);
void LNR(TREE T);

void main()
{
	TREE T;
	CreateTree(T);
	char S[100];
	printf("Nhap chuoi bat ki: ");
	gets(S);
	CreateTree(T,S);
	LNR(T);
}

void LNR(TREE T)
{
	if (T!=NULL)
	{
		LNR(T->pLeft);
		printf("%c : %d   \n",T->Key,T->Count);
		LNR(T->pRight);
	}
}

void CreateTree(TREE &T, char S[])
{
	InsertNode(T,S[0]);
	int t=strlen(S);
	for (int i = 1;i < t;i++)
	{
		InsertNode(T,S[i]);
	}
}

int InsertNode(TREE &T,char x)
{
	if (T!=NULL)
	{
		if (T->Key == x)
		{
			T->Count++;
			return 0;
		}
		if (T->Key > x)
			return InsertNode(T->pLeft, x);
		else
			return InsertNode(T->pRight, x);
	}
	else
	{
		Node *p = CreateNode(x);
		T=p;
		return 1;
	}
}

Node *CreateNode(char x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho");
		exit(0);
	}
	p->Key = x;
	p->Count = 1;
	p->pLeft = p->pRight = NULL;
	return p;
}

