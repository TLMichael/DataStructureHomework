#include <iostream>
using namespace std;

int hashsize[] = { 11, 47, 199, 499, 997 };
typedef struct {
	int *elem;
	int count;
	int sizeindex;
}HashTable;

#define SUCCESS		1
#define	UNSUCCESS	0
#define DUPLICATE	-1

bool InitHash(HashTable &H)
{
	H.elem = (int*)malloc(hashsize[0] * sizeof(int));
	memset(H.elem, 0, sizeof(int) * hashsize[0]);
	H.count = 0;
	H.sizeindex = 0;
	return SUCCESS;
}

bool RecreateHashTable(HashTable &H)
{
	H.sizeindex++;
	H.elem = (int *)realloc(H.elem, hashsize[H.sizeindex] * sizeof(int));
	return SUCCESS;
}

int myhash(HashTable H, int K)
{
	int hashVal = K % hashsize[H.sizeindex];
	if (hashVal < 0)
		hashVal += hashsize[H.sizeindex];
	return hashVal;
}

int SearchHash(HashTable H, int K, int &p, int &c)
{
	int i = 2;
	p = myhash(H, K);
	while (H.elem[p] != NULL && K != H.elem[p])
	{
		p = (p + (i / 2)*(i / 2)) % hashsize[H.sizeindex];
		i++;
	}
	if (K == H.elem[p])
		return SUCCESS;
	else
		return UNSUCCESS;
}

int InsertHash(HashTable &H, int e)
{
	int c = 0;
	int p = 0;
	if (SearchHash(H, e, p, c) == SUCCESS)
		return DUPLICATE;
	else if (c < hashsize[H.sizeindex] / 2)
	{
		H.elem[p] = e;
		H.count++;
		return true;
	}
	else
	{
		RecreateHashTable(H);
		return false;
	}
}

bool DeleteHash(HashTable H, int e)
{
	int p;
	int c = p = 0;
	if (SearchHash(H, e, p, c) != SUCCESS)
		return false;
	else
	{
		H.elem[p] = NULL;
		H.count--;
		return true;
	}
}

bool TraverseHash(HashTable H)
{
	cout << "HashTable:";
	for (int i = 0; i < hashsize[H.sizeindex]; i++)
	{
		cout << "\t" << H.elem[i];
	}
	cout << endl;
	return true;
}

bool DestroyHash(HashTable H)
{
	free(H.elem);
	return true;
}

int main()
{
	HashTable H;

	InitHash(H);
	InsertHash(H, 3);
	InsertHash(H, 6);
	InsertHash(H, 109);
	InsertHash(H, 200);
	InsertHash(H, 88);

	TraverseHash(H);

	DeleteHash(H, 6);
	DeleteHash(H, 200);
	TraverseHash(H);

	DestroyHash(H);

	system("pause");
	return 0;
}