#include <iostream>
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

void TraverseSqList(SqList L)
{
	cout << "¡¾SqList¡¿ ";
	for (int i = 1; i <= L.length; i++)
		cout << " " << L.elem[i];
	cout << endl;
}

int Partition(SqList &L, int low, int high)
{
	L.elem[0] = L.elem[low];
	int pivotkey = L.elem[low];
	while (low < high)
	{
		while (low < high && L.elem[high] >= pivotkey)
			high--;
		L.elem[low] = L.elem[high];
		while (low < high && L.elem[low] <= pivotkey)
			low++;
		L.elem[high] = L.elem[low];
	}
	L.elem[low] = L.elem[0];
	return low;
}

void QSort(SqList &L, int low, int high)
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}

void QuickSort(SqList &L)
{
	QSort(L, 1, L.length);
}

int main()
{
	SqList L;
	InitSqList(L);
	TraverseSqList(L);

	QuickSort(L);

	TraverseSqList(L);

	system("pause");
	return 0;
}