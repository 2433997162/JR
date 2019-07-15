#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1000006;
int cnt,n,m,s,t;
int head[maxn],nxt[maxn],to[maxn],w[maxn],dep[maxn],cur[maxn];
//{{{
void add (int u,int v,int val)
{
	nxt[cnt]=head[u],head[u]=cnt,to[cnt]=v,w[cnt++]=val;
}
bool bfs ()
{
	queue<int> q;
	memset(dep,0,sizeof(dep));
	for (int i=0;i<=n;++i)	cur[i]=head[i];
	q.push(s);
	dep[s]=1;
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (int e=head[x];e!=-1;e=nxt[e]){
			if (!dep[to[e]]&&w[e]>0){
				dep[to[e]]=dep[x]+1;
				if (to[e]==t)	return true;
				q.push(to[e]);
			}
		}
	}
	return false;
}
int dfs (int x,int dist)
{
	if (x==t)	return dist;
	for (int &e=cur[x];e!=-1;e=nxt[e]){
		if (dep[to[e]]==dep[x]+1&&w[e]>0){
			int di=dfs(to[e],min(dist,w[e]));
			if (di>0){
				w[e]-=di;
				w[e^1]+=di;
				return di;
			}
		}
	}
	return 0;
}
int dinic ()
{
	int ans=0;
	while (bfs())
		while (int d=dfs(s,inf))	ans+=d;
	return ans;
}
//}}}
// memset(head,-1,sizeof(head));
// memset(cur,-1,sizeof(cur));
