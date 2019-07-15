#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000006;
const int limit = 22;
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
int n,m,l,r;
int a[maxn],lg[maxn],pre[limit];
int f[maxn][limit];
void Make_St ()
{
	pre[0]=1,lg[0]=-1;
	for (int i=1;i<=limit-1;++i)	pre[i]=pre[i-1]<<1;
	for (int i=1;i<maxn;++i)	lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n;++i)	f[i][0]=a[i];
	for (int j=1;j<=limit-1;++j)
		for (int i=1;i<=n;++i)
			if (i+pre[j]-1<=n)
				f[i][j]=max(f[i][j-1],f[i+pre[j-1]][j-1]);
			else break;
}
int query (int l,int r)
{
	if (l==r)	return a[l];
	int len=r-l+1;
	return max(f[l][lg[len]],f[r-pre[lg[len]]+1][lg[len]]);
}
int main ()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)	cin>>a[i];
	Make_St();
	for (int i=1;i<=m;++i){
		cin>>l>>r;
		printf("%d\n",query(l,r));
	}
	return 0;
}
