#include <cstdio>
using namespace std;
const int maxn = 500005;
int n;
int c[maxn];
inline int lowbit (int x) { return x  & -x; }
inline void insert (int l,int r,int w)
{
	for (int i=l;i<=n;i+=lowbit(i))		c[i]+=w;
	for (int i=r+1;i<=n;i+=lowbit(i))	c[i]-=w;
}
inline int query (int k)
{
	int res=0;
	while (k)	res+=c[k],k-=lowbit(k);
	return res;
}
