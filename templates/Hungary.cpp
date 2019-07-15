#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000006;
int n,m,edges,u,v,cnt;
int head[maxn],nxt[maxn],to[maxn],link[maxn];
bool vis[maxn];
void add (int u,int v)
{
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
}
bool find(int x)
{
	for (int e=head[x];e;e=nxt[e])
		if (!vis[to[e]]){
			vis[to[e]]=true;
			if (!link[to[e]]||find(link[to[e]])){
				link[to[e]]=x;
				return true;
			}
		}
	return false;
}
int hungary ()
{
	int ans=0;
	for (int i=1;i<=n;++i){
		memset(vis,false,sizeof(vis));
		ans+=find(i);
	}	
	return ans;
}
int main ()
{
	scanf("%d%d%d",&n,&m,&edges);
	while (edges--){
		scanf("%d%d",&u,&v);
		if (v>m)	continue;
		add(u,v);
	}
	printf("%d\n",hungary());
	return 0;
}
