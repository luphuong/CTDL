#include<stdio.h>
#include<stdlib.h>
#define hung 100

struct Node
{
	int Key;
	int vitri;
	Node *pNext;
};

struct List
{
	Node *pHead;
	Node *pTail;
};

Node *CreateNode(int x, int vitri);
void Nhap(int A[][hung], int m, int n);
void NhapMaTran(int A[][hung], int B[][hung], int &m, int &n);
void DuyetDS(List L);
void AddTail(List &L, Node*p);
void NhapList(List &L,int A[][hung],int m,int n);
Node *KiemTra(Node *p, List L);
List CongMaTran(List L1, List L2);
List TruMaTran(List L1, List L2);
void Xuat(List L,int m,int n);
void CreateList(List &L);

void main()
{
	int A[hung][hung],B[hung][hung];
	int m,n;
	NhapMaTran(A,B,m,n);
	List L1,L2,Lt,Lh;
	CreateList(L1);
    CreateList(L2);
	NhapList(L1,A,m,n);
	NhapList(L2,B,m,n);

	Lt = CongMaTran(L1,L2);
	printf("Tong 2 ma tran: \n");
	Xuat(Lt,m,n);
	Lh=TruMaTran(L1,L2);
	printf("Hieu 2 ma tran: \n");
	Xuat(Lh,m,n);

}
void CreateList(List &L)
{
	L.pHead = L.pTail = NULL;
}

void Xuat(List L,int m,int n)
{
	int A[hung] = {0};
	int B[hung][hung];
	int nA=0;
	Node *p=L.pHead;
	while(p!=NULL)
	{
		A[p->vitri]=p->Key;
		p=p->pNext;
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			B[i][j] = A[nA++];
			printf("%d ",B[i][j]);
		}
		printf("\n");
	}
}

List TruMaTran(List L1,List L2)
{
	List L;
	L.pHead=L.pTail=NULL;

	Node *p=L1.pHead;
	Node *q=L2.pHead;
	Node *k=new Node;
	while(p!=NULL)
	{
		if(KiemTra(p,L2)==NULL)
		{
			k=CreateNode(p->Key,p->vitri);
			AddTail(L,k);
		}
		p=p->pNext;
	}
	while(q!=NULL)
	{
		if(KiemTra(q,L1)==NULL)
		{
			k=CreateNode(0-q->Key,q->vitri);
			AddTail(L,k);
		}
		q=q->pNext;
	}
	p=L1.pHead;
	while(p!=NULL)
	{
		if(KiemTra(p,L2)!=NULL)
		{
			q=KiemTra(p,L2);
			k=CreateNode(p->Key-q->Key,p->vitri);
			AddTail(L,k);
		}
		p=p->pNext;
	}
	return L;
}

List CongMaTran(List L1,List L2)
{
	List L;
	L.pHead=L.pTail=NULL;

	Node *p=L1.pHead;
	Node *q=L2.pHead;
	Node *k=new Node;
	while(p!=NULL)
	{
		if(KiemTra(p,L2)==NULL)
		{
			k=CreateNode(p->Key,p->vitri);
			AddTail(L,k);
		}
		p=p->pNext;
	}
	while(q!=NULL)
	{
		if (KiemTra(q,L1)==NULL)
		{
			k=CreateNode(q->Key,q->vitri);
			AddTail(L,k);
		}
		q=q->pNext;
	}
	p=L1.pHead;
	while(p!=NULL)
	{
		if(KiemTra(p,L2)!=NULL)
		{
			q=KiemTra(p,L2);
			k=CreateNode(p->Key+q->Key,p->vitri);
			AddTail(L,k);
		}
		p=p->pNext;
	}
	return L;
}

Node *KiemTra(Node *p,List L)
{
	Node *q=L.pHead;
	while(q!=NULL)
	{
		if(q->vitri==p->vitri)
			return q;
		q=q->pNext;
	}
	return NULL;
}

void NhapList(List &L,int A[][hung],int m,int n)
{
	int C[hung];
	int nC=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			C[nC++]=A[i][j];

	for(int k=0;k<m*n;k++)
		if (C[k]!=0)
		{
			Node *p=CreateNode(C[k],k);
			AddTail(L,p);
		}
}

void DuyetList(List L)
{
	if (L.pHead==NULL)
	{
		printf("Danh sach rong");
		exit(0);
	}
	Node *p=new Node;
	p=L.pHead;
	while(p!=NULL)
	{
		printf("%d : %d",p->Key,p->vitri);
		p=p->pNext;
	}
}

void AddTail(List &L,Node *p)
{
	if (L.pHead==NULL)
		L.pHead=L.pTail=p;
	else
	{
		L.pTail->pNext=p;
		L.pTail=p;
	}
}

void NhapMaTran(int A[][hung],int B[][hung],int &m,int &n)
{
	printf("nhap so dong so cot : ");
	scanf("%d%d",&m,&n);
	printf("Nhap ma tran A\n");
	Nhap(A,m,n);
	printf("Nhap ma tran B\n");
	Nhap(B,m,n);
}

void Nhap(int A[][hung], int m, int n)
{
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			scanf("%d",&A[i][j]);
}


Node *CreateNode(int x,int vitri)
{
	Node *p=new Node;
	if (p==NULL)
	{
		printf("Khong du bo nho");
		exit(0);
	}
	p->Key=x;
	p->vitri=vitri;
	p->pNext=NULL;
	return p;
}