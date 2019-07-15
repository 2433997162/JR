#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 4000006;
const int mod = 998244353;
const int g = 3;
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
int n,m,bit,len;
int a[maxn],b[maxn],ans[maxn],rev[maxn];
int ksm (int a,int b)
{
	int s=1;
	for (;b;b>>=1,a=1ll*a*a%mod)
		if (b&1)	s=1ll*s*a%mod;
	return s;
}
void get_rev (int bit)
{
	int lim=1<<bit;
	for (int i=0;i<=lim;++i)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
}
void NTT (int *a,int len,int on_off)
{
	for (int i=0;i<=len-1;++i)
		if (i<rev[i])	swap(a[i],a[rev[i]]);
	for (int i=1;i<len;i<<=1){
		int wn=ksm(g,(mod-1)/(i*2));
		if (on_off==-1)	wn=ksm(wn,mod-2);
		for (int j=0;j<len;j+=(i<<1)){
			int w=1;
			for (int k=0;k<i;++k){
				int u=a[j+k],t=1ll*w*a[j+k+i]%mod;
				a[j+k]=1ll*(u+t)%mod;
				a[j+k+i]=1ll*(u-t+mod)%mod;
				w=1ll*w*wn%mod;
			}
		}
	}
	if (on_off==-1){
		int inv=ksm(len,mod-2);
		for (int i=0;i<=len-1;++i)	a[i]=1ll*a[i]*inv%mod;
	}
}
int main ()
{
	cin>>n>>m;
	for (int i=0;i<=n;++i)	cin>>a[i];
	for (int i=0;i<=m;++i)	cin>>b[i];
	len=1;
	while (len<=n+m)	++bit,len<<=1;
	get_rev(bit);
	NTT(a,len,1);
	NTT(b,len,1);
	for (int i=0;i<=len;++i)	ans[i]=1ll*a[i]*b[i]%mod;
	NTT(ans,len,-1);
	for (int i=0;i<=n+m;++i)	printf("%d ",ans[i]);
	return 0;
}
