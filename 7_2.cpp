#include <iostream>
using namespace std;
const int MAX_VERTEX_NUM = 20;
const int INF = 0x3f3f3f3f;

struct {
	char adjvex;
	int lowcost;
}closedge[MAX_VERTEX_NUM];

typedef enum {
	UDN
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
int loc[MAX_VERTEX_NUM + 100];

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

	for (int i = 0; i < G.vexnum; i++)
	{
		G.vexs[i] = 'a'+ i;
		loc[G.vexs[i]] = i;
	}
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = INF;
	cout << "输入各条边的权值（例如：1 2 5）：" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		int i, j;
		cin >> i >> j >> w;
		
		G.arcs[i - 1][j - 1].adj = G.arcs[j - 1][i - 1].adj = w;
	}
}

void CreateGraph(MGraph &G)
{
	G.kind = UDN;
	switch (G.kind)
	{
	case UDN:return CreateUDN(G);
	default:
		break;
	}
}

int mininum(MGraph G)
{
	int k = 0;
	int min = -1;
	while (min == -1)
	{
		if (closedge[k].lowcost != 0)
			min = k;
		k++;
	}
	for (int i = k; i < G.vexnum; i++)
	{
		if (closedge[i].lowcost < closedge[min].lowcost && closedge[i].lowcost != 0)
		{
			min = i;
		}
	}

	return min;
}

void MiniSpanTree_PRIM(MGraph G, char u)
{
	// 用普里姆算法从第u个顶点出发构造网G的最小生成树T，输出T的各条边。
	// 记录从顶点集U到V－U的代价最小的边的辅助数组定义：
	//  struct {
	//      VertexType  adjvex;
	//      VRType     lowcost;
	//  } closedge[MAX_VERTEX_NUM];
	int cost = 0;
	int i, j, k;
	k = LocateVex(G, u);
	for (j = 0; j < G.vexnum; ++j)
	{
		if (j != k)
		{
			closedge[j].adjvex = u;
			closedge[j].lowcost = G.arcs[k][j].adj;
		}
	}
	closedge[k].lowcost = 0;
	cout << "\n得到最小生成树：\n";
	for (i = 1; i < G.vexnum; ++i)
	{
		k = mininum(G);
		cout << "\t<" << closedge[k].adjvex << "," << G.vexs[k] << ">";
		cost += closedge[k].lowcost;
		closedge[k].lowcost = 0;
		for (j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[k][j].adj < closedge[j].lowcost)
			{
				closedge[j].adjvex = G.vexs[k];
				closedge[j].lowcost = G.arcs[k][j].adj;
			}
		}
	}
	cout << "\n得到最小费用：" << cost << endl;
}

int main()
{
	MGraph G;
	CreateGraph(G);

	MiniSpanTree_PRIM(G, 'a');

	system("pause");
	return 0;
}