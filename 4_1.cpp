#include<iostream>
using namespace std;
#define MAXSIZE 12500

typedef struct {
	int i, j;
	int e;
}Triple;
typedef struct {
	Triple data[MAXSIZE + 1];
	int mu, nu, tu;
}TSMatrix;

void TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu != 0)
	{
		int q = 1;
		for (int col = 1; col <= M.nu; col++)
		{
			for (int p = 1; p <= M.tu; p++)
			{
				if (M.data[p].j == col)
				{
					T.data[q].i = M.data[p].j;
					T.data[q].j = M.data[p].i;
					T.data[q].e = M.data[p].e;
					q++;
				}
			}
		}

	}
}

void FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
	int *num;
	int *cpot;
	int col, q, p;
	num = (int*)malloc((M.nu+1) * sizeof(int));
	cpot = (int*)malloc((M.nu+1) * sizeof(int));
	T.mu = M.nu;
	T.nu = M.mu;
	T.tu = M.tu;
	if (T.tu != 0)
	{
		memset(num, 0, M.nu * sizeof(int));
		for (int t = 1; t <= M.tu; t++)
		{
			num[M.data[t].j]++;
		}
		cpot[1] = 1;
		for (col = 2; col <= M.nu; col++)
		{
			cpot[col] = cpot[col - 1] + num[col - 1];
		}
		for (p = 1; p <= M.tu; p++)
		{
			col = M.data[p].j;
			q = cpot[col];
			T.data[q].i = M.data[p].j;
			T.data[q].j = M.data[p].i;
			T.data[q].e = M.data[p].e;
			cpot[col]++;
		}
	}
}

void CreateSMatrix(TSMatrix &M)
{
	cout << "input row and col: ";
	cin >> M.mu >> M.nu;
	int count = 1;
	int tmp;
	for (int i = 1; i <= M.mu; i++)
	{
		for (int j = 1; j <= M.nu; j++)
		{
			cin >> tmp;
			if (tmp != 0)
			{
				M.data[count].i = i;
				M.data[count].j = j;
				M.data[count].e = tmp;
				count++;
			}
		}
	}
	M.tu = count - 1;
}

void TraverseSMatrix(TSMatrix M)
{
	cout << "Matrix : i j v" << endl;
	for (int i = 1; i <= M.tu; i++)
	{
		printf("\t%d %d %d\n", M.data[i].i, M.data[i].j, M.data[i].e);
	}
}

int main()
{
	TSMatrix M, T, S;
	CreateSMatrix(M);
	TraverseSMatrix(M);
	TransposeSMatrix(M, T);
	TraverseSMatrix(T);
	FastTransposeSMatrix(M, S);
	TraverseSMatrix(S);
	
	system("pause");
	return 0;
}