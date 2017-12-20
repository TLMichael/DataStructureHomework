#include <iostream>
using namespace std;

#define MAXSIZE 20
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
	cout << "¡¾SqList¡¿";
	for (int i = 1; i <= L.length; i++)
	{
		cout << " " << L.elem[i];
	}
	cout << endl;
}

void HeapAdjust(SqList &H, int s, int m)
{
	int j;
	int rc = H.elem[s];
	for (j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && H.elem[j] < H.elem[j + 1])
			j++;
		if (rc >= H.elem[j])
			break;
		H.elem[s] = H.elem[j];
		s = j;
	}
	H.elem[s] = rc;
}

void HeapSort(SqList &H)
{
	int i;
	int temp;
	for (i = H.length / 2; i > 0; i--)
	{
		HeapAdjust(H, i, H.length);
	}
	for (i = H.length; i > 1; i--)
	{
		temp = H.elem[i];
		H.elem[i] = H.elem[1];
		H.elem[1] = temp;
		HeapAdjust(H, 1, i - 1);
	}
}

int main()
{
	SqList L;
	InitSqList(L);
	TraverseSqList(L);

	HeapSort(L);

	TraverseSqList(L);
	
	system("pause");
	return 0;
}