#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	Node*pNext;
};
struct List
{
	Node*pHead;
	Node*pTail;
};
Node*CreateNode(int x);
void CreateList(List &L);
void Nhap(int &n);
void Luu(List &L,int n);
void AddHead(List &L,Node *p);
void Xuat(List L);
void main()
{
	List L;
	int n;
	CreateList(L);
	Nhap(n);
	Luu(L,n);
	Xuat(L);
}
void Xuat(List L)
{
	for(Node*p=L.pHead;p!=NULL;p=p->pNext)
		printf("%d",p->info);
}
void Luu(List &L,int n)
{
	int x;
	while(n>0)
	{
		x=n%2;
		Node*p=CreateNode(x);
		AddHead(L,p);
		n=n/2;
	}
}
void AddHead(List &L,Node *p)
{
	if(L.pHead==NULL)
	{
		L.pHead=p;
		L.pTail=p;
	}
	else
	{
		p->pNext=L.pHead;
		L.pHead=p;
		
	}
}
void Nhap(int &n)
{
	printf("\nNhap So he 10 : ");
	scanf("%d",&n);
}
Node*CreateNode(int x)
{
	Node*p=new Node;
	if(p==NULL)
		exit(0);
	p->info=x;
	p->pNext=NULL;
	return p;
};
void CreateList(List &L)
{
	L.pHead=NULL;
	L.pTail=NULL;
}