#include <cstdio>
#include <fstream>
#include <algorithm>
//{{{define
#define rint register int
#define lc(x) tree[x].lc
#define rc(x) tree[x].rc
#define val(x) tree[x].val
#define dis(x) tree[x].dis
#define fa(x) tree[x].fa
//}}}
using namespace std;
const int maxn = 150005;
//{{{cin
struct IO{
	template<typename T>
	IO & operator>>(T&res){
		res=0;
		bool flag=false;
		char ch;
		while((ch=getchar())>'9'||ch<'0')	 flag|=ch=='-';
		while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^'0'),ch=getchar();
		if (flag)	 res=~res+1;
		return *this;
	}
}cin;
//}}}
struct Tree{
	int val,lc,rc,dis,fa;
}tree[maxn];
inline void init (int n)
{
	for (int i=1;i<=n;++i)	fa(i)=i;
}
inline int find (int x)
{
	if (x==fa(x))	return x;
	return fa(x)=find(fa(x));
}
inline int Merge (int x,int y)
{
	if (!x||!y)	return x+y;
	if (val(x)>val(y))	swap(x,y);
	rc(x)=Merge(rc(x),y);
	fa(rc(x))=x;
	if (dis(lc(x))<dis(rc(x)))	swap(lc(x),rc(x));
	dis(x)=dis(rc(x))+1;
	return x;
}
inline void pop (int x)
{
	val(x)=-1;
	fa(lc(x))=lc(x);
	fa(rc(x))=rc(x);
	fa(x)=Merge(lc(x),rc(x));
	lc(x)=rc(x)=dis(x)=0;
}
