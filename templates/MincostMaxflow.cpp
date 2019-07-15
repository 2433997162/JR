#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 123456789
using namespace std;
const int maxn = 1000006;
int n,m,u,v,s,t,val,coss,cnt,flow,min_cost;
int head[maxn],nxt[maxn],to[maxn],w[maxn],cost[maxn],pre[maxn],path[maxn],dis[maxn];
bool vis[maxn];
void add (int u,int v,int val,int coss)
{
	nxt[cnt]=head[u],head[u]=cnt,to[cnt]=v,w[cnt]=val,cost[cnt++]=coss;
}
bool spfa ()
{
	memset(dis,inf,sizeof(dis));
	queue<int> q;
	q.push(s);
	dis[s]=0,pre[t]=-1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		vis[x]=false;
		for (int e=head[x];e!=-1;e=nxt[e])
			if (w[e]>0&&dis[x]+cost[e]<dis[to[e]]){
				dis[to[e]]=dis[x]+cost[e];
				pre[to[e]]=x,path[to[e]]=e;
				if (!vis[to[e]])	q.push(to[e]);
				vis[to[e]]=true;
			}
	}
	return pre[t]!=-1;
}
void MinCost_Flow ()
{
	while (spfa()){
		int f=inf;
		for (int u=t;u!=s;u=pre[u])
			if (w[path[u]]<f)	f=w[path[u]];
		flow+=f,min_cost+=f*dis[t];
		for (int u=t;u!=s;u=pre[u]){
			w[path[u]]-=f;
			w[path[u]^1]+=f;
		}
	}
}
int main ()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=m;++i){
		scanf("%d%d%d%d",&u,&v,&val,&coss);
		add(u,v,val,coss),add(v,u,0,-coss);
	}
	MinCost_Flow();
	printf("%d %d\n",flow,min_cost);
	return 0;
}
