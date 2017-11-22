#include<stdio.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include<time.h>
#define hung 100
void nhap(int A[],int &n);
void xuat(int A[],int n);
void QuickSort(int A[],int l,int r);
void MergeSort(int A[],int l,int r);
void RadixSort(int A[],int n);
void menu(int A[]);
void Merge(int A[],int l,int m,int r);
void CountSort(int A[], int n, int exp);
int GetMax(int A[], int n);
int ngaunhien(int x);
void main()
{
	int A[hung];
	menu(A);
}
void menu(int A[])
{
	long milisecond;
	long second;
	struct _timeb timebuffer;
	struct _timeb timebuffer1;
	int k,n;
	int l,r;
menu:
	nhap(A,n);
	printf("\n");
	xuat(A,n);
      l=0;
	r=n-1;
	while(k)
	{
		printf("\n1.QuickSort\n");
		printf("2.MergeSort\n");
		printf("3.RadixSort\n");
		printf("4.Thoat\n");
		printf("Lua Chon : ");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			_ftime( &timebuffer );
			QuickSort(A,l,r);
			_ftime( &timebuffer1 );
			xuat(A,n);
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto menu;break;
		case 2:
			_ftime( &timebuffer );
			MergeSort(A,l,r);
			_ftime( &timebuffer1 );
			xuat(A,n);
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto menu;break;
		case 3:
			_ftime( &timebuffer );
			RadixSort(A,n);
			_ftime( &timebuffer1 );
			xuat(A,n);
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto menu;break;
		case 4:
			exit(0);
		}
	}
}
void QuickSort(int A[],int l,int r)
{
	int i=l,j=r;
	int p=A[(l+r)/2];
	while(i<=j)
	{
		while(A[i]<p)
			i++;
		while(A[j]>p)
			j--;
		if(i<=j)
		{
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
			i++;
			j--;
		}
	};
	if(l<j)
		QuickSort(A,l,j);
	if(i<r)
		QuickSort(A,i,r);
}
void Merge(int A[],int l,int m,int r)
{
	int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[hung],R[hung];
    for(i=0;i<n1;i++)
        L[i]=A[l+i];
    for(j=0;j<n2;j++)
        R[j]=A[m+1+j];
    i=0; 
    j=0; 
    k=l; 
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else
        {
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        A[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        A[k]=R[j];
        j++;
        k++;
    }
}
void MergeSort(int A[],int l,int r)
{
   if(l<r)
    {
        int m=l+(r-l)/2;
        MergeSort(A,l,m);
        MergeSort(A,m+1,r);
        Merge(A,l,m,r);
    }
}
int GetMax(int A[],int n)
{
    int gx=A[0];
    for (int i=1;i<n;i++)
        if(A[i]>gx)
            gx=A[i];
    return gx;
}
void CountSort(int A[],int n,int exp)
{
    int output[hung]; 
    int i,count[10]={0};
    for(i=0;i<n;i++)
        count[(A[i]/exp)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[(A[i]/exp)%10]-1]=A[i];
        count[(A[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        A[i]=output[i];
}
void RadixSort(int A[],int n)
{
    int m=GetMax(A,n);
    for (int exp=1;m/exp>0;exp *=10)
        CountSort(A,n,exp);
}
void xuat(int A[],int n)
{
	for(int i=0;i<n;i++)
		printf(" %d ",A[i]);
}
void nhap(int A[],int &n)
{
	srand((unsigned)time(NULL));
	printf("Nhap N: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int t=ngaunhien(100);
		A[i]=t;
	}
}
int ngaunhien(int x)
{
	long t;
	t=rand()%x;
	return t;
}