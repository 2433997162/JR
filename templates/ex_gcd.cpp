//��֪a,b  ���  ax+by=1
void ex_gcd (int a,int b,int &x,int &y)
{
	if (b==0){x=1,y=0;return;}
	ex_gcd(b,a%b,x,y);
	int tmp=x;
	x=y,y=tmp-a/b*y;
}
/*
 * �����  ax+by=c
 * ������(�Ƿ��н�) �� ����gcd(a,b)|c [c%gcd(a,b)==0]
 * ��������  ax+by=gcd(a,b)
 * �ٽ���õ�x��y�ֱ����c/gcd(a,b)
 */
