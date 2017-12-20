#include <iostream>
#include <queue>
using namespace std;
const int MAX_VERTEX_NUM = 20;
const int INF = 0x3f3f3f3f;

typedef enum {
	DG, DN, UDG, UDN
}GraphKind;
typedef struct ArcCell {
	int adj;
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
	char vexs[MAX_VERTEX_NUM];
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
}MGraph;
int loc[MAX_VERTEX_NUM + 100], visited[MAX_VERTEX_NUM];

int LocateVex(MGraph G, char c)
{
	if (loc[c] >= 0)
		return loc[c];
	else
		return -1;
}

void CreateUDN(MGraph &G)
{
	char s, t;
	int w;
	cout << "点数，边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入点（例如：a b c）:" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
		loc[G.vexs[i]] = i;
	}
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INF;
	cout << "输入各条边的权值（例如：a b 5）：" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> s >> t >> w;
		int i = LocateVex(G, s);
		int j = LocateVex(G, t);
		G.arcs[i][j].adj = G.arcs[j][i].adj = w;
	}
}

void CreateDN(MGraph &G)
{
	char s, t;
	int w;
	cout << "点数，边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入点（例如：a b c）：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
		loc[G.vexs[i]] = i;
	}
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INF;
	cout << "输入各条边的权值：（例如：a b 5）" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> s >> t >> w;
		int i = LocateVex(G, s);
		int j = LocateVex(G, t);
		G.arcs[i][j].adj = w;
	}
}

void CreateUDG(MGraph &G)
{
	char s, t;
	int w;
	cout << "点数，边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入点（例如：a b c）：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
		loc[G.vexs[i]] = i;
	}
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = 0;
	cout << "输入存在的边（例如：a b 1）：" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> s >> t >> w;
		int i = LocateVex(G, s);
		int j = LocateVex(G, t);
		G.arcs[i][j].adj = G.arcs[j][i].adj = w;
	}
}

void CreateDG(MGraph &G)
{
	char s, t;
	int w;
	cout << "点数，边数：";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入点（例如：a b c）：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vexs[i];
		loc[G.vexs[i]] = i;
	}
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = 0;
	cout << "输入存在的边（例如：a b 1）：" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> s >> t >> w;
		int i = LocateVex(G, s);
		int j = LocateVex(G, t);
		G.arcs[i][j].adj = w;
	}
}

void CreateGraph(MGraph &G)
{
	cout << "输入图类型(0:DG|1:DN|2:UDG|3:UDN)：";
	cin >> (int&)G.kind;
	switch (G.kind)
	{
	case DG:return CreateDG(G);
	case DN:return CreateDN(G);
	case UDG:return CreateUDG(G);
	case UDN:return CreateUDN(G);
	default:
		break;
	}
}

void DestroyGraph(MGraph &G)
{
	return;
}

char GetVex(MGraph &G, int v)
{
	return G.vexs[v];
}

void PutVex(MGraph &G, int v, char value)
{
	G.vexs[v] = value;
}

int FirstAdjVex(MGraph G, int v)
{
	switch (G.kind)
	{
	case DG:
	case UDG:
	{
		for (int i = 0; i < G.vexnum; i++)
			if (G.arcs[v][i].adj == 1)
				return i;
		break;
	}
	case DN:
	case UDN:
	{
		for (int i = 0; i < G.vexnum; i++)
			if (G.arcs[v][i].adj != INF)
				return i;
		break;
	}
	default:
		break;
	}
	return -1;
}

int NextAdjVex(MGraph G, int v, int w)
{
	switch (G.kind)
	{
	case DG:
	case UDG:
	{
		for (int i = w + 1; i < G.vexnum; i++)
			if (G.arcs[v][i].adj == 1)
				return i;
		break;
	}
	case DN:
	case UDN:
	{
		for (int i = w + 1; i < G.vexnum; i++)
			if (G.arcs[v][i].adj != INF)
				return i;
		break;
	}
	default:
		break;
	}
	return -1;
}

