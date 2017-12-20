#include <iostream>
#include <time.h>
using namespace std;

#define MAXSIZE	20

typedef struct {
	int elem[MAXSIZE + 1];
	int length;
}SqList;

void InitSqList(SqList &L)
{
	for (int i = 1; i <= MAXSIZE; i++)
	{
		L.elem[i] = rand() % 100;
	}
	L.length = MAXSIZE;
}

void TraverseList(SqList L)
{
	cout << "°æSqList°ø ";
	for (int i = 1; i <= L.length; i++)
		cout << " " << L.elem[i];
	cout << endl;
}

//≤Â»Î≈≈–Ú
void InsertSort(SqList &L)
{
	for (int i = 2; i <= L.length; i++)
	{
		if (L.elem[i] < L.elem[i - 1])
		{
			L.elem[0] = L.elem[i];
			L.elem[i] = L.elem[i - 1];
			int j;
			for (j = i - 2; L.elem[0] < L.elem[j]; --j)
				L.elem[j + 1] = L.elem[j];
			L.elem[j + 1] = L.elem[0];
		}
	}
}

//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(SqList &L)
{
	for (int i = 2; i <= L.length; i++)
	{
		L.elem[0] = L.elem[i];
		int low = 1;
		int high = i - 1;
		while (low <= high)
		{
			int m = (low + high) / 2;
			if (L.elem[0] < L.elem[m])
				high = m - 1;
			else
				low = m + 1;
		}
		for (int j = i - 1; j >= high + 1; --j)
			L.elem[j + 1] = L.elem[j];
		L.elem[high + 1] = L.elem[0];
	}
}

//√∞≈›≈≈–Ú£®Ωªªª≈≈–Ú£©
void BubbleSort(SqList &L)
{
	int temp;
	for (int i = 1; i < L.length; i++)
	{
		for (int j = 1; j < L.length - i; j++)
		{
			if (L.elem[j] > L.elem[j + 1])
			{
				temp = L.elem[j];
				L.elem[j] = L.elem[j + 1];
				L.elem[j + 1] = temp;
			}
		}
	}
}

//—°‘Ò≈≈–Ú
void SelectSort(SqList &L)
{
	int min;
	for (int i = 1; i < L.length; i++)
	{
		int temp;
		min = i;
		for (int j = i + 1; j <= L.length; j++)
		{
			if (L.elem[j] < L.elem[min])
				min = j;
		}
		if (min != i)
		{
			temp = L.elem[i];
			L.elem[i] = L.elem[min];
			L.elem[min] = temp;
		}
	}
}

void Merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k;
	for (j = m + 1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
	if (i <= m)
	{
		while (k <= n && i <= m)
			TR[k++] = SR[i++];
	}
	if (j <= n)
	{
		while (k <= n && j <= n)
			TR[k++] = SR[j++];
	}
}
void MSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[21];
	if (s == t)
		TR1[t] = SR[s];
	else
	{
		m = (s + t) / 2;
		MSort(SR, TR2, s, m);
		MSort(SR, TR2, m + 1, t);
		Merge(TR2, TR1, s, m, t);
	}
}
//πÈ≤¢≈≈–Ú
void MergeSort(SqList &L)
{
	MSort(L.elem, L.elem, 1, L.length);
}

int main()
{	static SqList L;
	cout << "°æΩªªª≈≈–Ú°ø" << endl;
	InitSqList(L);
	TraverseList(L);
	BubbleSort(L);
	TraverseList(L);

	cout << "°æ—°‘Ò≈≈–Ú°ø" << endl ;
	InitSqList(L);
	TraverseList(L);
	SelectSort(L);
	TraverseList(L);

	cout << "°æπÈ≤¢≈≈–Ú°ø" << endl;
	InitSqList(L);
	TraverseList(L);
	MergeSort(L);
	TraverseList(L);

	system("pause");
	return 0;
}