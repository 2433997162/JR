#include <iostream>
#include <cstring>
#include <algorithm>
#define rint register int
using namespace std;
const int maxn = 1000006;
int n,m=122;
int sa[maxn],rk[maxn],h[maxn],cup[maxn],fkey[maxn],skey[maxn];
//suffix[i]表示从原字符串第i个字符开始到字符串结尾的后缀
//sa[i]表示排名为i的是以sa[i]开始到字符串结尾的后缀
//rk[i]保存的是后缀i在所有后缀中从小到大排列的“名次”
//h[i]表示排名i-1和i的最长公共前缀
//fkey[i]表示第i个元素的第一关键字
//skey[i]表示第二关键字排名为i的数，下一轮第一关键字的sa 
//cup就是桶
char s[maxn];
inline void get_sa ()
{
	for (rint i=1;i<=n;++i)	++cup[fkey[i]=s[i]];
	for (rint i=2;i<=m;++i)	cup[i]+=cup[i-1];
	for (rint i=n;i>=1;--i)	sa[cup[fkey[i]]--]=i;
	for (rint k=1;k<=n;k<<=1){
		rint num=0;
		for (rint i=n-k+1;i<=n;++i)	skey[++num]=i;
		for (rint i=1;i<=n;++i)
			if (sa[i]>k)	skey[++num]=sa[i]-k;
		for (rint i=1;i<=m;++i)	cup[i]=0;
		for (rint i=1;i<=n;++i)	++cup[fkey[i]];
		for (rint i=2;i<=m;++i)	cup[i]+=cup[i-1];
		for (rint i=n;i>=1;--i)	sa[cup[fkey[skey[i]]]--]=skey[i],skey[i]=0;
		//按第二关键字排序 
		swap(fkey,skey);
		// 求第一关键字 
		fkey[sa[1]]=num=1;
		for (rint i=2;i<=n;++i)	
			fkey[sa[i]]=(skey[sa[i]]==skey[sa[i-1]] && skey[sa[i]+k]==skey[sa[i-1]+k]) ? num : ++num;
		if (num==n)	break;
		m=num;
	}
}
inline void get_h ()
{
	for (rint i=1;i<=n;++i)	rk[sa[i]]=i;
	for (rint i=1;i<=n;++i){
		if (rk[i]==1)	continue;
		h[rk[i]]=h[rk[i-1]];//h[rk[i]]>=h[rk[i-1]]-1
		if (h[rk[i]])	--h[rk[i]];
		while (sa[rk[i]-1]+h[rk[i]]<=n&&i+h[rk[i]]<=n&&s[i+h[rk[i]]]==s[sa[rk[i]-1]+h[rk[i]]])	++h[rk[i]];
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	cin>>(s+1);
	n=strlen(s+1);
	get_sa();
	get_h();
	for (int i=1;i<=n;++i)	cout<<sa[i]<<" ";
	return 0;
}

