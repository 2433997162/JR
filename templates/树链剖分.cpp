#include <iostream>
#include <fstream>
#include <algorithm>
//{{{define
#define lt(x) seg_tree[x].l
#define rt(x) seg_tree[x].r
#define lazy(x) seg_tree[x].lazy
#define val(x) seg_tree[x].val
#define cr(x) x<<1|1
#define cl(x) x<<1
#define fa(x) tree[x].fa
#define top(x) tree[x].top
#define w(x) tree[x].w
#define dep(x) tree[x].dep
#define size(x) tree[x].size
#define son(x) tree[x].son
#define dfn(x) tree[x].dfn
//}}}
using namespace std;
const int maxn = 2000006;
struct Seg_Tree{
	int l,r;
	long long val,lazy;
	Seg_Tree(){	l=r=val=lazy=0;}
}seg_tree[maxn];
struct Tree{
	int son,fa,top,dfn,dep,size;
	long long w;
	Tree(){	son=fa=w=top=dfn=dep=size=0;}
}tree[maxn];
int n,m,cnt,root,ope,u,v,l,r,mod,index;
int head[maxn],refer[maxn],nxt[maxn],to[maxn];
//{{{add(u,v)
void add (int u,int v)
{
	nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
}
//}}}
//{{{push_down(k)
void push_down(int k)
{
	lazy(cl(k))=(lazy(cl(k))+lazy(k))%mod;
	lazy(cr(k))=(lazy(cr(k))+lazy(k))%mod;
	val(cl(k))=(val(cl(k))+lazy(k)*(rt(cl(k))-lt(cl(k))+1))%mod;
	val(cr(k))=(val(cr(k))+lazy(k)*(rt(cr(k))-lt(cr(k))+1))%mod;
	lazy(k)=0;
}
//}}}
//{{{modify(l,r,v,k)
void modify (int l,int r,long long v,int k=1)
{
	if (l<=lt(k)&&r>=rt(k)){
		val(k)=(val(k)+(rt(k)-lt(k)+1)*v)%mod;
		lazy(k)=(lazy(k)+v)%mod;
		return;
	}
	if (lazy(k))    push_down(k);
	int mid=(lt(k)+rt(k))>>1;
	if (l<=mid)	modify(l,r,v,cl(k));
	if (r>mid)	modify(l,r,v,cr(k));
	val(k)=(val(cl(k))+val(cr(k)))%mod;
}
//}}}
//{{{query(l,r,k)
int query (int l,int r,int k=1)
{
	if (l<=lt(k)&&r>=rt(k))	return val(k);
	if (lazy(k))	push_down(k);
	int mid=(lt(k)+rt(k))>>1;
	long long res=0;
	if (l<=mid)	res=(res+query(l,r,cl(k)))%mod;
	if (r>mid)	res=(res+query(l,r,cr(k)))%mod;
	return res;
}
//}}}
//{{{build(k,l,r)
void build (int k,int l,int r)
{
	lt(k)=l,rt(k)=r;
	if (l==r){	val(k)=w(refer[l]);return;}
	int mid=(l+r)>>1;
	build(cl(k),l,mid),build(cr(k),mid+1,r);
	val(k)=(val(cl(k))+val(cr(k)))%mod;
}
//}}}
//{{{dfs1(x)
void dfs1 (int x)
{
	size(x)=1;
	dep(x)=dep(fa(x))+1;
	for (int e=head[x];e;e=nxt[e]){
		if (to[e]==fa(x))	continue;
		fa(to[e])=x;
		dfs1(to[e]);
		size(x)+=size(to[e]);
		if (size(son(x))<size(to[e]))	son(x)=to[e];
	}
}
//}}}
//{{{dfs2(x)
void dfs2 (int x)
{
	dfn(x)=++index;
	refer[index]=x;
	if (!son(x))	return;
	top(son(x))=top(x);
	dfs2(son(x));
	for (int e=head[x];e;e=nxt[e]){
		if (to[e]==son(x)||to[e]==fa(x))	continue;
		top(to[e])=to[e];
		dfs2(to[e]);
	}
}
//}}}
//{{{ask(x,y)
int ask (int x,int y)
{
	int ans=0;
	while (top(x)!=top(y)){
		if (dep(top(x))<dep(top(y)))	swap(x,y);
		ans=(ans+query(dfn(top(x)),dfn(x)))%mod;
		x=fa(top(x));
	}
	if (dep(x)>dep(y))	swap(x,y);
	return ans=(ans+query(dfn(x),dfn(y)))%mod;
}
//}}}
//{{{change(x,y,v)
void change(int x,int y,int v)
{
	while (top(x)!=top(y)){
		if (dep(top(x))<dep(top(y)))	swap(x,y);
		modify(dfn(top(x)),dfn(x),v);
		x=fa(top(x));
	}
	if (dep(x)>dep(y))	swap(x,y);
	modify(dfn(x),dfn(y),v);
}
//}}}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>root>>mod;
	for (int i=1;i<=n;++i)	cin>>w(i);
	for (int i=1;i<=n-1;++i){
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	top(root)=root;
	dfs1(root);
	dfs2(root);
	build(1,1,n);
	for (int i=1;i<=m;++i){
		cin>>ope>>l;
		if (ope!=4)	cin>>r;
		if (ope==1)	cin>>v,change(l,r,v);
		else if (ope==2)	cout<<ask(l,r)<<endl;
		else if (ope==3)	modify(dfn(l),dfn(l)+size(l)-1,r);
		else if (ope==4)	cout<<query(dfn(l),dfn(l)+size(l)-1)<<endl;
	}
	return 0;
}
