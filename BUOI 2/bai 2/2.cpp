#include<stdio.h>
#include<stdlib.h>
#include<sys/timeb.h>
#include<time.h>
#define hung 100
void nhap(int A[],int &n);
void xuat(int A[],int n);
void BinarySort(int A[],int n);
void ShakerSort(int A[],int n);
void swap(int &a,int &b);
void ShellSort(int A[],int n);
void Heapify(int A[],int n,int i);
void BuildHeap(int A[],int n);
void HeapSort(int A[],int n);
int ngaunhien(int x);
void Menu(int A[]);
void main()
{
	int A[hung];
	Menu(A);
}
void Menu(int A[])
{
	int k,n;
	long milisecond;
	long second;
	struct _timeb timebuffer;
	struct _timeb timebuffer1;
Menu:
	nhap(A,n);
	printf("\n");
	xuat(A,n);
	while(k)
	{
		printf("\n1.BinarySort\n");
		printf("2.ShakerSort\n");
		printf("3.ShellSort\n");
		printf("4.HeapSort\n");
		printf("5.Thoat\n");
		printf("Lua Chon : ");
		scanf("%d",&k);
		switch(k)
		{
		case 1 :
            _ftime( &timebuffer );
			BinarySort(A,n);
            _ftime( &timebuffer1 );
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto Menu;break;
		case 2 :
            _ftime( &timebuffer );
			ShakerSort(A,n);
            _ftime( &timebuffer1 );
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
		  system("pause");system("cls");goto Menu;break;
		case 3 :
			_ftime( &timebuffer );
			ShellSort(A,n);
			_ftime( &timebuffer1 );
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto Menu;break;
		case 4 :
			_ftime( &timebuffer );
			HeapSort(A,n);
			_ftime( &timebuffer1 );
			milisecond = timebuffer1.millitm - timebuffer.millitm;
			second = timebuffer1.time - timebuffer.time;
			printf("\n So giay %ld  va %ld phan tram giay",second, milisecond);
			system("pause");system("cls");goto Menu;break;
		case 5:
			exit(0);
		}
	}
}
void HeapSort(int A[],int n)
{
   BuildHeap(A,n);
  for(int i=n-1;i>0;i--)
  {
    swap(A[0],A[i]);
    Heapify(A,i,0);
  }
  xuat(A,n);
}
void BuildHeap(int A[],int n) 
{
  for(int i=n/2-1;i>=0;i--)
  Heapify(A,n,i);
}
void Heapify(int A[],int n,int i) 
{
	int l =2*(i+1)-1;
    int r =2*(i+1);
    int max;
	if(l<n && A[l]>A[i])
		max=l;
    else
        max=i;
    if(r<n && A[r]>A[max])
        max = r;
    if(i!=max) 
	{
		swap(A[i],A[max]);
		Heapify(A,n,max);
	}
}
void  ShellSort(int A[],int n)
{
     int i;
	for(i=1;i<n;i++)
	{
		int x=A[i];
		int j=i-1;
		while(j>=0 && A[j]>x)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=x;
	}
	xuat(A,n);
}
void ShakerSort(int A[],int n)
{
	int l=0;
	int r=n-1;
	int k =0;
	while(l<r)
	{
		for(int i=l;i<r;i++)
		{
			if (A[i]>A[i+1])
			{
				swap(A[i],A[i+1]);
				k=i;
			}
		}
		r=k;
		for(i=r;i>l;i--)
		{
			if (A[i]<A[i-1])
			{
				swap(A[i],A[i-1]);
				k=i;
			}
		}
		l=k;
	}
	xuat(A,n);
}
void swap(int &a,int &b)
{
	int k=a;
	a=b;
	b=k;
}
void BinarySort(int A[],int n)
{
for (int i=1;i<n;i++)
{
	int x=A[i],l=0,r=i-1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (x<A[mid])
			r=mid-1;
		else 
			l=mid+1;
	}
	for(int j=i-1;j>=l;j--)
		A[j+1]=A[j];
	A[l]=x;
}
xuat(A,n);
}
void xuat(int A[],int n)
{
	for(int i=0;i<n;i++)
		printf("%2d ",A[i]);
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