#include<iostream>
using namespace std;

struct e {
	int x1, x2, y1, y2;
}buf[11];//�洢�򿪴��ڵĶ�������

int main() 
{
	int n, m, i, j;
	int a[11][2];//�洢���������
	int cengci[11] = { 0,1,2,3,4,5,6,7,8,9,10 };
	cin >> n >> m;

	for (i = 1; i <= n; i++) 
	{
		cin >> buf[i].x1 >> buf[i].y1 >> buf[i].x2 >> buf[i].y2;
	}
	for (i = 1; i <= m; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}


	for (i = 1; i <= m; i++) 
	{
		bool zai = false;
		for (j = n; j>0; j--) {//�Ӷ��㿪ʼ���ο��Ƿ��ڴ�����
			if (a[i][0] >= buf[cengci[j]].x1&&a[i][0] <= buf[cengci[j]].x2
				&&a[i][1] >= buf[cengci[j]].y1&&a[i][1] <= buf[cengci[j]].y2) 
			{
				cout << cengci[j] << endl;;//������ڲ�
				zai = true;
				cengci[n] = j;//Ų�����
				for (int x = j; x<n; x++) 
				{
					cengci[x] = cengci[x + 1];
				}//�ı���˳��
				break;
			}

		}
		if (zai == false) 
		{
			cout << "IGNORED" << endl;
		}

	}

	system("pause");
	return 0;
}