#include <iostream>
using namespace std;
const long long mod = 998244353;
const int maxn = 2005;
long long n,g,k,up,down,ni,ans;
long long x[maxn],y[maxn];
void ex_gcd (long long a,long long b,long long &x,long long &y)
{
	if (!b){	x=1,y=0;return;}
	ex_gcd(b,a%b,x,y);
	long long t=x;
	x=y,y=t-a/b*y;
}
int main ()
{
	cin>>n>>k;
	for (int i=1;i<=n;++i)	cin>>x[i]>>y[i];
	for (int i=1;i<=n;++i){
		up=y[i],down=1;
		for (int j=1;j<=n;++j){
			if (i==j) continue;
			up=up*(k+mod-x[j])%mod;
			down=down*(x[i]+mod-x[j])%mod;
		}
		ex_gcd(down,mod,ni,g);
		ni=(ni%mod+mod)%mod;
		ans=(ans+up*ni%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}
