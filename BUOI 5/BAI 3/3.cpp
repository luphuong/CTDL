#include<stdio.h>
#include<stdlib.h>
#define hung 100
struct QUEUE
{
	int Front;
	int Rear;
	int A[hung];
	int Count;
};
void CreateQueue(QUEUE &Q);
void Menu(QUEUE Q);
void EnQueue(QUEUE &Q,int x);
void Xuat(QUEUE Q);
int Isempty(QUEUE Q);
void Nhap(QUEUE &Q);
int Isfull(QUEUE Q);
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
        printf("\n2: Kiem tra QUEUE day");
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
                if (Isfull(Q))
				{
					printf("QUEUE day !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
                else 
				{
					printf ("QUEUE chua day !");
					printf("\nEnter de tiep tuc\n");
					system("pause");system("cls");goto Menu;
				}
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
	return Q.A[Q.Front];
}
int DeQueue(QUEUE &Q) 
{
	int x;
    if (Isempty(Q)) 
		printf("Hang doi rong !");
    else
    {
        x = Q.A[Q.Front];
        for (int i=Q.Front; i<Q.Rear; i++) 
            Q.A[i] = Q.A[i+1];
        Q.Rear--; 
        Q.Count--;
    }
	return x; 
}
void Xuat(QUEUE Q)
{
    if (Isempty(Q)) 
		printf("Hang doi rong !");
    else
    {
        for (int i=Q.Front; i<=Q.Rear; i++)
            printf("%d   ",Q.A[i]);
        printf("\n");
    }
}
int Isempty(QUEUE Q) 
{
    if (Q.Count == 0) 
        return 1;
    return 0;
}
void Nhap(QUEUE &Q)
{
	int n;
    int x;
    do
    {
        printf("Nhap so phan tu cua QUEUE (<%d) :",hung);
        scanf("%d",&n);
    } while (n>hung || n<1);
    for (int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d : ", i+1);
        scanf("%d",&x);
        EnQueue(Q,x);
    }
}
void EnQueue(QUEUE &Q,int x) 
{
    if (Isfull(Q)) 
		printf("Hang doi day !");
    else
    { 
        Q.A[++Q.Rear] = x; 
        Q.Count++; 
    }
}
int Isfull(QUEUE Q) 
{
    if (Q.Count==hung) 
        return 1;
    return 0;
}
void CreateQueue(QUEUE &Q)
{
	Q.Front=0;
	Q.Rear=-1;
	Q.Count=0;
}
