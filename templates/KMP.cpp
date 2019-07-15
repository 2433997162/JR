#include <iostream>
#include <cstring>
using namespace std;
const int maxn=1000005;
int sl,tl;
int nxt[maxn];
bool bl[maxn];
int s[maxn],t[maxn];
void Get_Next (char *s)
{
	int k=0,j=1;
	while (j<=sl){
		if (!k||s[k]==s[j])	nxt[++j]=++k;
		else	k=nxt[k];
	}
}
int Match (char *s,char *t)//how many times s appears in t
{
	sl=strlen(s+1),tl=strlen(t+1);
	Get_Next(s);
	int j=1,k=1,ans=0;
	while (k<=tl){
		if (!j||s[j]==t[k])	++j,++k;
		else	j=nxt[j];
		if (j==sl+1)	j=nxt[j],++ans;
	}
	return ans;
}
