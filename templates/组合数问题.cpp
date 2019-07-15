#define ll long long
const int mod = 1000000007;
const int maxn = 1000006;
int inv[maxn];
/*
    -- m
   |
    -- n
    C(n,m)
    ��n��ѡm���ķ����� 
        n!
    ----------
     m!(n-m)!
*/  
void Y (int n)
{
	inv[1]=1;//��Ԫ 
	for (int i=2;i<=n;++i)	
		inv[i]=-mod/i*inv[mod%i]%mod,inv[i]=(inv[i]+mod)%mod;
}
ll C (int n,int m)//n > m
{
	ll res=1;
	int p=n-m+1;
	for (int i=m+1;i<=n;++i)	res=res*i%mod;
	for (int i=2;i<=p;++i)		res=res*inv[i]%mod; //�����ݽ�С����ŷ����ö�������С���� 
	return res;
}
