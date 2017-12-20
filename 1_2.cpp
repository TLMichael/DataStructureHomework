#include <iostream>
#include <stdlib.h>
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
	L.elem = new int[LIST_INIT_SIZE];
	if (!L.elem)	return;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
}
void CreateList_Sq(SqList &L) {
	int n;
	cout << "Please input number:";
	cin >> n;
	cout << "..." << endl;
	for (int i = 0; i<n; i++)
		L.elem[i] = rand()%100;
	L.length = n;
}
void DestroyList_Sq(SqList &L)
{
	delete []L.elem;
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
	cout << "111" << endl;
	ListTraverse_Sq(L);
	Inverse_Sq(L);
	cout << "222" << endl;
	ListTraverse_Sq(L);

	DestroyList_Sq(L);
	
	return 0;
}
