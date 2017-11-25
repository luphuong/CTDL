#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int info;
	Node*pNext;
};
struct STACK
{
	Node*Top;
};
void CreateStack(STACK &S);
void Menu(STACK S);
void Nhap(STACK &S);
void Xuat(STACK S);
int Isempty(STACK S);
int Top(STACK S);
void Push(STACK &S,int x);
Node*CreateNode(int x);
int Pop(STACK &S);
int Len(STACK S);
void main()
{
	STACK S;
	CreateStack(S);
	Menu(S);
}
void Menu(STACK S)
{
	int k;
	Nhap(S);
Menu:
	system("cls");
	Xuat(S);
	while(k)
	{
		printf("\n1: Kiem tra STACK rong");
        printf("\n2: Kiem tra  do dai STACK");
        printf("\n3: Them phan tu vao STACK");
        printf("\n4: Xoa phan tu trong STACK");
        printf("\n5: Lay thong tin phan tu o dinh STACK");		
        printf("\n6: Xuat STACK");
        printf("\n7: Thoat");
        printf("\nLua Chon: ");
        scanf("%d",&k);
		switch(k)
		{
			case 1:
            {
                if (Isempty(S)) 
				{
					printf("STACK rong !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
                else 
				{
					printf ("STACK khong rong !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
            }
            case 2:
            {
                printf("Do dai Stack: %d",Len(S));
                printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
            case 3:
            {
                int x;
                printf ("Nhap phan tu can chen vao STACK: ");
                scanf("%d",&x);
                Push(S,x);
				printf("\nSTACK sau khi chen\n");
				Xuat(S);
				printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
            case 4:
            {
                Pop(S);
				printf("\nSTACK sau khi Pop\n");
				Xuat(S);
				printf("\nEnter de tiep tuc\n");
                system("pause");system("cls");goto Menu;
            }
			case 5:
			{
				int d=Top(S);
				printf("\nPhan tu o dinh STACK la %d",d);
				printf("\nEnter de tiep tuc\n");
                system("pause");system("cls");goto Menu;
			}
            case 6: 
            {
                Xuat(S);
				printf("\nEnter de tiep tuc\n");
                system("pause");system("cls");goto Menu;
            }
            case 7: exit(0);
		}
	}
}
int Len(STACK S)
{
    Node *p = S.Top;
    int i=0;
    while (p != NULL) 
    {
        i++;
        p = p->pNext;
    }
    return i;
}
int Pop(STACK &S) 
{
	int x;
	Node*p=S.Top;
    if (!Isempty(S))
    {
        x = S.Top->info; 
        S.Top = S.Top->pNext; 
		delete p;
    }
	return x;
}
void Push(STACK &S,int x) 
{
    Node*p=CreateNode(x);
    p->pNext=S.Top;
    S.Top =p;
}
void Xuat(STACK S)
{
	for (Node*p=S.Top;p!=NULL;p=p->pNext)
		printf("%d   ",p->info);
    printf("\n");
}
void Nhap(STACK &S)
{
	int n;
    int x;
	printf("Nhap so phan tu cua STACK: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
		Node*p=CreateNode(x);
        Push(S,x);
    }
}
int Top(STACK S) 
{
    return S.Top->info;
}
int Isempty(STACK S) 
{
    return (S.Top == NULL);
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
void CreateStack(STACK &S)
{
	S.Top=NULL;
}