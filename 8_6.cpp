#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define MAX_NUM_OF_KEY	8
#define RADIX			10
#define MAX_SPACE		1000
#define KeysType char
typedef struct {
	KeysType keys[MAX_NUM_OF_KEY];
	//InfoType otheritems;
	int next;
}SLCell;
typedef struct {
	SLCell r[MAX_SPACE];
	int keynum;
	int recnum;
}SLList;
typedef int ArrType[RADIX];

void InitSLList(SLList &L)
{
	L.keynum = 3;
	L.recnum = 20;
	for (int i = 1; i <= 20; i++)
	{
		stringstream stream;
		int num = rand() % 1000;
		if (num >= 100)
		{
			stream << num;
		}
		else if (num >= 10)
		{
			stream << 0 << num;
		}
		else if (num >= 0)
		{
			stream << 0 << 0 << num;
		}
		string keys = stream.str();
		strcpy(L.r[i].keys, keys.c_str());
	}
	for (int i = 1; i <= L.recnum; i++)
		L.r[i - 1].next = i;
}

void TraverseSLList(SLList L)
{
	cout << "¡¾RadixSort¡¿" << endl;
	for (int i = L.r[0].next; i; i = L.r[i].next)
	{
		cout << " ";
		for (int j = 0; j < L.keynum; j++)
		{
			cout << L.r[i].keys[j];
		}
	}
	cout << endl;
}

void Distribute(SLList &L, int i, ArrType &f, ArrType &e)
{
	int j, p;
	for (j = 0; j < RADIX; j++)
		f[j] = 0;
	for (p = L.r[0].next; p; p = L.r[p].next)
	{
		j = (int)L.r[p].keys[i] - '0';
		if (!f[j])
			f[j] = p;
		else
			L.r[e[j]].next = p;
		e[j] = p;
	}
}

void Collect(SLList &L, int i, ArrType f, ArrType e)
{
	int j, t;
	for (j = 0; !f[j]; j++);
	L.r[0].next = f[j];
	t = e[j];
	while (j < RADIX)
	{
		for (j = j + 1; j < RADIX && !f[j]; j++);
		if (j < RADIX)
		{
			L.r[t].next = f[j];
			t = e[j];
		}
	}
	L.r[t].next = 0;
}

void RadixSort(SLList &L)
{
	int i;
	ArrType f, e;
	for (i = 1; i <= L.recnum; i++)
		L.r[i - 1].next = i;
	L.r[L.recnum].next = 0;
	for (i = L.keynum - 1; i >= 0; i--)
	{
		Distribute(L, i, f, e);
		Collect(L, i, f, e);
		TraverseSLList(L);
		//print_SLList2(L, i);
	}
}



int main()
{
	SLList L;
	InitSLList(L);
	TraverseSLList(L);
	RadixSort(L);

	system("pause");
	return 0;
}