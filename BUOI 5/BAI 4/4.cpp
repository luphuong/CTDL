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
void Menu(QUEUE Q);
void EnQueue(QUEUE &Q,int x);
void Nhap(QUEUE &Q);
int Isempty(QUEUE Q);
void Xuat(QUEUE Q);
int DeQueue(QUEUE &Q);
int Front(QUEUE Q);
void main()
{
	QUEUE Q;
	CreateQueue(Q);
	Menu(Q);
}
void Menu(QUEUE Q)
{
	int k;
	Nhap(Q);
Menu:
	system("cls");
	Xuat(Q);
	while(k)
	{
		printf("\n1: Kiem tra QUEUE rong");
		printf("\n2: Kiem tra  do dai QUEUE");
        printf("\n3: Them phan tu vao QUEUE");
        printf("\n4: Xoa phan tu trong QUEUE");
		printf("\n5: Lay thong tin cua QUEUE");
        printf("\n6: Xuat QUEUE");
        printf("\n7: Thoat");
	    printf("\nLua chon: ");
        scanf("%d",&k);
        switch(k)
        {
            case 1:
            {
                if (Isempty(Q)) 
				{
					printf("QUEUE rong !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
                else 
				{
					printf ("QUEUE khong rong !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
            }
            case 2:
            {
                printf("\nDo dai cua QUEUE la : %d",Q.Count);
				printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
            case 3:
            {
                int x;
                printf ("Nhap phan tu can chen vao QUEUE: ");
                scanf("%d",&x);
                EnQueue(Q,x);
				printf("\nQUEUE sau khi chen\n");
				Xuat(Q);
                printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
            case 4:
            {
                int x=DeQueue(Q);
				printf("\nThong tin phan tu xoa : %d",x);
				printf("\nQUEUE sau khi xoa\n");
				Xuat(Q);
                printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
			case 5:
			{
				int x=Front(Q);
				if(x!=0)
					printf("\nThong tin phan tu dau : %d",x);
				else
					printf("Hang doi rong !");
				printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
			}
            case 6: 
            {
                Xuat(Q);
                printf("\nEnter de tiep tuc\n");
				system("pause");system("cls");goto Menu;
            }
            case 7: 
				exit(0);
		}
	}
}
int Front(QUEUE Q) 
{
    if (Isempty(Q)) 
		return 0;
	return Q.Front->info;
}
int DeQueue(QUEUE &Q) 
{
    if (Isempty(Q)) 
    {
        printf("Hang doi rong !");
        return 0;
    }
    else
    {
        int x = Q.Front->info;
        if (Q.Count == 1) 
            CreateQueue(Q);
        else
            Q.Front = Q.Front->pNext;
        Q.Count --;
        return x; 
    }
}
void Xuat(QUEUE Q)
{
    Node*p = Q.Front;
    while(p!= NULL)
    {
        printf("%d   ",p->info);
        p=p->pNext;
    }
    printf("\n");
}
int Isempty(QUEUE Q) 
{
    if (Q.Count == 0) 
        return 1;
    return 0;
}
void Nhap(QUEUE &Q)
{
	int n,x;
	printf("Nhap so phan tu cua QUEUE: ");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
		Node*p=CreateNode(x);
        EnQueue(Q,x);
    }
}
void EnQueue(QUEUE &Q,int x) 
{
    Node*p =CreateNode(x); 
    if (Isempty(Q))
    {
        Q.Front=Q.Rear=p; 
    }
    else 
    { 
        Q.Rear->pNext=p;
        Q.Rear=p;
    }
    Q.Count++; 
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