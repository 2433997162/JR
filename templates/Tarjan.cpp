#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
const int maxn = 1000005;
int n,m,u,v;

//有向图
int cnt;
int head[maxn],tnext[maxn],to[maxn];

//Tarjan
int Index;	
int dfn[maxn],low[maxn];
bool vis[maxn];//是否在栈里
stack<int>stk;

void add (int u,int v)
{
	tnext[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
}

void Tarjan (int u)
{
	dfn[u]=low[u]=++Index;
	stk.push(u);
	vis[u]=true;
	for (int e=head[u];e;e=tnext[e]){
		
		if (!dfn[to[e]]){
			
			Tarjan(to[e]);
			low[u]=min(low[u],low[to[e]]);
		}
		else if (vis[to[e]])	low[u]=min(low[u],dfn[to[e]]);
	}
	if (low[u]==dfn[u]){
		
		while (true){
			int v=stk.top();
			stk.pop();
			printf("%d ",v);
			vis[v]=false;
			if (u==v)break;
		}
		printf("\n");
	}
}

void input ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)	scanf("%d%d",&u,&v),add(u,v);
	for (int i=1;i<=n;i++)	if (!dfn[i])	Tarjan(i);
}

int main ()
{
	input();
	return 0;
}
