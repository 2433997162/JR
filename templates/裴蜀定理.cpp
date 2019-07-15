#include <cstdio>
#include <cmath>
using namespace std;
int ans,n,t;
int gcd (int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int main ()
{
	scanf("%d",&n);
	scanf("%d",&ans);
	while (--n){
		scanf("%d",&t);
		t=abs(t);
		ans=abs(gcd(ans,t));
	}
	printf("%d",ans);
	return 0;
}
