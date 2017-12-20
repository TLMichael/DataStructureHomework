#include <iostream>
#include <stack>
using namespace std;
const int MAX_VERTEX_NUM = 20;
const int INF = 0x3f3f3f3f;
typedef struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	int info;
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
int ve[MAX_VERTEX_NUM];
int vl[MAX_VERTEX_NUM];


int LocateVex(ALGraph G, char c)
{
	if (loc[c] >= 0)
		return loc[c];
	else
		return -1;
}
void CreateDN(ALGraph &G)
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
		p->info = w;
		p->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p;
	}
}

bool TopologicalOrder(ALGraph G, stack<int> &T)
{
	// 有向网G采用邻接表存储结构，求各顶点实践的最早发生时间ve（全局变量）
	// T为拓扑序列顶点栈，S为零入度顶点栈
	// 若G无回路，则用栈T返回G的一个拓扑序列，且函数值为true，否则为false
	stack<int> S;	//入度为0顶点栈S
	int count = 0, j, k;
	ArcNode *p;
	for (j = 0; j < G.vexnum; j++)		//入读为0者进栈
	{
		if (indegree[j] == 0)
			S.push(j);
	}
	memset(ve, 0, sizeof(ve));
	while (!S.empty())
	{
		j = S.top();	S.pop();	T.push(j);
		count++;								//对入栈T的顶点进行计数
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			if (--indegree[k] == 0)				//对j号顶点的每个邻接点的入度减1
				S.push(k);						//若入度减为0，则入栈
			if (ve[j] + p->info > ve[k])
				ve[k] = ve[j] + p->info;		//ve(k) = Max{ve(j) + dut(<j, k>)}
		}
	}
	if (count < G.vexnum)
		return false;
	else
		return true;
}

void CriticalPath(ALGraph G)
{
	stack<int> T;
	int a, j, k, el, ee, dut;
	char tag;
	ArcNode *p;
	if (!TopologicalOrder(G, T))
	{
		cout << "图有回路" << endl;
		return;
	}
	for (a = 0; a < G.vexnum; a++)
	{
		vl[a] = ve[G.vexnum - 1];
	}
	while (!T.empty())
	{
		for (j = T.top(), T.pop(), p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = p->info;
			if (vl[j] > vl[k] - dut)
				vl[j] = vl[k] - dut;
		}
	}
	cout << "关键活动：" << endl;
	cout << "起点\t终点\tdut\tee\tel\ttag\n";
	for (j = 0; j < G.vexnum; j++)
		for (p = G.vertices[j].firstarc; p; p = p->nextarc)
		{
			k = p->adjvex;
			dut = p->info;
			ee = ve[j];
			el = vl[k] - dut;
			tag = (ee == el) ? '*' : ' ';
			cout << G.vertices[j].data << "\t" << G.vertices[k].data << "\t" 
				<< dut << "\t" << ee << "\t" << el << "\t" << tag << endl;
		}
}

int main()
{
	ALGraph G;
	CreateDN(G);

	CriticalPath(G);

	system("pause");
	return 0;
}