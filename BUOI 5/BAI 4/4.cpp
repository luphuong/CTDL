#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	Node*pNext;
};
struct QUEUE
{
	Node*Front;
	Node*Rear;
	int Count;
};
void CreateQueue(QUEUE &Q);
Node*CreateNode(int x);
void main()
{
	QUEUE Q;
	CreateQueue(Q);
	Menu(Q);
}
void Menu(QUEUE Q)
{
	Nhap(Q);
	Xuat(Q);
}
void Nhap(QUEUE &Q)
{
}
Node*CreateNode(int x)
{
	Node*p=new Node;
	if(p==NULL)
		exit(0);
	p->info=x;
	p->pNext=NULL;
	return p;
}
void CreateQueue(QUEUE &Q)
{
	Q.Front=NULL;
	Q.Rear=NULL;
	Q.Count=0;
}