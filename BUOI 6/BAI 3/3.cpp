#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int Key;
	Node*pRight;
	Node*pLeft;
};
typedef struct Node NODE; 
typedef NODE *TREE; 

void CreateTree(TREE &T)
{
	T=NULL;
}

void Nhap(TREE &T);
void Menu(TREE T);
void InsertNode(TREE &T,int x);
void LNR(TREE T);
Node* CreateNode(int x);
int Isempty(TREE T);
void InsertNode(TREE &T, int x);
void LRN(TREE T);
void NLR(TREE T);
void NRL(TREE T);
void RNL(TREE T);
void RLN(TREE T);
Node* SearchKey(TREE T,int x);
int DelKey(TREE &T,int x);
int CountNode(TREE T);
int Count(TREE T);
int CountLa(TREE T);
int Max(int a,int b);
int High(TREE T);
void main()
{
	TREE T;
	CreateTree(T);
	Menu(T);
}
void Menu(TREE T)
{
	int k;
	Nhap(T);
Menu:
	system("cls");
	while(k)
	{
		printf("\n1.In cay thanh LNR, LRN, NLR, NRL, RNL, RLN\n");
		printf("2.Tim mot nut co khoa bang X\n");
		printf("3.Xoa mot nut co khoa bang X\n");
		printf("4.Dem so nut trong cay\n");
		printf("5.Dem so nut co day du hai cay con\n");
		printf("6.Dem so nut la\n");
		printf("7.Tinh chieu cao cua cay\n");
		printf("8.Ve cay nhi phan ra man hinh\n");
		printf("9.Thoat\n");
		printf("Lua chon : ");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			{
			printf("\nLNR : ");
			LNR(T);
			printf("\nLRN : ");
			LRN(T);
			printf("\nNLR : ");
			NLR(T);
			printf("\nNRL : ");
			NRL(T);
			printf("\nRNL : ");
			RNL(T);
			printf("\nRLN : ");
			RLN(T);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 2:
			{
			Node *p;
			int x;
            printf("Nhap vao X can tim: ");
            scanf("%d", &x);
            p=SearchKey(T,x);
            if(p!=NULL) 
				printf("Tim thay X %d\n", p->Key);
            else 
				printf("X %d khong co trong cay\n", x);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 3:
			{
			int n;
			printf("\nNhap X can xoa : ");
			scanf("%d",&n);
			if (DelKey(T,n)) 
				printf("Xoa thanh cong\n");
            else 
				printf("Khong tim thay X %d can xoa\n", n);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 4:
			{
			int a=CountNode(T); 
			printf("\nSo nut trong cay la %d",a);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 5:
			{
			int b=Count(T);
			printf("\nSo nut co day du 2 con la %d",b);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 6:
			{
				int c=CountLa(T);
				printf("\nSo nut la trong cay la %d",c);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 7:
			{
				int d=High(T);
			printf("\nChieu cao cua cay la %d",d);
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 8:
			{
			printf("\nEnter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
			}
		case 9:
			exit(0);
		}
	}
}
int High(TREE T)
{
    if(Isempty(T)||(T->pLeft==NULL && T->pRight==NULL))
        return 0;
    else
        return (1+Max(High(T->pLeft),High(T->pRight)));
}
int Max(int a,int b)
{
    if(a>=b)
        return (a);
    else
        return (b);
}
int CountLa(TREE T)
{
    if(Isempty(T))
        return NULL;
    if((T->pLeft==NULL)&&(T->pRight==NULL))
        return 1;
    return CountLa(T->pLeft) + CountLa(T->pRight);
}
int Count(TREE T)
{
    if (T==NULL) 
		return 0;
    if (T->pLeft!=NULL && T->pRight!=NULL) 
		return 1+Count(T->pLeft)+Count(T->pRight);
    else 
		return Count(T->pLeft)+Count(T->pRight);
}
int CountNode(TREE T) 
{
   if( T==NULL)
      return 0;
   else
      return 1 + CountNode(T->pLeft) + CountNode(T->pRight);
}
int DelKey(TREE &T,int x)    
{
    if (T==NULL) 
		return 0;
    else 
		if(T->Key > x) 
			return DelKey(T->pLeft,x);
    else 
		if(T->Key < x) 
			return DelKey(T->pRight, x);
    else 
    {
        Node *p = T;
        if (T->pLeft == NULL) 
			T = T->pRight;    
        else 
			if(T->pRight == NULL) 
				T = T->pLeft;   
        else 
        {
            Node*S=T,*Q=S->pLeft;
            while(Q->pRight!=NULL)
            {
                S=Q;
                Q=Q->pRight;
            }
            p->Key = Q->Key;
            S->pRight = Q->pLeft;
            delete Q;
        }
    }
    return 1;
}
void LNR(TREE T)
{
	if(T!=NULL)
     {
		LNR(T->pLeft);
        printf("%d   ",T->Key);
        LNR(T->pRight);
     }
}
void LRN(TREE T)
{
	if(T!=NULL)
     {
		LNR(T->pLeft);
		LNR(T->pRight);
        printf("%d   ",T->Key);
     }
}
void NLR(TREE T)
{
	if(T!=NULL)
     {
		printf("%d   ",T->Key);
		LNR(T->pLeft);
		LNR(T->pRight);
     }
}
void NRL(TREE T)
{
	if(T!=NULL)
     {
		printf("%d   ",T->Key);
		LNR(T->pRight);
		LNR(T->pLeft);
     }
}
void RNL(TREE T)
{
	if(T!=NULL)
     {
		LNR(T->pRight);
		printf("%d   ",T->Key);
		LNR(T->pLeft);
     }
}
void RLN(TREE T)
{
	if(T!=NULL)
     {
		LNR(T->pRight);
		LNR(T->pLeft);
		printf("%d   ",T->Key);
     }
}
void Nhap(TREE &T)
{
	FILE *fi;
	fi=fopen("docfile.txt","rt");
	if (fi == NULL)
	{
		printf("Khong doc duoc file");
		exit(0);
	}
	int n, x;
	fscanf(fi,"%d",&n);
	for (int i=0;i<n;i++)
	{
		fscanf(fi,"%d",&x);
		InsertNode(T,x);
	}
	fclose(fi);
}
Node* CreateNode(int x)
{
    Node* p = new Node;
    p->Key = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
int Isempty(TREE T)
{
	return (T==NULL);
}
void InsertNode(TREE &T, int x)
{

    if(T==NULL)
	{ 
        Node *p = new Node;
        p->Key=x;
		p->pLeft=p->pRight=NULL;
		T=p;
    }
    else 
	{
        if(T->Key > x)
		{
            InsertNode(T->pLeft,x);
        }
        else 
			if(T->Key < x)
			{
				InsertNode(T->pRight,x);
			}
    }
}
Node* SearchKey(TREE T,int x)   
{
    if (T!=NULL)
    {
        if (T->Key == x) 
		{ 
			Node *p = T; 
			return p;
		}
        if (T->Key > x) 
			return SearchKey(T->pLeft, x);
        if (T->Key < x) 
			return SearchKey(T->pRight,x);
    }
    return NULL;
}


