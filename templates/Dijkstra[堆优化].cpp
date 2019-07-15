#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 100005;
struct Edge{
    int tnext,to,w;
}edge[maxn<<4];
int head[maxn],cnt;
int dis[maxn],vis[maxn];
int n,m,u,v,w,st;
int read (void)
{
    int res=0;
    char ch;
    bool flag=false;
    while ((ch=getchar())>'9'||ch<'0')	flag=flag||ch=='-';
    while (ch<='9'&&ch>='0')	res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    if (flag)return ~res+1;
    return res;
}
void add (int u,int v,int w)
{
    edge[++cnt].tnext=head[u];
    edge[cnt].to=v;
    edge[cnt].w=w;
    head[u]=cnt;
}
void input (void)
{
    n=read(),m=read(),st=read();
    for (int i=1;i<=m;i++){
        u=read(),v=read(),w=read();
        add(u,v,w);
        //ע����ģ������������ͼ����������ͼ����ȥ������ע�� 
        //add(v,u,w) 
    }
}
void dijkstra (void)
{
    priority_queue< pair<int,int> > q;
    for (int i=1;i<=n;i++)dis[i]=2147483647;
    /*
     * Ĭ��Ϊ����� 
     * pair�ĵ�һάΪdis���෴��
     * pair�ĵڶ�άΪ�ڵ���
     * ���ȶ��л��Ȱ���pair��firstԪ�ؽ�������
     * �����෴���������תΪС����
     */
    dis[st]=0;
    q.push(make_pair(0,st));
    while (q.size()){
        int x=q.top().second;
        q.pop();
        if (vis[x])continue;
        vis[x]=true;
        for (int i=head[x];i;i=edge[i].tnext){
            int y=edge[i].to,z=edge[i].w;
            if (dis[y]>dis[x]+z&&!vis[y]){
                dis[y]=dis[x]+z;
                q.push(make_pair(-dis[y],y));
            }
        }
    }
}
void print (void)
{
    for (int i=1;i<=n;i++)printf("%d ",dis[i]);
}
int main ()
{
    input();
    dijkstra();
    print();
    return 0;
}
