#include <iostream>
using namespace std;
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

struct SqList
{
	int *elem;
	int length;
	int listsize;
};
void InitList_Sq(SqList &L) {
	L.elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem)	exit(0);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void CreateList_Sq(SqList &L) {
	int n;
	cout << "输入元素个数：";
	cin >> n;
	cout << "随机创建线性表..." << endl;
	for (int i = 0; i<n; i++)
		L.elem[i] = rand()%100;
	L.length = n;
}
void DestroyList_Sq(SqList &L)
{
	free(L.elem);
}
void Inverse_Sq(SqList &L) {
	for (int i = 0; i<L.length / 2; i++)
		swap(L.elem[i], L.elem[L.length - 1 - i]);
}
void ListTraverse_Sq(SqList L) {
	for (int i = 0; i<L.length; i++)
		cout << L.elem[i] << " ";
	cout << endl;
}
int main() {
	SqList L;
	InitList_Sq(L);
	CreateList_Sq(L);
	cout << "转置前：" << endl;
	ListTraverse_Sq(L);
	Inverse_Sq(L);
	cout << "转置后：" << endl;
	ListTraverse_Sq(L);

	DestroyList_Sq(L);
	system("pause");
	return 0;
}