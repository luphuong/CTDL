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
void CreateList(List &L);
void nhap(List &L);
Node* CreateNode(int x);
void AddTail(List &L,Node *p);
void xuat(List &L);
void Menu(List L);
void AddHead(List &L,Node *p);
void ThemNodeHead(List &L,Node*p);
void ThemNodeTail(List &L,Node*p);
void DemNode(List L);
void FindX(List L);
void RemoveHead(List &L);
void RemoveTail(List &L);
void RemoveNode(List &L);
void Remove(List &L,Node *&p,int x);
void main()
{
	List L;
	CreateList(L);
	Menu(L);
}
void Menu(List L)
{
	nhap(L);
	int k,i;
	Node*p=new Node;
Menu:
	printf("\n");
	xuat(L);
	while(k)
	{
		printf("\n1.Them nut vao dau DS hoac vao cuoi DSLK\n");
		printf("2.Dem so nut trong DSLK don\n");
		printf("3.Tim mot nut co thanh phan du lieu bang X\n");
		printf("4.Xoa mot nut dau hoac cuoi DSLK don\n");
		printf("5.Xoa nut co du lieu bang X\n");
		printf("6.Sap xep danh sach lien ket don theo chieu tang dan\n");
		printf("7.Chen nut co du lieu Bang X,sao cho danh sach van tang\n");
		printf("8.Thoat\n");
		printf("Lua Chon : ");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			printf("\n1.Them nut vao dau danh sach\n");
			printf("2.Them nut vao cuoi danh sach\n");
			printf("Lua Chon : ");
			scanf("%d",&i);
			switch(i)
			{
			case 1:
				ThemNodeHead(L,p);
				xuat(L);
				printf("\nEnter de tiep tu!!!\n");
				system("pause");system("cls");goto Menu;
			case 2:
				ThemNodeTail(L,p);
				xuat(L);
				printf("\nEnter de tiep tu!!!\n");
				system("pause");system("cls");goto Menu;
			}
		case 2:
			DemNode(L);
			printf("\nEnter de tiep tu!!!\n");
			system("pause");system("cls");goto Menu;
		case 3:
			FindX(L);
			printf("\nEnter de tiep tu!!!\n");
			system("pause");system("cls");goto Menu;
		case 4:
			printf("\n1.Xoa nut dau DSLK\n");
			printf("2.Xoa nut cuoi DSLK\n");
			printf("Lua chon : ");
			scanf("%d",&i);
			switch(i)
			{
			case 1:
				RemoveHead(L);
				xuat(L);
				printf("\nEnter de tiep tu!!!\n");
			    system("pause");system("cls");goto Menu;
			case 2:
				RemoveTail(L);
				xuat(L);
				printf("\nEnter de tiep tu!!!\n");
			    system("pause");system("cls");goto Menu;
			}
		case 5:
			RemoveNode(L);
			xuat(L);
			printf("\nEnter de tiep tu!!!\n");
			system("pause");system("cls");goto Menu;
		case 8:exit(0);
		}
	}
}
void RemoveNode(List &L)
{
	Node*p=new Node;
	int x;
	printf("Nhap X : ");
	scanf("%d",&x);
	for(p=L.pHead;p!=NULL;p=p->pNext)
	{
		if(p->info==x)
			Remove(L,p,x);
	}
}
void Remove(List &L,Node *&phead,int x)
{
	Node *virtualnode=new Node;
     virtualnode->pNext=phead;
     phead=virtualnode;
     Node *q;
     for(Node *p=phead;p->pNext!=NULL;p=p->pNext)
	 {
             if(p->pNext->info==x)
             {
                 q=p->pNext; 
                 p->pNext=q->pNext;
                 delete q;
             }
	 }
     phead=phead->pNext;
     delete virtualnode;
}
void RemoveTail(List &L)
{
	Node*p=L.pHead;
	if(p!=NULL)
	{ 
		Node*q=L.pTail;
		if(L.pTail==L.pHead)
			L.pHead=L.pTail=NULL;
		else
		{
			for(p=L.pHead;p->pNext!=L.pTail;p=p->pNext);
			p->pNext=NULL;
			L.pTail=p;
		}
		delete q;
	}
	else
		printf("\nKhong xoa duoc\n");
}
void RemoveHead(List &L)
{
	Node*p=L.pHead;
	if(p!=NULL)
	{ 
		L.pHead=L.pHead->pNext;
		delete p;;
		if(L.pHead==NULL)
			L.pTail=NULL;
	}
	else
		printf("\nKhong xoa duoc\n");
}
void FindX(List L)
{
	int n;
	int vt=-1;
	int i=1;
	Node*p;
	printf("Nhap X : ");
	scanf("%d",&n);
	for(p=L.pHead;p!=NULL;p=p->pNext,i++)
	{
		if(p->info==n)
		{
			vt=i;
			break;
		}
	}
	if(vt!=-1)
		printf("Tim thay nut bang X tai vi tri thu %d\n",vt);
	else
		printf("Khong tim thay nut bang X\n");
}
void DemNode(List L)
{
	Node*p;
	int dem=0;
	for(p=L.pHead;p!=NULL;p=p->pNext)
		dem++;
	printf("So nut trong DSLK don la %d\n",dem);
}
void ThemNodeHead(List &L,Node*p)
{
	int x;
	printf("\nNhap X : ");
	scanf("%d",&x);
		if(x>=0)
		{
			p=CreateNode(x);
			AddHead(L,p);
		}
		else
		{
			printf("Ket Thuc\n");
			exit(0);
		}
}
void ThemNodeTail(List &L,Node*p)
{
	int x;
	printf("\nNhap X : ");
	scanf("%d",&x);
		if(x>=0)
		{
			p=CreateNode(x);
			AddTail(L,p);
		}
		else
		{
			printf("Ket Thuc\n");
			exit(0);
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
void xuat(List &L)
{
	Node *p=L.pHead;
	while(p!=NULL)
	{
		printf("%2d ",p->info);
		p=p->pNext;
	}
}
void nhap(List &L)
{
	int n,x;
	Node*p=new Node;
	printf("Nhap So Phan Tu : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Phan Tu Thu %d : ",i+1);
		scanf("%d",&x);
		if(x>=0)
		{
			p=CreateNode(x);
			AddTail(L,p);
		}
		else
		{
			printf("Ket Thuc\n");
			exit(0);
		}
	}
}
void AddTail(List &L,Node *p)
{
	if(L.pHead==NULL)
	{
		L.pHead=p;
		L.pTail=p;
	}
	else
	{
		L.pTail->pNext=p;
		L.pTail=p;
	}
}
Node* CreateNode(int x)
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
