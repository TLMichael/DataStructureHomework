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
		cout << "���Ա�Ϊ�գ�" << endl;
	cout << "���Ա�����" << ListLength_Sq(L) << "��Ԫ�ء�" << endl;
	GetElem_Sq(L, 2, e);
	cout << "���Ա��еĵ�2��Ԫ��Ϊ��" << e << endl;
	cout << "����һ������";
	cin >> e;
	int loc = LocateElem_Sq(L, e);
	if (loc == 0)
		cout << "���Ա��в�����" << e << endl;
	else
		cout << "���Ա�ĵ�" << loc << "��Ԫ����" << e << endl;
	cout << "��������Ѱ��ǰ���ͺ��Ԫ�أ�" << endl;
	PriorElem_Sq(L, 5, pre_e);
	cout << "5��ǰһ��Ԫ���ǣ�" << pre_e << endl;
	NextElem_Sq(L, 5, next_e);
	cout << "5�ĺ�һ��Ԫ���ǣ�" << next_e << endl;
	cout << "������������Ԫ�أ�" << endl;
	if (ListInsert_Sq(L, 2, 666))
		cout << "�ɹ��ڵڶ���λ�ò���666" << endl;
	else
		cout << "����ʧ��" << endl;
	cout << "���Ա��ʱ��״̬��" << endl;
	ListTraverse_Sq(L);
	cout << "��������ɾ��Ԫ�أ�" << endl;
	if (ListDelete_Sq(L, 3, e))
		cout << "�ɹ�ɾ��������Ԫ��" << e << endl;
	else
		cout << "ɾ��ʧ��" << endl;
	cout << "���Ա��ʱ��״̬��" << endl;
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
	cout << "������Ԫ�صĸ�����";
	cin >> n;
	cout << "��ֱ�����" << n << "��Ԫ��:" << endl;
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
		cout << "�����Ա�L�в�����" << cur_e << "��ǰ����";
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
		cout << "�����Ա�L�в�����" << cur_e << "�ĺ�̣�";
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