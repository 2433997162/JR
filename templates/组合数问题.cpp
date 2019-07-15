#define ll long long
const int mod = 1000000007;
const int maxn = 1000006;
int inv[maxn];
/*
    -- m
   |
    -- n
    C(n,m)
    在n中选m个的方案数 
        n!
    ----------
     m!(n-m)!
*/  
void Y (int n)
{
	inv[1]=1;//逆元 
	for (int i=2;i<=n;++i)	
		inv[i]=-mod/i*inv[mod%i]%mod,inv[i]=(inv[i]+mod)%mod;
}
ll C (int n,int m)//n > m
{
	ll res=1;
	int p=n-m+1;
	for (int i=m+1;i<=n;++i)	res=res*i%mod;
	for (int i=2;i<=p;++i)		res=res*inv[i]%mod; //若数据较小可用欧几里得定理或费马小定理 
	return res;
}
