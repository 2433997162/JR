#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 2000006;
int num[maxn];
char s[maxn],p[maxn];
void Manacher ()
{
	int cnt,len,id,r;
	len=strlen(s+1);
	cnt=id=r=0;
	for (int i=1;i<=len;++i,++cnt)	num[++cnt]=s[i]-'a'+1;
	num[cnt+1]=-1;
	for (int i=1;i<=cnt;++i){
		if (i<r)	p[i]=min(p[2*id-i],r-i+1);
		while (num[i+p[i]]==num[i-p[i]])	++p[i];
		if (i+p[i]>=r)	r=i+p[i]-1,id=i;
	}
	len=0;
	for (int i=1;i<=cnt;++i)	--p[i];//直径
}
