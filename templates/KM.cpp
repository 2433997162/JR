#include <cstdio>
#include <cstring>
#define inf 0x7fffffff
using namespace std;
const int maxn = 5005;
int n,m;
int cl[maxn],cr[maxn],link[maxn];
int w[maxn][maxn];
bool visl[maxn],visr[maxn];
bool dfs (int k)
{
	visl[k]=true;
	for (int i=1;i<=m;++i){
		if (!visr[i]&&cl[k]+cr[i]==w[i][k]){
			visr[i]=true;
			if (!link[i]||dfs(link[i])){
				link[i]=k;
				return true;
			}
		}
	}
	return false;
}
int KM ()
{
	for (int i=1;i<=n;++i){
		while (true){
			int d=inf;
			memset(visl,false,sizeof(visl));
			memset(visr,false,sizeof(visr));
			if (dfs(i))	break;
			for (int j=1;j<=n;++j)
				if (visl[j])
					for (int k=1;k<=m;++k)
						if (!visr[k])	d=min(d,cl[j]+cr[k]-w[j][k]);
			if (d==inf)	return -1;
			for (int j=1;j<=n;++j)
				if (visl[j])	cl[j]-=d;
			for (int j=1;j<=m;++j)
				if (visr[j])	cr[j]+=d;
		}
	}
	int ans=0;
	for (int i=1;i<=m;++i)	ans+=w[link[i]][i];
	return ans;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		int d=0;
		for (int j=1;j<=m;++j){
			scanf("%d",&w[i][j]);
			d=max(d,w[i][j]);
		}
		cl[i]=d;
	}
	return 0;
}
