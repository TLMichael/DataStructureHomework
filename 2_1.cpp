#include<iostream>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

struct SqList
{
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
	cout << "随机生成" << n << "个元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		L.elem[i] = rand()%100;
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

void InsertSort_Sq(SqList &L)
{
	int n = L.length;
	int j, t;
	L.length = 0;
	for (int i = 0; i < n; i++)
	{
		j = 0; 
		t = L.elem[i];
		while (j < L.length && L.elem[j] < L.elem[i])
			j++;
		for (int k = L.length; k > j; k--)
			L.elem[k] = L.elem[k - 1];
		L.elem[j] = t;
		L.length++;
	}
}

int main()
{
	SqList L;
	InitList_Sq(L);
	CreateList_Sq(L);
	cout << "线性表：";
	ListTraverse_Sq(L);
	cout << "进行插入排序..." << endl;
	InsertSort_Sq(L);
	cout << "结  果：";
	ListTraverse_Sq(L);

	DestroyList_Sq(L);
	system("pause");
	return 0;
}