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
void DelNode(List &L);
void SapXep(List &L);
void AddNode(List &L);
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
		printf("7.Thoat\n");
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
			DelNode(L);
			xuat(L);
			printf("\nEnter de tiep tu!!!\n");
			system("pause");system("cls");goto Menu;
		case 6:
			SapXep(L);
			xuat(L);
			printf("\n");
			printf("\nEnter de tiep tu!!!\n");
			system("pause");system("cls");
			xuat(L);
			printf("\nChen nut Bang X vao DSLK\n");
			printf("0.Tro lai\n");
			printf("1.Tiep tuc\n");
			printf("Lua Chon : ");
			scanf("%d",&i);
			switch(i)
			{
			case 0:
				printf("\nEnter de tiep tu!!!\n");
				system("cls");goto Menu;
			case 1:
				AddNode(L);
				xuat(L);
				printf("\nEnter de tiep tu!!!\n");
				system("pause");system("cls");goto Menu;
			}
		case 7:exit(0);
		}
	}
}
void AddNode(List &L)
{
	int x;
	printf("\nNhap X : ");
	scanf("%d",&x);
	Node*p=CreateNode(x);
	if(L.pHead==NULL)
		return;
	if(L.pHead->info>x)
	{
		AddHead(L,p);
		return;
	}
	if(L.pTail->info<x)
	{
		AddTail(L,p);
		return;
	}
	int k=0;
	for(Node*l=L.pHead;l!=NULL;l=l->pNext)
	{
		if(l->info<x)
			k++;
		else
		{
			k++;
			break;
		}
	}
	Node*q=new Node;
	Node*w=new Node;
	Node*r=L.pHead;
	int dem=0;
	while(r!=NULL)
	{
		dem++;
		q=r;
		if(dem==k)
			break;
		else
			r=r->pNext;
	}
	w=L.pHead;
	while(w->pNext!=q)
		w=w->pNext;
	w->pNext=p;
	p->pNext=r;
}
void SapXep(List &L)
{
	Node *p,*q;
	for(p=L.pHead;p!=L.pTail;p=p->pNext)
	{
		Node *min=p;
		for(q=p->pNext;q!=NULL;q=q->pNext)
			if(q->info<min->info)
				min=q;
		int tmp=p->info;
		p->info=min->info;
		min->info=tmp;
	}
}
void DelNode(List &L)
{
	int x;
	printf("Nhap X : ");
	scanf("%d",&x);
	if(L.pHead==NULL)
		return;
	if(L.pHead->info==x)
	{
		RemoveHead(L);
		return;
	}
	if(L.pTail->info==x)
	{
		RemoveTail(L);
		return;
	}
	Node*q=new Node;
	for(Node*p=L.pHead;p!=NULL;p=p->pNext)
	{
		if(p->info==x)
		{
			q->pNext=p->pNext;
			delete p;
			return;
		}
		q=p;
	}
	printf("\nX khong co trong DSLK\n");
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
