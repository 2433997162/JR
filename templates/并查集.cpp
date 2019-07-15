#include <cstdio>
using namespace std;
const int maxn=100005;
int father[maxn];
int find (int x)
{
	if (father[x]!=x)father[x]=find(father[x]);
	return father[x];
}
void Union (int x,int y)
{
	father[find(x)]=find(y);
}
int main ()
{
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)father[i]=i;
	for (int i=0;i<m;i++){
		scanf("%d%d%d",&c,&a,&b);
		if (c==1)Union(a,b);
		else {
			int fa,fb;
			fa=find(a);
			fb=find(b);
			if (fa==fb)printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}

