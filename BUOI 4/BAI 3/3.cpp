#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int info;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

Node *CreateNode(int x);
void AddHead(List &L, Node *p);
void Xuat(List &L);
void Chuyen(List &L);
void CreateList(List &L);
void main()
{
	List L;
	CreateList(L);
	Chuyen(L);
	Xuat(L);
}
void CreateList(List &L)
{
	L.pHead= L.pTail = NULL;
}
void Chuyen(List &L)
{
	int n;
	Node *p;
	printf("Nhap so : ");
	scanf("%d",&n);
	if (n == 0)
	{
		p=CreateNode(n);
		AddHead(L,p);
	}
	while(n>0)
	{
		p=CreateNode(n%16);
		AddHead(L,p);
		n=n/16;
	}
}
void AddHead(List &L, Node *p)
{
	if (L.pHead==NULL)
		L.pHead=L.pTail=p;
	else
	{
		p->pNext = L.pHead;
		L.pHead = p;
	}
}

Node *CreateNode(int x)
{
	Node *p = new Node;
	if (p == NULL)
	{
		printf("Khong du bo nho");
		exit(0);
	}
	p->info = x;
	p->pNext = NULL;
	return p;
}

void Xuat(List &L)
{
	
		Node*p=L.pHead;
		while (p!=NULL)
		{
			if (p->info < 10)
				printf("%d",p->info);
			else
			{
				switch (p->info)
				{
				case 10:
					printf("A");
					break;
				case 11:
					printf("B");
					break;
				case 12:
					printf("C");
					break;
				case 13:
					printf("D");
					break;
				case 14:
					printf("E");
					break;
				case 15:
					printf("F");
					break;
				}
			}
			p=p->pNext;
		}
		printf("\n");
}


