/*******************************
Author:Morning_Glory
LANG:C++
Created Time:2019年07月14日 星期日 19时06分03秒
*******************************/
#include <cstdio>
#include <fstream>
#define ll long long
using namespace std;
ll a,m,b,mod=2000000000;
bool bj;
//{{{cin
struct IO{
	template<typename T>
	IO & operator>>(T&res){
		res=0;
		bool flag=false;
		char ch;
		while((ch=getchar())>'9'||ch<'0')	 flag|=ch=='-';
		while(ch>='0'&&ch<='9'){
		       	res=(res<<1)+(res<<3)+(ch^'0'),ch=getchar();
			if (res>=mod)	bj=true,res%=mod;
		}
		if (flag)	 res=~res+1;
		return *this;
	}
}cin;
//}}}
//{{{ksm
ll ksm (ll a,ll b)
{
	ll s=1;
	a=a%m;
	for (;b;b>>=1,a=a*a%m)
		if (b&1)	s=s*a%m;
	return s;
}
//}}}
//{{{phi
ll phi (ll x)
{
	ll res=x;
	for (int i=2;i*i<=x;++i)
		if (x%i==0){
			res=res/i*(i-1);
			while (x%i==0)	x/=i;
		}
	if (x>1)	res=res/x*(x-1);
	return res;
}
//}}}
int main()
{
	freopen("欧拉定理.in","r",stdin);
	freopen("欧拉定理.out","w",stdout);
	cin>>a>>m;
	mod=phi(m);
	cin>>b;
	if (bj)	b+=phi(m);
	printf("%lld\n",ksm(a,b));
	return 0;
}
