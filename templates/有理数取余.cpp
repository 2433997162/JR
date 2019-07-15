#include <cstdio>
#define ll long long
using namespace std;
const int mod = 19260817;
struct IO{
	template<class T>
	IO operator >> (T &res){
		res=0;
		char ch;
		bool flag=false;
		while ((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while (ch>='0'&&ch<='9')	res=((res<<3)+(res<<1)+(ch^'0'))%mod,ch=getchar();
		if (flag)	res=~res+1;
		return *this;
	}
}cin;
ll a,b,x,y;
void ex_gcd (ll a,ll b,ll &x,ll &y)
{
	if (!b)	{	x=1,y=0;return;}
	ex_gcd(b,a%b,x,y);
	int t=x;
	x=y,y=t-a/b*y;
}
int main ()
{
	cin>>a>>b;
	if (!b){	printf("Angry!");return 0;}
	ex_gcd(b,mod,x,y);
	x=(x+mod)%mod;
	x=x*a%mod;
	printf("%lld\n",x);
	return 0;
}
