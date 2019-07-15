const int maxn = 10000007;
long long c[maxn];
int lowbit (int x)
{
    return x & -x;
}
void insert (int k,int h)//����k������h
{
    for (int i=k;i<=n;i+=lowbit(i))	c[i]+=h;
}
long long  query (int x,int y)//��ѯ����[x,y]
{
    long long ans=0;
    for (int i=y;i>=1;i-=lowbit(i))	ans+=c[i];
    for (int i=x-1;i>=1;i-=lowbit(i))	ans-=c[i];
    return ans;
}
