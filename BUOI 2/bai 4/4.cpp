#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
struct SV
{
	char MSSV[10];
	char Hoten[30];
	float diemTB;
};
void xuat(SV A[],int n);
void xuatSV(SV a);
void docfile(SV A[],int &n);
void tachthongtin(char B[],SV &a);
void menu(SV A[],int n);
void lietkemax(SV A[],int n);
void DTBlon(SV A[],int n);
void timsinhvien(SV A[],int n);
int kiemtra(char S[],int x,char B[]);
void xoasinhvien(SV A[],int &n);
void SelectionSort(SV A[],int n);
void swap(SV &a, SV &b);
void InterchangeSort(SV A[],int n);
void BubbleSort(SV A[],int n);
void InsertionSort(SV A[],int n);
void QuickSort(SV A[],int l,int r);
void chensv(SV A[],int &n);
void nhap(SV &a);
void main()
{
	SV A[100];
	int n;
	docfile(A,n);
	menu(A,n);
}
void menu(SV A[],int n)
{
	int k;
	int x;
menu:
	while(k)
	{
	printf("\n1.In danh sach sinh vien ra man hinh");
	printf("\n2.Liet ke nhung sinh vien co DTB cao nhat trong lop");
	printf("\n3.Cho biet so sinh vien co DTB >=5");
	printf("\n4.Tim mot sinh vien co trong lop");
	printf("\n5.Xoa mot sinh vien co MSSV cho truoc trong lop hoc");
	printf("\n6.Sap xep danh sach sinh vien tang theo DTB bang thuat toan sap xep");
	printf("\n7.Them sinh vien vao danh sach");
	printf("\n8.Thoat");
	printf("\nMoi Ban Chon : ");
	scanf("%d",&k);
	switch(k)
	{
	case 1:
		printf("\nDanh sach co %d sinh vien\n",n);
		xuat(A,n);printf(" Enter de tiep tuc!!!\n"); system("pause");system("cls");break;
	case 2:
		lietkemax(A,n);printf(" Enter de tiep tuc!!!\n");system("pause"); system("cls");break;
	case 3:
		DTBlon(A,n);printf(" Enter de tiep tuc!!!\n");system("pause"); system("cls");break;
	case 4:
		timsinhvien(A,n);printf(" Enter de tiep tuc!!!\n");system("pause"); system("cls");break;
	case 5:
		xoasinhvien(A,n);printf(" Enter de tiep tuc!!!\n");system("pause"); system("cls");break;
	case 6:
		printf("\nChon thuat toan");
		printf("\n1.SelectionSort");
		printf("\n2.InterchangeSort");
		printf("\n3.BubbleSort");
		printf("\n4.InsertionSort");
		printf("\n5.QuickSort");
		printf("\nLua chon : ");
		scanf("%d",&x);
		switch(x)
		{
		case 1:
			SelectionSort(A,n);printf(" Enter de tiep tuc!!!\n");system("pause");system("cls");goto menu;break;
		case 2:
			InterchangeSort(A,n);printf(" Enter de tiep tuc!!!\n");system("pause");system("cls");goto menu;break;
		case 3:
			BubbleSort(A,n);printf(" Enter de tiep tuc!!!\n");system("pause");system("cls");goto menu;break;
		case 4:
			InsertionSort(A,n);printf(" Enter de tiep tuc!!!\n");system("pause");system("cls");goto menu;break;
		case 5:
			int l=0;
	        int r=n-1;
	        QuickSort(A,l,r);
			xuat(A,n);printf(" Enter de tiep tuc!!!\n");system("pause");system("cls");goto menu;break;
		}
	case 7:
		chensv(A,n);printf(" Enter de tiep tuc!!!\n");system("pause"); system("cls"); break;
	case 8:exit(0);
	}
	}
}
void chensv(SV A[],int &n)
{
	SV a;
	int i;
	printf("\n Nhap thong tin sinh vien can chen\n");
	nhap(a);
	float k=a.diemTB;
	if(k<A[0].diemTB)
	{
		int x=0;
		for(i=n-1;i>=x;i--)
			{
				A[i+1]=A[i];
			}
			A[x]=a;
			n++;
	}
	else
	{
		for(i=n-1;i>=0;i--)
		{
			if(k>=A[i].diemTB)
			{
				int x=i+1;
			    for(i=n-1;i>=x;i--)
				{
					A[i+1]=A[i];
				}
				A[x]=a;
			    n++;
			    break;
			}
	}
	}
	printf("\nDanh sach sinh vien sau khi them\n");
	xuat(A,n);
}
void nhap(SV &a)
{
	fflush(stdin);
	printf("\nNhap MSSV : ");
	gets(a.MSSV);
	fflush(stdin);
	printf("\nNhap ten sinh vien : ");
	gets(a.Hoten);
	fflush(stdin);
	printf("\nNhap diem TB : ");
	scanf("%f",&a.diemTB);
}
void QuickSort(SV A[],int l,int r)
{
	int i=l,j=r;
	float pivot=A[(l+r)/2].diemTB;
	while(i<=j)
	{
		while(A[i].diemTB<pivot)
			i++;
		while(A[j].diemTB>pivot)
			j--;
		if(i<=j)
		{
			 swap(A[i],A[j]);
			 i++;
			 j--;
		}
	}
	if(l<j)
		QuickSort(A,l,j);
	if(i<r)
		QuickSort(A,i,r);
}
void InsertionSort(SV A[],int n)
{
	int i;
	for(i=1;i<n;i++)
	{
		float x=A[i].diemTB;
		int j=i-1;
		while(j>=0 && A[j].diemTB>x)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1].diemTB=x;
	}
	printf("\nDanh sach sau khi sap xep\n");
	xuat(A,n);
}
void BubbleSort(SV A[],int n)
{
	int flag=1;
	int j=0;
	while(flag)
	{
		flag=0;
		j++;
		for(int i=0;i<n-j;i++)
		{
			if(A[i].diemTB>A[i+1].diemTB)
			{
				swap(A[i],A[i+1]);
				flag=1;
			}
		}
	}
	printf("\nDanh sach sau khi sap xep\n");
	xuat(A,n);
}
void InterchangeSort(SV A[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(A[i].diemTB>A[j].diemTB)
			{
				swap(A[i],A[j]);
			}
		}
	}
	printf("\nDanh sach sau khi sap xep\n");
	xuat(A,n);
}
void SelectionSort(SV A[],int n)
{
  for (int i=0;i<n-1;i++)
	{
		int min = i;
		for (int j=i+1;j<n;j++)
			if (A[min].diemTB>A[j].diemTB)
				min = j;
			swap(A[i], A[min]);
	}
  printf("\nDanh sach sau khi sap xep\n");
  xuat(A,n);
}
void swap(SV &a, SV &b)
{
   
	SV x = a;
	a = b;
	b = x;
}
void xoasinhvien(SV A[],int &n)
{
	char S[10];
	int i,j;
	fflush(stdin);
	printf("\nNhap MSSV can xoa : ");
	gets(S);
	int k=strlen(S);
	int dem=0;
	int h=n;
	for(i=0;i<n;i++)
	{
		if(kiemtra(S,k,A[i].MSSV))
		{
			for(j=i;j<n-1;j++)
			{
				A[j]=A[j+1];
			}
			n--;
		}
		else
			dem++;
	}
	if(dem==h)
		printf("\nkhong tim thay MSSV can xoa\n");
	else
	{
	for(i=0;i<n;i++)
	{
		xuatSV(A[i]);
	}
	}
}
void timsinhvien(SV A[],int n)
{
	int i;
	char S[10];
	fflush(stdin);
	printf("\nNhap ten sinh vien : ");
	gets(S);
	int k=strlen(S);
	int dem=0;
	for(i=0;i<n;i++)
	{
		if(kiemtra(S,k,A[i].Hoten))
		{
			xuatSV(A[i]);
			dem++;
		}
	}
	if(dem==0)
		printf("\nkhong co ten can tim\n");
}
int kiemtra(char S[],int x,char B[])
{
	int k=strlen(B);
	if(k==x)
	{
		for(int i=0;i<k;)
		{
			if(S[i]==B[i])
				i++;
			else
				return 0;
		}
		return 1;
	}
	else
		return 0;
}
void DTBlon(SV A[],int n)
{
	int dem=0;
	for(int i=0;i<n;i++)
	{
		if(A[i].diemTB>5 || A[i].diemTB==5)
		{
			//xuatSV(A[i]);
			dem++;
		}
	}
	if(dem==0)
		printf("\nkhong co\n");
	else
		printf("\nco %d sinh vien DTB >=5\n",dem);
}
void lietkemax(SV A[],int n)
{
	float max=-1;
	int j,i;
	for(i=0;i<n;i++)
	{
		if(A[i].diemTB>max)
		{
			max=A[i].diemTB;
			j=i;
		}
	}
	printf("\n Nhung sinh vien co DTB cao nhat lop : \n");
	xuatSV(A[j]);
	for(i=0;i<n;i++)
	{
		float k=A[i].diemTB;
		if(k==max)
			if(i!=j)
			{
				xuatSV(A[i]);	
			}
	}
}

