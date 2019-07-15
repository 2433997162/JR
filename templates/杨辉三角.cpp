#define ll long long
const int mod = 1000000007;
const int maxn = 1000006;
int inv[maxn];
/*
    -- m
   |
    -- n
    C(n-1,m-1)
    ��n��ѡm���ķ����� 
         (n-1)!
    ---------------
     (m-1)!(n-m+1)!
*/  
void Y ()
{
	inv[1]=1;//��Ԫ 
	for (int i=2;i<=n;++i)	
		inv[i]=-mod/i*inv[mod%i]%mod,inv[i]=(inv[i]+mod)%mod;
}
//������ǵĵ�n�е�m�о���n-1��ѡm-1��������� 
ll C (int n,int m)//����λ�õ��� 
{
	--n,--m;
	ll res=1;
	int p=n-m+1;
	for (int i=m+1;i<=n;++i)	res=res*i%mod;
	for (int i=2;i<=p;++i)		res=res*inv[i]%mod; //�����ݽ�С����ŷ����ö�������С���� 
	return res;
}
ll down_data (int n,int m,ll res)//�������(n,m)��(n+1,m)���� 
{
	//(n,m) -> (n+1,m) 
	//C(n,m)*(n+1)/(n-m+1) -> C(n+1,m) 
	--n,--m;
	return res*(n+1)*inv[n-m+1]%mod; 
}
ll rt_data (int n,int m,ll res)//�������(n,m)��(n,m+1)���� 
{
	//(n,m) -> (n,m+1)
	//C(n,m)*(n-m)/(m+1) -> C(n,m+1)
	--n,--m;
	return res*(n-m)*inv[m+1]%mod;
}
ll lt_data (int n,int m,ll res)
{
	//(n,m) -> (n,m-1)
	//C(n,m)*m/(n-m+1) -> C(n,m-1);
	--n,--m;
	return res*m*inv[n-m+1]%mod;
}
ll up_data (int n,int m,ll res)
{
	//(n,m) -> (n-1,m)
	//C(n,m)*(n-m)/n
	--n,--m;
	return res*(n-m)*inv[n]%mod;
}
