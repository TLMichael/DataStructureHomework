#include<iostream>
using namespace std;

typedef struct CSNode {
	int data;
	struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

void CreateCSTree(CSTree &T)
{
	int t;
	cin >> t;
	if (t == -1)
		T = NULL;
	else
	{
		T = (CSTree)malloc(sizeof(CSNode));
		T->data = t;
		CreateCSTree(T->firstchild);
		CreateCSTree(T->nextsibling);
	}
}

void DestroyCSTree(CSTree &T)
{
	if (T != NULL)
	{
		DestroyCSTree(T->firstchild);
		DestroyCSTree(T->nextsibling);
		free(T);
	}
}

//利用中序遍历CSTree，即可得到广义表的格式
void PrintCSTree(CSTree T)
{
	if (T != NULL)
	{
		cout << T->data;
		if (T->firstchild != NULL)
			cout << "(";
		PrintCSTree(T->firstchild);
		if (T->firstchild != NULL)
			cout << ")";
		if (T->nextsibling != NULL)
			cout << ", ";
		PrintCSTree(T->nextsibling);
	}
}

int main()
{
	CSTree T;
	cout << "Please input T: " << endl;
	cout << "(example:1 2 5 -1 6 -1 -1 3 -1 4 7 8 -1 9 -1 10 -1 -1 -1 -1 -1)" << endl;
	cout << "(example:6 7 -1 -1 8 -1 -1)" << endl;
	CreateCSTree(T);

	cout << "\nInOrderTraverse:\t";
	PrintCSTree(T);
	cout << endl;

	DestroyCSTree(T);
	system("pause");
	return 0;
}