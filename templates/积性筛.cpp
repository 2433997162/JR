//求n以内的所有数的m次方%mod 
int a[maxn],prime[maxn],cnt;
bool vis[maxn];
void jxs (int n,int m,int mod)
{
	for(int i = 2 ; i <= n ; ++i) {
		if(!vis[i]) {
			a[i] = quick_pow_mod(i,m,mod);
			prime[++cnt] = i;
		}
		for(int j = 1 ; j <= cnt ; ++j) {
			if(i * prime[j] > n) break;
			a[i * prime[j]] = a[i] * a[prime[j]] % mod;
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}
