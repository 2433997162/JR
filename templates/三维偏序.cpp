#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int maxn = 200005;
struct IO{
	template<class T>
	IO operator >> (T &res){
		res=0;
		char ch;
		bool flag=false;
		while ((ch=getchar())>'9'||ch<'0')  flag|=ch=='0';
		while (ch>='0'&&ch<='9')	res=(res<<3)+(res<<1)+(ch^'0'),ch=getchar();
		if (flag)   res=~res+1;
		return *this;
	}
}cin;
struct Flower{
	int a,b,c,ans;
	friend bool operator < (Flower x,Flower y){
		if (x.a==y.a){
			if (x.b==y.b)	return x.c<y.c;
			return x.b<y.b;
		}
	       	return x.a<y.a;
	}
}f[maxn],tmp[maxn];
int n,mx,ans;
int tree[maxn],cup[maxn];
void insert (int k,int v)
{
	while (k<=mx)	tree[k]+=v,k+=lowbit(k);
}
int query (int k)
{
	int res=0;
	while (k)	res+=tree[k],k-=lowbit(k);
	return res;
}
void msort (int l,int r)
{
	if (l>=r)   return;
	int mid=(l+r)>>1,i=l,j=mid+1,k=l-1;
	msort(l,mid),msort(mid+1,r);
	while (i<=mid&&j<=r){
		if (f[i].b<=f[j].b){
			tmp[++k]=f[i++];
			insert(tmp[k].c,1);
		}
		else{
			tmp[++k]=f[j++];
			tmp[k].ans+=query(tmp[k].c);
		}
	}
	while (j<=r)	tmp[++k]=f[j++],tmp[k].ans+=query(tmp[k].c);
	for (j=l;j<=i-1;++j)	insert(f[j].c,-1);
	while (i<=mid)  tmp[++k]=f[i++];
	for (i=l;i<=r;++i) 	f[i]=tmp[i];
}
int main ()
{
	cin>>n>>mx;
	for (int i=1;i<=n;++i)  cin>>f[i].a>>f[i].b>>f[i].c;
	sort(f+1,f+n+1);
	msort(1,n);
	for (int i=n;i>=1;--i){
		if (f[i].a==f[i+1].a&&f[i].b==f[i+1].b&&f[i].c==f[i+1].c)	f[i].ans=f[i+1].ans;
		++cup[f[i].ans];
	}
	for (int i=0;i<=n-1;++i)  printf("%d\n",cup[i]);
	return 0;
}
