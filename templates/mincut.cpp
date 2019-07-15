#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define inf 123456789
using namespace std;
const int maxn = 40005;
int n,m,cnt,s,t,u,v,val,ans;
int head[maxn],nxt[maxn],to[maxn],w[maxn],dep[maxn];
bool S[maxn];
void add (int u,int v,int val)
{
	nxt[cnt]=head[u],head[u]=cnt,to[cnt]=v,w[cnt++]=val;
}
bool bfs ()
{
	queue<int> q;
	memset(dep,0,sizeof(dep));
	dep[s]=1;
	q.push(s);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int e=head[x];~e;e=nxt[e])
			if (!dep[to[e]]&&w[e]>0)	dep[to[e]]=dep[x]+1,q.push(to[e]);
	}
	return dep[t];
}
int dfs (int x,int dist)
{
	if (x==t)	return dist;
	for (int e=head[x];~e;e=nxt[e]){
		if (dep[to[e]]==dep[x]+1&&w[e]>0){
			int di=dfs(to[e],min(dist,w[e]));
			if (di){
				w[e]-=di;
				w[e^1]+=di;
				return di;
			}
		}
	}
	return 0;
}
int Dinic ()
{
	int Ans=0;
	while (bfs())
		while (int d=dfs(s,inf))
			Ans+=d;
	return Ans;
}
void find ()
{
	queue<int> q;
	q.push(s);
	S[s]=true;
	ans=1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int e=head[x];~e;e=nxt[e])
			if (w[e]>0&&!S[to[e]])	S[to[e]]=true,q.push(to[e]),++ans;
	}
}
int main ()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	s=1,t=n;
	for (int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&val);
		add(u,v,val);
		add(v,u,0);
	}
	printf("%d ",Dinic());
	find();
	printf("%d\n",ans);
	for (int i=1;i<=n;++i)	
		if (S[i])	printf("%d ",i);
	return 0;
}
