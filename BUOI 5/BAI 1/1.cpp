#include<stdio.h>
#include<stdlib.h>
#define hung 100
struct STACK
{
	int Top;
	int A[hung];
};
void CreateStack(STACK &S);
void Push(STACK &S,int x);
void Xuat(STACK S);
void Nhap(STACK &S);
int Isempty(STACK S);
int Isfull(STACK S);
void Menu(STACK &S);
int Pop(STACK &S);
int Top(STACK S);
void main()
{
	STACK S;
	CreateStack(S);
	Menu(S);
}
void Menu(STACK &S)
{
	int k;
	Nhap(S);
Menu:
	system("cls");
	Xuat(S);
	while(k)
	{
    printf("\n1: Kiem tra STACK rong");
    printf("\n2: Kiem tra STACK day");
    printf("\n3: Them phan tu vao STACK");
    printf("\n4: Xoa phan tu trong STACK");
    printf("\n5: Lay thong tin phan tu o dinh STACK");		
    printf("\n6: Xuat STACK");
    printf("\n7: Thoat");
    printf("\nLua Chon: ");
    scanf("%d",&k);
        switch (k)
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
                if (Isfull(S)) 
				{
					printf("STACK day !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
                else 
				{
					printf ("STACK chua day !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
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
int Top(STACK S)
{
	return S.A[S.Top-1];
}
int Pop(STACK &S) 
{
	int t;
    if (S.Top!=0)
    {
	   t=S.A[S.Top];
        S.Top--; 
    }
	return t;
}
int Isfull(STACK S) 
{
    return (S.Top==hung); 
}
 
int Isempty(STACK S) 
{
	return(S.Top==0);
}
void Nhap(STACK &S)
{
    int n;
    int x;
    do
    {
        printf("Nhap so phan tu cua Stack (<%d) :",hung);
        scanf("%d",&n);
    } while (n>hung || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
        Push(S,x);
    }
}
void Xuat(STACK S)
{
	for (int i=S.Top-1; i>=0; i--)
        printf("%d   ",S.A[i]);
    printf("\n");
}
void Push(STACK &S,int x)
{
	if(S.Top==hung)
		printf("Ngan xep day");
	else
	{
		S.A[S.Top]=x;
		S.Top++;
	}

}
void CreateStack(STACK &S)
{
	S.Top=0;
}
