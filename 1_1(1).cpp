#include<iostream>

using namespace std;

#define LIST_INIT_SIZE	100
#define LISTINCREMENT	10

struct SqList {
	int *elem;
	int length;
	int listsize;
};

void InitList_Sq(SqList &L);
void DestroyList_Sq(SqList &L);
void ClearList_Sq(SqList &L);
bool ListEmpty_Sq(SqList L);
int	ListLength_Sq(SqList L);
void GetElem_Sq(SqList L, int i, int &e);
int LocateElem_Sq(SqList L, int e);
void PriorElem_Sq(SqList L, int cur_e, int &pre_e);
void NextElem_Sq(SqList L, int cur_e, int &next_e);
bool ListInsert_Sq(SqList &L, int i, int e);
bool ListDelete_Sq(SqList &L, int i, int &e);
void ListTraverse_Sq(SqList L);
void CreateList_Sq(SqList &L);

int main()
{
	SqList L;
	int e, pre_e, next_e;
	InitList_Sq(L);
	CreateList_Sq(L);
	if (ListEmpty_Sq(L))
		cout << "线性表为空！" << endl;
	cout << "线性表中有" << ListLength_Sq(L) << "个元素。" << endl;
	GetElem_Sq(L, 2, e);
	cout << "线性表中的第2个元素为：" << e << endl;
	cout << "输入一个数：";
	cin >> e;
	int loc = LocateElem_Sq(L, e);
	if (loc == 0)
		cout << "线性表中不存在" << e << endl;
	else
		cout << "线性表的第" << loc << "个元素是" << e << endl;
	cout << "举例——寻找前驱和后继元素：" << endl;
	PriorElem_Sq(L, 5, pre_e);
	cout << "5的前一个元素是：" << pre_e << endl;
	NextElem_Sq(L, 5, next_e);
	cout << "5的后一个元素是：" << next_e << endl;
	cout << "举例——插入元素：" << endl;
	if (ListInsert_Sq(L, 2, 666))
		cout << "成功在第二个位置插入666" << endl;
	else
		cout << "插入失败" << endl;
	cout << "线性表此时的状态：" << endl;
	ListTraverse_Sq(L);
	cout << "举例——删除元素：" << endl;
	if (ListDelete_Sq(L, 3, e))
		cout << "成功删除第三个元素" << e << endl;
	else
		cout << "删除失败" << endl;
	cout << "线性表此时的状态：" << endl;
	ListTraverse_Sq(L);
	DestroyList_Sq(L);
	system("pause");
	return 0;
}

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
	cout << "请分别输入" << n << "个元素:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> L.elem[i];
	}
	L.length = n;
	L.listsize=LIST_INIT_SIZE;
}

void DestroyList_Sq(SqList &L)
{
	free(L.elem);
}

void ClearList_Sq(SqList &L)
{
	free(L.elem);
	L.length = 0;
	L.listsize = 0;
}

bool ListEmpty_Sq(SqList L)
{
	return !L.length;
}

int ListLength_Sq(SqList L)
{
	return L.length;
}

void GetElem_Sq(SqList L, int i, int &e)
{
	e = L.elem[i - 1];
}

int LocateElem_Sq(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}

void PriorElem_Sq(SqList L, int cur_e, int &pre_e)
{
	bool flag = false;
	for (int i = 0; i < L.length; i++)
	{
		if (i != 0 && L.elem[i] == cur_e)
		{
			pre_e = L.elem[i - 1];
			flag = true;
		}
	}
	if (flag == false)
		cout << "（线性表L中不存在" << cur_e << "的前驱）";
}

void NextElem_Sq(SqList L, int cur_e, int &next_e)
{
	bool flag = false;
	for (int i = 0; i < L.length; i++)
	{
		if (i != L.length - 1 && L.elem[i] == cur_e)
		{
			next_e = L.elem[cur_e];
			flag = true;
		}
	}
	if(flag == false)
		cout << "（线性表L中不存在" << cur_e << "的后继）";
}

bool ListInsert_Sq(SqList &L, int i, int e) 
{
	if (i<1 || i>L.length + 1)	return false;
	if (L.length == L.listsize) {
		L.elem = (int *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
		if (!L.elem)	exit(0);
		L.listsize += LISTINCREMENT;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	L.length++;
	return true;
}
bool ListDelete_Sq(SqList &L, int i, int &e) 
{
	if (i<1 || i>L.length)	return false;
	e = L.elem[i - 1];
	for (int j = i - 1; j<L.length - 1; j++)
		L.elem[j] = L.elem[j + 1];
	L.length--;
	return true;
}
void ListTraverse_Sq(SqList L) {
	for (int i = 0; i<L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}