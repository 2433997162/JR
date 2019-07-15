//注，请输入大写字母 
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 20005;
int ch[maxn][27],tot,n,m;
char s[maxn];
bool exist[maxn];
void insert (char *str)//string
{
	int len = strlen(str+1),//注意
	node = 0;
	for (int i=1;i<=len;i++){
		int to = str[i]-'A';
		if (!ch[node][to]) ch[node][to] = ++tot;
		node = ch[node][to];
	}
	exist[node] = true;
}
bool find (char *str)//string
{
	int len = strlen(str+1),//注意
	    node = 0;
	for (int i=1;i<=len;i++){
		int to = str[i]-'0';
		if (!ch[node][to]) return false;
		node=ch[node][to];
	}
	return true;
}
int main ()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert(s);
	}
	for (int i=1;i<=m;i++){
		scanf("%s",s+1);
		if (find(s))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
