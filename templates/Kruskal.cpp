#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5005;
const int maxnn=200005;
struct Edge{
    int dota,dotb,distance;
}edge[maxnn];
int n,m,a,b,c,cnt,ans,k;
int fa[maxn];
int find (int x)
{
    if (fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
void Union (int x,int y)
{
    int fx=find(x);
    int fy=find(y);
    if (fx!=fy)fa[fx]=fy;
}
void add (int a,int b,int w)
{
    cnt++;
    edge[cnt].dota=a;
    edge[cnt].dotb=b;
    edge[cnt].distance=w;
}
void input ()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)fa[i]=i;
    for (int i=1;i<=m;i++){
        cin>>a>>b>>c;
        add(a,b,c);
    }
}
bool comp (Edge x,Edge y)
{
    return x.distance<y.distance;
}
void kruskal ()
{
    sort(edge+1,edge+m+1,comp);
    k=1;
    for (int i=1;i<=m;i++){
        if (find(edge[i].dota)!=find(edge[i].dotb)){
            Union(edge[i].dota,edge[i].dotb);
            k++;
            ans+=edge[i].distance;
            if (k==n)break;
        }
    }
    if (k<n)cout<<"orz";
    else cout<<ans;
}
int main ()
{
    input();
    kruskal();
    return 0;
}

