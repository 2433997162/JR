/*******************************
Author:Morning_Glory
LANG:C++
Created Time:2019年04月11日 星期四 16时40分44秒
*******************************/
#include <cstdio>
#include <fstream>
#include <algorithm>
#define rint register int
using namespace std;
const int maxn = 4000006;
int n,m,l,r,k;
int a[maxn],rk[maxn],id[maxn],ref[maxn];
int cnt;
int num[maxn],root[maxn],val[maxn],lc[maxn],rc[maxn];
bool comp (int x,int y)
{
	if (a[x]==a[y])	return x<y;
	return a[x]<a[y];
}
//建出第一棵树
void build (int l,int r,int &rt)
{
	rt=++cnt;
	if (l==r)	return;
	int mid=(l+r)>>1;
	build(l,mid,lc[rt]);
	build(mid+1,r,rc[rt]);
}
//新增之后的树,新的值为x，上一次的节点是last
void insert (int l,int r,int &rt,int last,int x)
{
	rt=++cnt;
	lc[rt]=lc[last],rc[rt]=rc[last];
	num[rt]=num[last]+1;
	if (l==r)	return;
	int mid=(l+r)>>1;
	if (x<=mid)	insert(l,mid,lc[rt],lc[last],x);
	else	insert(mid+1,r,rc[rt],rc[last],x);
}
//查询,这里以[x,y]第k大为例,值域为[l,r]
int query (int l,int r,int x,int y,int k)
{
	if (l==r)	return ref[l];
	int sum=num[lc[y]]-num[lc[x]],mid=(l+r)>>1;
	if (k<=sum)	return query(l,mid,lc[x],lc[y],k);
	else	return query(mid+1,r,rc[x],rc[y],k-sum);
}
int main()
{
	freopen("主席树.in","r",stdin);
	freopen("主席树.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (rint i=1;i<=n;++i)	scanf("%d",&a[i]),id[i]=i;
	sort(id+1,id+n+1,comp);
	for (rint i=1;i<=n;ref[rk[id[i]]]=a[id[i]],++i)
		if (a[id[i]]==a[id[i-1]])	rk[id[i]]=rk[id[i-1]];
		else rk[id[i]]=rk[id[i-1]]+1;
	//for (int i=1;i<=n;++i)	printf("%d ",ref[i]);
	//printf("\n");
	build(1,rk[id[n]],root[0]);
	for (rint i=1;i<=n;++i)	insert(1,rk[id[n]],root[i],root[i-1],rk[i]);
	for (rint i=1;i<=m;++i){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",query(1,rk[id[n]],root[l-1],root[r],k));
	}
	return 0;
}
