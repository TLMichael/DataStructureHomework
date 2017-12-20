#include<iostream>

using namespace std;

#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

struct SqList {
	int *elem;
	int length;
	int listsize;
};

void InitList_Sq(SqList &L)
{
	L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem) exit(0);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}

void CreateList_Sq(SqList &L)
{
	int n;
	cout << "请输入元素的个数：";
	cin >> n;
	cout << "随机生成了" << n << "个元素" << endl;
	for (int i = 0; i < n; i++)
	{
		L.elem[i] = rand() % 100;
	}
	L.length = n;
}

void DestroyList_Sq(SqList &L)
{
	free(L.elem);
}

void ListTraverse_Sq(SqList L) {
	for (int i = 0; i<L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}

void MergeList_Sq(SqList &L1, SqList L2)
{
	L1.elem = (int *)realloc(L1.elem, (L1.length + L2.length + LISTINCREMENT) * sizeof(int));
	int n = L2.length;
	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j < L1.length && L1.elem[j] < L2.elem[i])
			j++;
		for (int k = L1.length; k > j; k--)
			L1.elem[k] = L1.elem[k - 1];
		L1.elem[j] = L2.elem[i];
		L1.length++;
	}
}

int main() {
	SqList L1, L2;
	InitList_Sq(L1);
	InitList_Sq(L2);

	cout << "正在生成L1...     ";
	CreateList_Sq(L1);
	cout << "正在生成L2...     ";
	CreateList_Sq(L2);

	cout << "L1:";
	ListTraverse_Sq(L1);
	cout << "L2:";
	ListTraverse_Sq(L2);

	cout << "正在合并..." << endl;
	MergeList_Sq(L1, L2);
	cout << "L1:" << endl;
	ListTraverse_Sq(L1);

	DestroyList_Sq(L1);
	DestroyList_Sq(L2);
	system("pause");
	return 0;
}