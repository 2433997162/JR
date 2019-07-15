/*******************************
Author:Morning_Glory
LANG:C++
Created Time:2019年06月11日 星期二 14时23分51秒
*******************************/
#include <cstdio>
#include <fstream>
#define ll long long
using namespace std;
const int mod = 998244353;
const int maxn = 1000006;
//{{{cin
struct IO{
	template<typename T>
	IO & operator>>(T&res){
		res=0;
		bool flag=false;
		char ch;
		while((ch=getchar())>'9'||ch<'0')	 flag|=ch=='-';
		while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^'0'),ch=getchar();
		if (flag)	 res=~res+1;
		return *this;
	}
}cin;
//}}}
int n;
int a[maxn],fac[maxn];//factorial
bool vis[maxn];
int Extension (int *a,int n)
{
	int ans=0;
	for (int i=1;i<=n;++i){
		int low=0;
		vis[a[i]]=true;
		for (int j=1;j<=a[i]-1;++j)	low+=!vis[j];
		ans=(ans+1ll*low*fac[n-i]%mod)%mod;
	}
	return ans+1;
}
int main()
{
	freopen("康托展开.in","r",stdin);
	freopen("康托展开.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i)	cin>>a[i];
	fac[1]=1;
	for (int i=2;i<=n;++i)	fac[i]=1ll*fac[i-1]*i%mod;
	printf("%d\n",Extension(a,n));
	return 0;
}
