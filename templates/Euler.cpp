int cnt;
int prime[maxn],phi[maxn];
bool vis[maxn];
void Euler_sieve (int n)
int cnt;
int prime[maxn],phi[maxn];
bool vis[maxn];
void Euler_sieve (int n)
{
	phi[1]=1;
	for (int i=2;i<=n;++i){
		if (!vis[i])	prime[++cnt]=i,phi[i]=i-1;
		for (int j=1;j<=cnt&&i*prime[j]<=n;++j){
			vis[i*prime[j]]=true;
			if (i%prime[j]==0){	phi[i*prime[j]]=phi[i]*prime[j];break;}
			phi[i*prime[j]]=phi[i]*phi[prime[j]];
		}
	}
} 

