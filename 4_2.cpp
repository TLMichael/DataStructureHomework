#include<iostream>
using namespace std;

int main()
{
	int A[20][6] = { 0 };
	for (int i = 0; i < 20; i++)
		A[i][5] = 5;
	int N;
	cin >> N;
	int t;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		if (t > 5)
			exit(0);
		for (int j = 0; j < 20; j++)
		{
			if (A[j][5] >= t)
			{
				
				for (int k = 5-A[j][5]; k < 5 - A[j][5]+t; k++)
				{
					A[j][k] = 1;
					cout << j*5+k+1 << " ";
				}
				A[j][5] -= t;
				cout << endl;
				flag = true;
				break;
			}
		}
		if (flag = true)
			continue;
		else
		{
			int c = 0;
			while (t > 0)
			{
				if (A[c][5] > 0)
				{
					if (t > A[c][5])
					{
						t -= A[c][5];
						for (int k = 5 - A[c][5]; k < 5; k++)
						{
							A[c][k] = 1;
							cout << c*5+k+1 << " ";
						}
						A[c][5] = 0;
					}
					else
					{
						for (int k = 5 - A[c][5]; k < 5 - A[c][5] + t; k++)
						{
							A[c][k] = 1;
							cout << c*5+k+1 << " ";
						}
						A[c][5] = A[c][5] - t;
						t = 0;
					}
				}
				c++;
				if (c == 20)
					exit(0);
				
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}