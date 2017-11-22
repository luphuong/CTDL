#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define hung 100
void nhap(int A[],int &n);
void xuat(int A[],int n);
void xoavitri(int A[],int &n);
void lietkesomax(int A[],int n);
void lietkesomin(int A[],int n);
void xuat(int k);
void demphantuam(int A[],int n);
void giatriamlonnhat(int A[],int n);
void giatriduongnhonhat(int A[],int n);
void timphantu(int A[],int n);
int tim(int A[],int n);
void demsophantubangx(int A[],int n);
int dem(int A[],int n);
void SelectionSort(int A[],int n);
void InterchangeSort(int A[],int n);
void swap (int &a, int &b);
void BubbleSort(int A[],int n);
void InsertionSort(int A[],int n);
void QuickSort(int A[],int l,int r);
void timkiemnhiphan(int A[],int n);
int timkiem(int A[],int n,int k);
void xuat1(int kq);
void menu(int A[],int n);
void main()
{
	int A[hung],n;
	nhap(A,n);
	menu(A,n);
}
void menu(int A[],int n)
{
	int k = -1;
	int i,x;
Menu:
	while(k)
	{
		xuat(A, n);
		printf("\n");
		printf("\n");
		printf("1. Xoa 1 phan tu tai chi so k\n");
		printf("2.liet ke nhung phan tu mang gia tri max\n");
		printf("3.liet ke nhung phan tu mang gia tri min\n");
		printf("4.dem so phan tu co gia tri am\n");
		printf("5.cho biet gia tri am lon nhat \n");
		printf("6.cho biet gia tri duong nho nhat \n");
		printf("7.tim phan tu co khoa bang X co hay khong co\n");
		printf("8.dem so phan tu co gia tri bang X , khong co thi thong bao ko co\n");
		printf("9.sap xep mang tang dan bang thuat toan da hoc: \n");
		printf("10.thoat\n");
		printf("moi dua ra lua chon: ");
	scanf("%d",&k);
	
	switch(k)
	{
	case 1:xoavitri(A, n); printf("\n"); system("pause"); system("cls"); break;
	case 2:lietkesomax(A,n); printf("\n"); system("pause"); system("cls"); break;
	case 3:lietkesomin(A,n); printf("\n"); system("pause"); system("cls"); break;
	case 4:demphantuam(A,n); printf("\n"); system("pause"); system("cls"); break;
	case 5:giatriamlonnhat(A,n); printf("\n"); system("pause"); system("cls"); break;
	case 6:giatriduongnhonhat(A,n); printf("\n"); system("pause"); system("cls"); break;
	case 7:timphantu(A, n);printf("\n"); system("pause"); system("cls"); break;
	case 8:demsophantubangx(A, n); printf("\n"); system("pause"); system("cls"); break;
	case 9:printf("chon thuat toan\n");
		printf("1 Selection Sort\n");
		printf("2 Interchange Sort\n");
		printf("3 Bubble Sort\n");
		printf("4 Insertion Sort\n");
		printf("5 Quick Sort\n");
		scanf("%d",&i);
		switch(i)
		{
		case 1:SelectionSort(A,n); printf("\n"); system("pause"); system("cls"); break;
		case 2:InterchangeSort(A,n); printf("\n"); system("pause"); system("cls"); break;
		case 3:BubbleSort(A,n); printf("\n"); system("pause"); system("cls"); break;
		case 4:InsertionSort(A,n); printf("\n"); system("pause"); system("cls"); break;
		case 5:int l=0;
	           int r=n-1;
	           QuickSort(A,l,r);
			   xuat(A,n); printf("\n"); system("pause"); system("cls"); break;
		}
		printf("\ntim phan tu bang thuat toan tim kiem nhi phan tu cau 9\n");
		printf("0.ket thuc\n");
		printf("1.tiep tuc\n");
		scanf("%d",&x);
		switch(x)
		{
		case 0:system("cls");goto Menu;break;
		case 1:timkiemnhiphan(A, n);goto Menu; break;
		}
	case 10:exit(0);
	}
	}
}
void timkiemnhiphan(int A[],int n)
{
	int k;
	printf("so can tim: ");
	scanf("%d",&k);
	int kq=timkiem(A,n,k);
	xuat1(kq);
}
void xuat1(int kq)
{
	if(kq==-1)
		printf("khong tim thay ");
	else
		printf("tim thay o vi tri thu: %d \n",kq+1);
}
int timkiem(int A[],int n,int k)
{
	int mid,l=0,r=n-1;
     while(l<=r)
	 {
		 mid=(l+r)/2;
		 if(A[mid]==k)
			 return mid;
		 else
			 if(A[mid]<k)
				 l=mid+1;
			 else
				 r=mid-1;
	 }
		 return -1;
}
void QuickSort(int A[],int l,int r)
{
	int i=l,j=r;
	int pivot=A[(l+r)/2];
	while(i<=j)
	{
		while(A[i]<pivot)
			i++;
		while(A[j]>pivot)
			j--;
		if(i<=j)
		{
			int temp=A[i];
			A[i]=A[j];
			 A[j]=temp;
			 i++;
			 j--;
		}
	}
	if(l<j)
		QuickSort(A,l,j);
	if(i<r)
		QuickSort(A,i,r);
}

