#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct SV
{
	char MSSV[10];
	char HoTen[30];
	float DiemTB;
	SV*pNext;
};
struct List
{
	SV*pHead;
	SV*pTail;
};
void CreateList(List &L);
SV*CreateSV(char MS[],char HT[],float DTB);
void AddTail(List &L,SV*p);
void Menu(List L);
void Nhap(List &L);
void Xuat(List L);
void XuatSV(SV*p);
void LietKeSV(List L);
void DemSV(List L);
int KiemTra(char S[],int k,char A[],int a);
void Find(List L);
void RemoveTail(List &L);
void Delete(List &L);
void RemoveHead(List &L);
void SelectionSort(List &L);
void BubbleSort(List &L);
void InterchangeSort(List &L);
void InsertionSort(List &L);
void QuickSort(List &L);
void AddSV(List &L);
void AddHead(List &L,SV *p);
void main()
{
	List L;
	CreateList(L);
	Menu(L);
}
void Menu(List L)
{
	int k,i;
	Nhap(L);
	system("cls");
Menu:
	while(k)
	{
		printf("\n1.In danh sach ra man hinh\n");
		printf("2.Liet ke nhung SV co DTB cao nhat\n");
		printf("3.Cho biet so SV co DTB>=5\n");
		printf("4.Tim SV co ten X trong lop\n");
		printf("5.Xoa SV co MSSV cho truoc\n");
		printf("6.Sap xep DSSV tang dan theo DTB bang cac thuat toan sap xep\n");
		printf("7.Thoat\n");
		printf("Lua Chon : ");
		scanf("%d",&k);
		switch(k)
		{
		case 1:
			Xuat(L);
			printf("\nNhan Enter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
		case 2:
			LietKeSV(L);
			printf("\nNhan Enter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
		case 3:
			DemSV(L);
			printf("\nNhan Enter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
		case 4:
			Find(L);
			printf("\nNhan Enter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
		case 5:
			Delete(L);
			printf("\nDSSV sau khi xoa\n");
			Xuat(L);
			printf("\nNhan Enter de tiep tuc\n");
			system("pause");system("cls");goto Menu;
		case 6:
			system("cls");
			printf("\nNhung thuat toan sap xep\n");
			printf("\n1.Selection Sor\n");
			printf("2.Interchange Sort\n");
			printf("3.Bubble Sort\n");
			printf("4.Insertion Sort\n");
			printf("5.Quick Sort\n");
			printf("Lua Chon : ");
			scanf("%d",&i);
			switch(i)
			{
			case 1:
				SelectionSort(L);
				printf("\nDSSV sau khi sap xep\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");break;
			case 2:
				InterchangeSort(L);
				printf("\nDSSV sau khi sap xep\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");break;
			case 3:
				BubbleSort(L);
				printf("\nDSSV sau khi sap xep\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");break;
			case 4:
				InsertionSort(L);
				printf("\nDSSV sau khi sap xep\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");break;
			case 5:
				QuickSort(L);
				printf("\nDSSV sau khi sap xep\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");break;
			}
			printf("\nChen SV vao DS\n");
			printf("0.Quay lai\n");
			printf("1.Tiep tuc\n");
			printf("Lua Chon : ");
			scanf("%d",&i);
			switch(i)
			{
			case 0:
				system("cls");goto Menu;
			case 1:
				AddSV(L);
				printf("\nDSSV sau khi chen\n");
				Xuat(L);
			    printf("\nNhan Enter de tiep tuc\n");
			    system("pause");system("cls");goto Menu;
			}
		case 7:
			exit(0);
		}
	}
}
void AddSV(List &L)
{
	char MS[10];
	char HT[30];
	float DTB;
	fflush(stdin);
	printf("\nMa So Sinh Vien : ");
	gets(MS);
	fflush(stdin);
	printf("Ten Sinh Vien : ");
	gets(HT);
	fflush(stdin);
	printf("Diem TB : ");
	scanf("%f",&DTB);
	fflush(stdin);
	SV*p=CreateSV(MS,HT,DTB);
	if(L.pHead==NULL)
		return;
	if(L.pHead->DiemTB>p->DiemTB)
	{
		AddHead(L,p);
		return;
	}
	if(L.pTail->DiemTB<p->DiemTB)
	{
		AddTail(L,p);
		return;
	}
	int k=0;
	for(SV*l=L.pHead;l!=NULL;l=l->pNext)
	{
		if(l->DiemTB<p->DiemTB)
			k++;
		else
		{
			k++;
			break;
		}
	}
	SV*q=new SV;
	SV*w=new SV;
	SV*r=L.pHead;
	int dem=0;
	while(r!=NULL)
	{
		dem++;
		q=r;
		if(dem==k)
			break;
		else
			r=r->pNext;
	}
	w=L.pHead;
	while(w->pNext!=q)
		w=w->pNext;
	w->pNext=p;
	p->pNext=r;
}
void AddHead(List &L,SV *p)
{
	if(L.pHead==NULL)
	{
		L.pHead=p;
		L.pTail=p;
	}
	else
	{
		p->pNext=L.pHead;
		L.pHead=p;
		
	}
}
void QuickSort(List &L)
{
	List L1,L2;
	L1.pHead=L1.pTail=NULL;
	L2.pHead=L2.pTail=NULL;
	if(L.pHead == L.pTail)
		return;
	SV *pivot=L.pHead;
	L.pHead=pivot->pNext;
	while(L.pHead != NULL)
	{
		SV *p=L.pHead;
		L.pHead=p->pNext;
		p->pNext=NULL;
		if(p->DiemTB < pivot->DiemTB)
			AddTail(L1,p);
		else
			AddTail(L2,p);
	};
	QuickSort(L1);
	QuickSort(L2);
	if(L1.pHead!=NULL)
	{
		L.pHead=L1.pHead;
		L1.pTail->pNext=pivot;
	}
	else
		L.pHead=pivot;

	pivot->pNext=L2.pHead;

	if(L2.pHead!=NULL)
		L.pTail=L2.pTail;
	else
		L.pTail=pivot;
}
void InsertionSort(List &L)
{
	SV *p,*q;
	for(p=L.pHead;p!=L.pTail;p=p->pNext)
	{
		SV *min=p;
		for(q=p->pNext;q!=NULL;q=q->pNext)
			if(q->DiemTB<min->DiemTB)
				min=q;
		float tmp=p->DiemTB;
		p->DiemTB=min->DiemTB;
		min->DiemTB=tmp;
	}
}
void BubbleSort(List &L)
{
	SV *p,*q;
	for(p=L.pHead;p!=L.pTail;p=p->pNext)
	{
		SV *min=p;
		for(q=p->pNext;q!=NULL;q=q->pNext)
			if(q->DiemTB<min->DiemTB)
				min=q;
		float tmp=p->DiemTB;
		p->DiemTB=min->DiemTB;
		min->DiemTB=tmp;
	}
}
void InterchangeSort(List &L)
{
	SV *p,*q;
	for(p=L.pHead;p!=L.pTail;p=p->pNext)
	{
		SV *min=p;
		for(q=p->pNext;q!=NULL;q=q->pNext)
			if(q->DiemTB<min->DiemTB)
				min=q;
		float tmp=p->DiemTB;
		p->DiemTB=min->DiemTB;
		min->DiemTB=tmp;
	}
}
void SelectionSort(List &L)
{
	SV *p,*q;
	for(p=L.pHead;p!=L.pTail;p=p->pNext)
	{
		SV *min=p;
		for(q=p->pNext;q!=NULL;q=q->pNext)
			if(q->DiemTB<min->DiemTB)
				min=q;
		float tmp=p->DiemTB;
		p->DiemTB=min->DiemTB;
		min->DiemTB=tmp;
	}
}
void Delete(List &L)
{
	char S[30];
	char A[30];
	int a,k;
	fflush(stdin);
	printf("Nhap MSSV : ");
	gets(S);
	k=strlen(S);
	if(L.pHead==NULL)
		return;
	strcpy(A,L.pHead->MSSV);
	a=strlen(A);
	if(KiemTra(S,k,A,a))
	{
		RemoveHead(L);
		return;
	}
	strcpy(A,L.pTail->MSSV);
	a=strlen(A);
	if(KiemTra(S,k,A,a))
	{
		RemoveTail(L);
		return;
	}
	SV*q=new SV;
	for(SV*p=L.pHead;p!=NULL;p=p->pNext)
	{
		strcpy(A,p->MSSV);
		a=strlen(A);
		if(KiemTra(S,k,A,a))
		{
			q->pNext=p->pNext;
			delete p;
			return;
		}
		q=p;
	}
	printf("\nKhong xoa duoc\n");
}
void RemoveHead(List &L)
{
	SV*p=L.pHead;
	if(p!=NULL)
	{ 
		L.pHead=L.pHead->pNext;
		delete p;;
		if(L.pHead==NULL)
			L.pTail=NULL;
	}
	else
		printf("\nKhong xoa duoc\n");
}
void RemoveTail(List &L)
{
	SV*p=L.pHead;
	if(p!=NULL)
	{ 
		SV*q=L.pTail;
		if(L.pTail==L.pHead)
			L.pHead=L.pTail=NULL;
		else
		{
			for(p=L.pHead;p->pNext!=L.pTail;p=p->pNext);
			p->pNext=NULL;
			L.pTail=p;
		}
		delete q;
	}
	else
		printf("\nKhong xoa duoc\n");
}
void Find(List L)
{
	char S[10];
	fflush(stdin);
	printf("\nNhap ten sinh vien : ");
	gets(S);
	int k=strlen(S);
	int dem=0;
	for(SV*p=L.pHead;p!=NULL;p=p->pNext)
	{
		char A[30];
		strcpy(A,p->HoTen);
		int a=strlen(A);
		if(KiemTra(S,k,A,a))
		{
			XuatSV(p);
			dem++;
		}
	}
	if(dem==0)
		printf("\nkhong co ten can tim\n");
	
}
int KiemTra(char S[],int k,char A[],int a)
{
	if(a==k)
	{
		for(int i=0;i<a;i++)
		{
			if(S[i]!=A[i])
				return 0;
		}
		return 1;
	}
	else
		return 0;
}
void DemSV(List L)
{
	int dem=0;
	for(SV*p=L.pHead;p!=NULL;p=p->pNext)
	{
		if(p->DiemTB>=5)
			dem++;
	}
	if(dem==0)
		printf("\nKhong co SV nao co DTB>=5\n");
	else
		printf("\nSo SV co DTB>=5 la %d\n",dem);
}
void LietKeSV(List L)
{
	float max=L.pHead->DiemTB;
	SV*q=new SV;
	SV*p=new SV;
	for(p=L.pHead;p!=NULL;p=p->pNext)
	{
		if(p->DiemTB>max)
		{
			max=p->DiemTB;
			q=p;
		}
	}
	printf("\nNhung SV co DTB cao nhat \n");
	for(p=L.pHead;p!=NULL;p=p->pNext)
	{
		if(p->DiemTB==max)
		{
			XuatSV(p);
		}
	}
}
void Xuat(List L)
{
	printf("\n");
	for(SV*p=L.pHead;p!=NULL;p=p->pNext)
	{
		XuatSV(p);
	}
}
void XuatSV(SV*p)
{
	printf("%s %s %.1f\n",p->MSSV,p->HoTen,p->DiemTB);
}
void AddTail(List &L,SV *p)
{
	if(L.pHead==NULL)
	{
		L.pHead=p;
		L.pTail=p;
	}
	else
	{
		L.pTail->pNext=p;
		L.pTail=p;
	}
}
void Nhap(List &L)
{
	int n;
	char MS[10];
	char HT[30];
	float DTB;
	printf("Nhap So Sinh Vien : ");
	scanf("%d",&n);
	fflush(stdin);
	for(int i=0;i<n;i++)
	{
		printf("\nNhap thong tin SV thu %d",i+1);
		printf("\nMa So Sinh Vien : ");
		gets(MS);
		fflush(stdin);
		printf("Ten Sinh Vien : ");
		gets(HT);
		fflush(stdin);
		printf("Diem TB : ");
		scanf("%f",&DTB);
		fflush(stdin);
		SV*p=CreateSV(MS,HT,DTB);
		AddTail(L,p);
	}
}
SV*CreateSV(char MS[10],char HT[30],float DTB)
{
	SV*p=new SV;
	if(p==NULL)
		exit(0);
	strcpy(p->MSSV,MS);
	strcpy(p->HoTen,HT);
	p->DiemTB=DTB;
	p->pNext=NULL;
	return p;
}
void CreateList(List &L)
{
	L.pHead=NULL;
	L.pTail=NULL;
}