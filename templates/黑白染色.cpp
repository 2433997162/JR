#include <cstdio>
#include <cstring>
#define reset(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn = 1000006;
struct IO{
	template<typename T>
	IO & operator>>(T&res){
	 	res=0;
		bool flag=false;
		char ch;
		while((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while(ch>='0'&&ch<='9')	res=(res<<1)+(res<<3)+(ch^'0'),ch=getchar();
		if (flag)	res=~res+1;
		return *this;
	}
}cin;
int T,n,m,u,v,cnt;
int head[maxn],nxt[maxn],to[maxn],col[maxn];
bool flag;
void add (int u,int v)
{
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
}
void dfs (int x)
{
	for (int e=head[x];e&&flag;e=nxt[e]){
		if (col[to[e]])	flag=col[to[e]]+col[x]==3;
		else col[to[e]]=3-col[x],dfs(to[e]);
	}
}
int main()
{
	cin>>T;
	while (T--){
		flag=true,cnt=0;
		reset(col),reset(head);
		cin>>n>>m;
		for (int i=1;i<=m;++i)	cin>>u>>v,add(u,v),add(v,u);
		for (int i=1;i<=n&&flag;++i)	
			if (!col[i])	col[i]=1,dfs(i);
		if (flag)	printf("Correct\n");
		else	printf("Wrong\n");
	}
	return 0;
}
