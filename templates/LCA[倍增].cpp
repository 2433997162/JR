#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500005;
const int limit = 20;
int tnext[maxn<<1],to[maxn<<1],head[maxn],dep[maxn],f[maxn][32],lg[maxn];
//lg为常数优化,用于优化某深度最大可开2的log_2(n)次方 
int n,m,s,cnt,u,v;
void add(int u,int v)
{
	to[++cnt]=v,tnext[cnt]=head[u],head[u]=cnt;
}
int read(void)
{
	int res=0;
	bool flag=false;
	char ch;
	while ((ch=getchar())>'9'||ch<'0')
		if (ch=='-')flag=true;
	while (ch>='0'&&ch<='9')res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	if (flag)return ~res+1;
	return res;
}
void Deal (int u,int father)
{
	dep[u]=dep[father]+1;
	f[u][0]=father;
	
	for (int i=1;(1<<i)<=dep[u];i++)
		f[u][i]=f[f[u][i-1]][i-1];
		
	for (int node=head[u];node;node=tnext[node])
		if (to[node]!=father)Deal (to[node],u);
}
//查询x与y的LCA 
int LCA (int x,int y)
{
	if (dep[x]<dep[y])swap(x,y);
	
	for (int i=lg[dep[x]];i>=0;i--)
		if (dep[f[x][i]]>=dep[y])x=f[x][i];
		
	if (x==y)return y;
	
	for (int i=lg[dep[x]];i>=0;i--)
		if (f[x][i]!=f[y][i])		x=f[x][i],y=f[y][i];
		
	return f[x][0];
}
int main ()
{
	//ios::sync_with_stdio(false);
	n=read(),m=read(),s=read();
	for (int i=1;i<n;i++){
		u=read(),v=read();
		add(u,v),add(v,u);
	}
	lg[0]=-1;
	for (int i=1;i<n;i++)
		lg[i]=lg[i>>1]+1;
	
	Deal (s,0);
	
	for (int i=1;i<=m;i++){
		u=read(),v=read();
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
