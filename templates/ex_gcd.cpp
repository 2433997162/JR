//已知a,b  求解  ax+by=1
void ex_gcd (int a,int b,int &x,int &y)
{
	if (b==0){x=1,y=0;return;}
	ex_gcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
}
/*
 * 若求解  ax+by=c
 * △条件(是否有解) ： 满足gcd(a,b)|c [c%gcd(a,b)==0]
 * 可以先求  ax+by=gcd(a,b)
 * 再将求得的x与y分别乘以c/gcd(a,b)
 */
