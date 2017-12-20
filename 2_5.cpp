#include<iostream>
using namespace std;
struct SqList {
	int *elem;
	int length;
};

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
	int n;
	cout << "Please input an positive integer \"n\":";
	cin >> n;
	L.length = n;
	L.elem = (int *)malloc(L.length * sizeof(int));
	cout << "Please input " << n << "positive integers:";
	for (int i = 0; i < L.length; i++)
	{
		cin >> L.elem[i];
	}
	InsertSort_Sq(L);

	int i, j;
	if(n % 2 == 0)
	{
		if (L.elem[n / 2 - 1] != L.elem[n / 2])
		{
			cout << -1 << endl;
		}
		else
		{
			i = n / 2 - 2;
			j = n / 2 + 1;
			while (i != -1)
			{
				if (L.elem[i] == L.elem[n / 2 - 1] && L.elem[j] == L.elem[n / 2])
				{
					i--;
					j++;
				}
				else if (L.elem[i] != L.elem[n / 2 - 1] && L.elem[j] != L.elem[n / 2])
				{
					cout << L.elem[n / 2] << endl;
					break;
				}
				else
				{
					cout << -1 << endl;
					break;
				}
			}
			if (i == -1)
				cout << L.elem[n / 2] << endl;
		}
	}
	else
	{
		i = n / 2 - 1;
		j = n / 2 + 1;
		while (i != -1)
		{
			if (L.elem[i] == L.elem[n / 2] && L.elem[j] == L.elem[n / 2])
			{
				i--;
				j++;
			}
			else if(L.elem[i]!=L.elem[n/2] && L.elem[j] !=L.elem[n/2])
			{
				cout << L.elem[n / 2] << endl;
			}
			else
			{
				cout << -1 << endl;
				break;
			}
		}
		if (i == -1)
			cout << L.elem[n / 2] << endl;
	}



	system("pause");
	return 0;
}