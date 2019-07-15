#include <cstdio>
#define lc(x) child[x][0]
#define rc(x) child[x][1]
using namespace std;
const int maxn = 100005;
int root,n,m,x,y,cnt;
int fa[maxn],size[maxn],val[maxn];
bool tag[maxn];
int child[maxn][2];
inline void pushdown (int x)
{
	if (x&&tag[x]){
		tag[lc(x)]^=1,tag[rc(x)]^=1,tag[x]=0;
		int t=lc(x);
		lc(x)=rc(x),rc(x)=t;
	}
}
inline void rotate (int x)
{
	int f=fa[x],g=fa[f],c=x==rc(f);
	child[f][c]=child[x][!c],child[x][!c]=f;
	fa[f]=x,fa[x]=g,fa[child[f][c]]=f;
	if (g)	child[g][f==rc(g)]=x;
	size[x]=size[lc(x)]+size[rc(x)]+1;
	size[f]=size[lc(f)]+size[rc(f)]+1;
}
inline void splay (int x,int goal=0)//转到goal下面
{
	for (int f;(f=fa[x])!=goal;rotate(x))
		if (fa[f]!=goal)
			rotate((x==rc(f))==(f==rc(fa[f]))?f:x);
	if (!goal)	root=x;
}
void insert (int x)
{
	int now=root,f=0;
	while (now&&val[now]!=x){
		f=now;
		now=child[now][x>val[now]];
	}
	now=++cnt;
	fa[now]=f;
	if (f)	child[f][x>val[f]]=now;
	val[now]=x;
	size[now]=1;
	splay(now);
}
inline int find_x (int x)//查找排名为ｘ的数
{
	int now=root;
	while (true){
		pushdown(now);
		if (lc(now)&&x<=size[lc(now)])	now=lc(now);
		else {
			x-=size[lc(now)]+1;
			if (x<=0)	return now;
			now=rc(now);
		}
	}
}
inline void reverse (int x,int y)
{
	int l=find_x(x),r=find_x(y);
	splay(l),splay(r,l);
	tag[lc(r)]^=1;
}
void print (int x)
{
	pushdown(x);
	if (lc(x))	print(lc(x));
	if (x>1&&x<n+2)	printf("%d ",x-1);
	if (rc(x))	print(rc(x));
}
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+2;++i)	insert(i);
	for (int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		reverse(x,y+2);
	}
	print(root);
	printf("\n");
	return 0;
}