void tachthongtin(char B[],SV &a)
{
	int i=0;
	while(B[i]!=' ')
	{
		a.MSSV[i]=B[i];
		i++;
	}
	a.MSSV[i]='\0';

	char temp[10];
	int len=strlen(B)-2;
	int j=len;
	int k=0;
	while(B[j]!=' ')
	{
		temp[k++]=B[j];
		j--;
	}
	temp[k]='\0';
	strrev(temp);
	a.diemTB=float(atof(temp));

	int t=0;
	for(k=i+1;k<j;k++)
		a.Hoten[t++]=B[k];
	a.Hoten[t]='\0';
}
void docfile(SV A[],int &n)
{
	FILE *fi=fopen("DSSV.txt","rt");
	if(fi==NULL)
	{
		printf("khong tim thay file");
		exit(0);
	}
	fscanf(fi,"%d%/*c",&n);
	char B[50];
	for(int i=0;i<n;i++)
	{
		fgets(B,50,fi);
		tachthongtin(B,A[i]);
	}
	fclose(fi);
}
void xuat(SV A[],int n)
{
	for(int i=0;i<n;i++)
		xuatSV(A[i]);
}
void xuatSV(SV a)
{
	printf("%s  %s  %.2f\n",a.MSSV,a.Hoten,a.diemTB);
}