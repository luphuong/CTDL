#include<stdio.h>
#define hung 100
void nhap(int &n);
void doisang2(int A[],int n);
void main()
{
	int n,A[hung];
	nhap(n);
	doisang2(A,n);
}
void doisang2(int A[],int n)
{
	int i;
	for(i=0;n>0;i++)
	{
		A[i]=n%2;
		n=n/2;
	}
	for(i=i-1;i>=0;i--)  
		printf("%d",A[i]);
    printf("\n");
}
void nhap(int &n)
{
	scanf("%d",&n);
}