#include <cstdio>
#define ll long long
using namespace std;
const int maxn = 100005;
struct IO{
	template<class T>
	IO operator >> (T &res){
		res=0;
		char ch;
		bool flag=false;
		while ((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while (ch>='0'&&ch<='9')	res=(res<<3)+(res<<1)+(ch^'0'),ch=getchar();
		if (flag)	res=~res+1;
		return *this;
	}
}cin;
struct Segment_Tree{
	int l,r;
	ll value,lazy;
}tree[maxn<<2];
int n,m,x,y,value,ope;
void build (int k,int l,int r)
{
	tree[k].l=l,tree[k].r=r;
	if (l==r){
		cin>>tree[k].value;
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tree[k].value=tree[k<<1].value+tree[k<<1|1].value;
}
void down (int k)
{
	tree[k<<1].lazy+=tree[k].lazy;
	tree[k<<1|1].lazy+=tree[k].lazy;
	tree[k<<1].value+=tree[k].lazy*(tree[k<<1].r-tree[k<<1].l+1);
	tree[k<<1|1].value+=tree[k].lazy*(tree[k<<1|1].r-tree[k<<1|1].l+1);
	tree[k].lazy=0;
}
void insert (int k,int l,int r,ll value)
{
	if (tree[k].l>=l&&tree[k].r<=r){
		tree[k].value+=value*(tree[k].r-tree[k].l+1);
		tree[k].lazy+=value;
		return;
	}
	if (tree[k].lazy)	down(k);
	int mid=tree[k].l+tree[k].r>>1;
	if (l<=mid)	insert(k<<1,l,r,value);
	if (r>mid)	insert(k<<1|1,l,r,value);
	tree[k].value=tree[k<<1].value+tree[k<<1|1].value;
}
ll query (int k,int l,int r)
{
	if (tree[k].l>=l&&tree[k].r<=r)	return tree[k].value;
	if (tree[k].lazy)	down(k);
	int mid=tree[k].l+tree[k].r>>1;
	ll res=0;
	if (l<=mid)	res+=query(k<<1,l,r);
	if (r>mid)	res+=query(k<<1|1,l,r);
	return res;
}
int main ()
{
	cin>>n>>m;
	build(1,1,n);
	for (int i=1;i<=m;++i){
		cin>>ope>>x>>y;
		if (ope==1){
			cin>>value;
			insert(1,x,y,value);
		}
		else 	printf("%lld\n",query(1,x,y));
	}
	return 0;
}
