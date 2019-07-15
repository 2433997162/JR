#include <cstdio>
#define lc(x) child[(x)][0]
#define rc(x) child[(x)][1]
const int maxn = 500005;
int n,ope,v;
int root,cnt;
int fa[maxn],val[maxn],num[maxn],size[maxn];
int child[maxn][2];
//{{{
inline void rotate (int x)
{
	int f=fa[x],g=fa[fa[x]],c=x==rc(f);
	child[f][c]=child[x][!c];
	fa[child[f][c]]=f,child[x][!c]=f;
	fa[f]=x,fa[x]=g;
	if (g)	child[g][f==rc(g)]=x;
	size[f]=size[lc(f)]+size[rc(f)]+num[f];
	size[x]=size[lc(x)]+size[rc(x)]+num[x];
}
inline void splay (int x,int goal=0)//move x to goal'son
{
	for (int f;(f=fa[x])!=goal;rotate(x))
		if (fa[f]!=goal)
			rotate((x==rc(f))==(f==rc(fa[f]))?f:x);
	if (!goal)	root=x;
}
inline void insert (int x)
{
	int now=root,f=0;
	while (now&&val[now]!=x){
		f=now;
		now=child[now][x>val[now]];
	}
	if (now)	++num[now];
	else{
		now=++cnt;
		fa[now]=f,val[now]=x;
		if (f)	child[f][x>val[f]]=now;
		num[now]=size[now]=1;
	}
	splay(now);
}
inline int find_x (int x)//查询x数的排名,并将其旋转到根节点,使用前要注意会不会查询不存在的数，如果没有该数的话，就先把该数insert
{
	int now=root,res=0;
	if (!now)	return -1;
	while (true){
		if (x<val[now])		now=lc(now);
		else{
			res+=size[lc(now)];
			if (x==val[now]||!rc(now)){
				splay(now);
				return res+1;
			}
			res+=num[now];
			now=rc(now);
		}
	}
}
inline int k_th (int x)//查询排名为x的数
{
	int now=root;
	while (true){
		if (lc(now)&&x<=size[lc(now)])	now=lc(now);
		else{
			x-=size[lc(now)]+num[now];
			if (x<=0) return now;
			now=rc(now);
		}
	}
}
inline int pre (int t)//查找前驱(0)或者后继(1)
{
	//前驱定义为小于x的最大的数
	//后继定义为大于x的最小的数
	int x=child[root][t];
	t=!t;
	while (child[x][t])	x=child[x][t];
	return x;
}
inline void delet ()// 使用前先将要删除的结点旋到根结点
{
	int x=root;
	--num[x],--size[x];
	if (num[x])	return;
	int l=pre(0),r=pre(1);
	if (!l&&!r) size[x]=root=0;
	else if (!l)	root=rc(x),fa[root]=rc(x);
	else if (!r)	root=lc(x),fa[root]=lc(x);
	else{
		splay(l),splay(r,l);
		lc(r)=0,--size[r],--size[l];
	}
	fa[x]=val[x]=size[x]=0;
}
//}}}
