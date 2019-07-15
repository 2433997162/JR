#include <cstdio>
using namespace std;
int a,b,x,y;
void ex_gcd (int,int,int &,int &);
int main ()
{
	/*
	 * ax ≡ 1 mod b
	 * ax % b == 1
	 * ax - ax/b*b == 1
	 * 设y为ax/b,ax + (b(-y)) == 1
	 * 以下y为-y
	 * ax + by == gcd(a,b)
	 * gcd(a,b) == gcd(b,a%b) == gcd(b,a-a/b*b)
	 * ax + by == gcd(b,a-a/b*b) == bx'+(a-a/b*b)y'
	 * ax + by == bx' + ay' - a/b*by'
	 * ax + by == ay' + b(x'-a/b*by)
	 * x = y',y = x' - ab / by
	 */
	scanf("%d%d",&a,&b);
	ex_gcd(a,b,x,y);
	printf("%d",(x+b)%b);
	return 0;
}
void ex_gcd(int a,int b,int &x,int &y)
{
	if (b==0){x=1,y=0;return;}
	ex_gcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
}