void InsertVex(MGraph &G, char v)
{
	switch (G.kind)
	{
	case DG:
	case UDG:
	{
		G.vexs[G.vexnum] = v;
		for (int i = 0; i < G.vexnum; i++)
		{
			G.arcs[i][G.vexnum].adj = G.arcs[G.vexnum][i].adj = 0;
		}
		G.vexnum++;
	}
	case DN:
	case UDN:
	{
		G.vexs[G.vexnum] = v;
		for (int i = 0; i < G.vexnum; i++)
		{
			G.arcs[i][G.vexnum].adj = G.arcs[G.vexnum][i].adj = INF;
		}
		G.vexnum++;
	}
	default:
		break;
	}
}

void DeleteVex(MGraph &G, char v)
{
	int p = LocateVex(G, v);
	int count = 0;
	switch (G.kind)
	{
	case DG:
	{
		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[i][p].adj != 0)
				count++;
			if (G.arcs[p][i].adj != 0)
				count++;
		}
		break;
	}
	case DN:
	{
		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[i][p].adj != INF)
				count++;
			if (G.arcs[p][i].adj != INF)
				count++;
		}
		break;
	}
	case UDG:
	{
		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[i][p].adj != 0)
				count++;
		}
		break;
	}
	case UDN:
	{
		for (int i = 0; i < G.vexnum; i++)
		{
			if (G.arcs[i][p].adj != INF)
				count++;
		}
		break;
	}
	default:
		break;
	}
	for (int i = p; i < G.vexnum - 1; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = G.arcs[i + 1][j];
	for (int j = p; j < G.vexnum - 1; j++)
		for (int i = 0; i < G.vexnum; i++)
			G.arcs[i][j] = G.arcs[i][j + 1];
	G.arcnum = G.arcnum - count;
	G.vexnum--;
}

void InsertArc(MGraph &G, char v, char w)
{
	int i = LocateVex(G, v);
	int j = LocateVex(G, w);
	switch (G.kind)
	{
	case DG:
	{
		G.arcs[i][j].adj = 1;
		break;
	}
	case DN:
	{
		G.arcs[i][j].adj = 0x3f3f;
		break;
	}
	case UDG:
	{
		G.arcs[i][j].adj = G.arcs[j][i].adj = 1;
		break;
	}
	case UDN:
	{
		G.arcs[i][j].adj = G.arcs[j][i].adj = 0x3f3f;
		break;
	}
	default:
		break;
	}
	G.arcnum++;
}

void DeleteArc(MGraph &G, char v, char w)
{
	int  i = LocateVex(G, v);
	int j = LocateVex(G, w);
	switch (G.kind)
	{
	case DG:
	{
		G.arcs[i][j].adj = 0;
		break;
	}
	case DN:
	{
		G.arcs[i][j].adj = INF;
		break;
	}
	case UDG:
	{
		G.arcs[i][j].adj = G.arcs[j][i].adj = 0;
		break;
	}
	case UDN:
	{
		G.arcs[i][j].adj = G.arcs[j][i].adj = INF;
		break;
	}
	default:
		break;
	}
	G.arcnum--;
}

void DFS(MGraph G, int v)
{
	visited[v] = 1;
	cout << G.vexs[v] << " ";
	for (int w = FirstAdjVex(G, v); w != -1; w = NextAdjVex(G, v, w))
		if (!visited[w])
			DFS(G, w);
}

void DFSTraverse(MGraph G)
{
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
			DFS(G, i);
	}
	cout << endl;
}

void BFSTraverse(MGraph G)
{
	memset(visited, 0, sizeof(visited));
	queue<int> q;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << G.vexs[i] << " ";
			q.push(i);
			while (!q.empty())
			{
				int u = q.front();
				q.pop();
				for (int w = FirstAdjVex(G, u); w != -1; w = NextAdjVex(G, u, w))
					if (!visited[w])
					{
						visited[w] = 1;
						cout << G.vexs[w] << " ";
						q.push(w);
					}
			}
		}
	}
	cout << endl;
}

int main()
{
	MGraph G;
	CreateGraph(G);
	cout << "深度优先遍历:  ";
	DFSTraverse(G);
	cout << "广度优先遍历： ";
	BFSTraverse(G);

	DestroyGraph(G);

	system("pause");
	return 0;
}