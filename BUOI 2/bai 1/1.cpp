#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#define hung 100
void nhap(int A[],int &n);
void xuat(int A[],int n);
void BinarySort(int A[],int n);
void ShakerSort(int A[],int n);
void swap(int &a,int &b);
void ShellSort(int A[],int n);
void Menu(int A[]);
void Heapify(int A[],int n,int i);
void BuildHeap(int A[],int n);
void HeapSort(int A[],int n);
void main()
{
	int A[hung];
	Menu(A);
}
void Menu(int A[])
{
	int i,n;
Menu :
	printf("nhap mang A\n");
	nhap(A,n);
	while(i)
	{
	printf("1.Binary Sort\n");
	printf("2.Shaker Sort\n");
	printf("3.Shell Sort\n");
	printf("4.Heap Sort\n");
	printf("5.thoat\n");
	printf("lua chon : ");
	scanf("%d",&i);
	switch(i)
	{
	case 1: 
		BinarySort(A,n);
		xuat(A,n);system("pause");system("cls");goto Menu;
		break;
	case 2: 
		ShakerSort(A,n);
		xuat(A,n);system("pause");system("cls");goto Menu;
		break;
	case 3: 
		ShellSort(A,n);
		xuat(A,n);system("pause");system("cls");goto Menu;
		break;
	case 4: 
		HeapSort(A,n);
		xuat(A,n);system("pause");system("cls");goto Menu;
		break;
	case 5:exit(0);break;
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
}
void xuat(int A[],int n)
{
	for(int i=0;i<n;i++)
		printf("%2d ",A[i]);
}
void nhap(int A[],int &n)
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
}