#include <iostream>
#include <queue>
using namespace std;
const int MAX_VERTEX_NUM = 20;
const int INF = 0x3f3f3f3f;
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *nextarc;
	int w;
}ArcNode;
typedef struct VNode {
	char data;
	ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX_NUM];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;
int loc[MAX_VERTEX_NUM + 100];
int indegree[MAX_VERTEX_NUM];
int LocateVex(ALGraph G, char c)
{
	if (loc[c] >= 0)
		return loc[c];
	else
		return -1;
}
void CreateDG(ALGraph &G)
{
	char s, t;
	int w;
	ArcNode *p;
	memset(loc, 0, sizeof(loc));
	memset(indegree, 0, sizeof(indegree));
	cout << "点数，边数:";
	cin >> G.vexnum >> G.arcnum;
	cout << "输入点（例如：a b c）：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
		loc[G.vertices[i].data] = i;
	}
	cout << "输入存在的边（例如：a b 1）：" << endl;
	for (int k = 0; k < G.arcnum; k++)
	{
		cin >> s >> t >> w; 
		int i = LocateVex(G, s);
		int j = LocateVex(G, t);
		indegree[j]++;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = j;
		p->w = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
	}
}

void TopologicalSort(ALGraph G)
{
	int count = 0;
	queue<int> q;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (!indegree[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int i = q.front(); q.pop();
		cout << G.vertices[i].data << " ";
		count++;
		for (ArcNode *j = G.vertices[i].firstarc; j != NULL; j = j->nextarc)
		{
			int k = j->adjvex;
			if (!(--indegree[k]))
				q.push(k);
		}
	}
	if (count < G.vexnum)
	{
		cout << "该图有回路！" << endl;
		return;
	}
	cout << endl;
}

int main()
{
	ALGraph G;
	CreateDG(G);
	cout << "拓扑排序:\n";
	TopologicalSort(G);

	system("pause");
	return 0;
} 