#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000006;
const int limit = 25;
struct IO{
	template<class T>
	IO operator >> (T &res){
		res=0;
		char ch;
		bool flag=false;
		while ((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while (ch>='0'&&ch<='9')	res=(res<<3)+(res<<1)+(ch^'0'),ch=getchar();
		if (flag)	res=~res+1;
		return *this;
	}
}cin;
int n,m,root;
int u,v,cnt;
int lg[maxn];
int head[maxn],nxt[maxn],to[maxn],dep[maxn];
int f[maxn][limit];
void add (int u,int v)
{
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
}
void Deal (int u,int father)
{
	dep[u]=dep[father]+1;
	f[u][0]=father;

	for (int i=1;(1<<i)<=dep[u];++i)	
		f[u][i]=f[f[u][i-1]][i-1];

	for (int e=head[u];e;e=nxt[e])
		if (to[e]!=father)	Deal(to[e],u);
}
int LCA (int x,int y)
{
	if (dep[x]<dep[y])	swap(x,y);

	for (int i=lg[dep[x]];i>=0;--i)
		if (dep[f[x][i]]>=dep[y])
			x=f[x][i];

	if (x==y)	return x;
	for (int i=lg[dep[x]];i>=0;--i)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];

	return f[x][0];
}
int main ()
{
	cin>>n>>m>>root;
	lg[0]=-1;
	for (int i=1;i<=n;++i)	lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n-1;++i){
		cin>>u>>v;
		add(u,v),add(v,u);
	}

	Deal(root,0);
	for (int i=1;i<=m;++i){
		cin>>u>>v;
		printf("%d\n",LCA(u,v));
	}
	return 0;
}