void InsertionSort(int A[],int n)
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
void BubbleSort(int A[],int n)
{
	int flag=1;
	int j=0;
	while(flag)
	{
		flag=0;
		j++;
		for(int i=0;i<n-j;i++)
		{
			if(A[i]>A[i+1])
			{
				int temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
				flag=1;
			}
		}
	}
	xuat(A,n);
}
void SelectionSort(int A[],int n)
{
  for (int i=0;i<n-1;i++)
	{
		int min = i;
		for (int j=i+1;j<n;j++)
			if (A[min]>A[j])
				min = j;
			swap(A[i], A[min]);
	}
  xuat(A,n);
}
void swap(int &a, int &b)
{
   
	int x = a;
	a = b;
	b = x;
}
void InterchangeSort(int A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i]>A[j])
			{
				int t=A[i];
				A[i]=A[j];
				A[j]=t;
			}
		}
	}
	xuat(A,n);
}
void demsophantubangx(int A[],int n)
{
	int kq=dem(A,n);
	if(kq==0)
		printf("khong co ");
	else
		printf("%d ",kq);
}
int dem(int A[],int n)
{
	int dem=0,i,x;
	printf("nhap so can dem: ");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(A[i]==x)
			dem++;
	}
	if(dem!=0)
		return dem;
	else
		return 0;
}
void timphantu(int A[],int n)
{
	int kq=tim(A,n);
	if(kq==1)
		printf("tim thay ");
	else
		printf("khong co ");
}
int tim(int A[],int n)
{
	int x,i=0;
	printf("nhap so can tim: ");
	scanf("%d",&x);
	while(i<n && A[i]!=x)
	{
		i++;
	}
	if(i!=n)
		return 1;
	else
		return 0;;
}
void giatriduongnhonhat(int A[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
				if(A[i]>A[j])
			{
				int k=A[i];
				A[i]=A[j];
				A[j]=k;
			}
		}
	}
    int min;
	for(i=0;i<n;i++)
	{
		if(A[i]>0)
		{
			min=A[i];
			break;
		}
	}
	xuat(min);
}
void giatriamlonnhat(int A[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i]>A[j])
			{
				int k=A[i];
				A[i]=A[j];
				A[j]=k;
			}
		}
	}
	int max;
	for(i=n-1;i>=0;i--)
	{
		if(A[i]<0)
		{
			max=A[i];
			break;
		}
	}
	xuat(max);
}
void demphantuam(int A[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(A[i]<0)
			dem++;
	}
	xuat(dem);
}
void xuat(int k)
{
	printf("%d ",k);
}
void lietkesomin(int A[],int n)
{
	int B[hung],b=0;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i]>A[j])
			{
				int k=A[j];
				A[j]=A[i];
				A[i]=k;
			}
		}
	}
	if(n<4)
	{
	    B[b++]=A[0];
		xuat(B,b);
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			B[b++]=A[i];
		}
		xuat(B,b);
	}
}
void lietkesomax(int A[],int n)
{
	int B[hung],b=0;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(A[i]<A[j])
			{
				int k=A[j];
				A[j]=A[i];
				A[i]=k;
			}
		}
	}
	if(n<4)
	{
	    B[b++]=A[0];
		xuat(B,b);
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			B[b++]=A[i];
		}
		xuat(B,b);
	}
}
void xoavitri(int A[],int &n)
{
	int k;
	printf("vi tri can xoa (bat dau tu 0): ");
	scanf("%d",&k);
	for(int i=k;i<n-1;i++)
		A[i]=A[i+1];
	n--;
	xuat(A,n);
}
void nhap(int A[],int &n)
{
	printf("nhap so phan tu: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
}
void xuat(int A[],int n)
{
	for(int i=0;i<n;i++)
		printf("%d ",A[i]);
}