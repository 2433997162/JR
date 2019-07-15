//请输入大写字母
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 1000005;
int n;
char str[maxn];
struct AC_automation{
	int ch[maxn][26],val[maxn],fail[maxn],cnt;
	queue<int>q;
	//s从1开始
	void insert (char *s){
		int now=0,v;
		while (*(++s)){
			v=(*s)-'A';
			if (!ch[now][v]) ch[now][v]=++cnt;
			now=ch[now][v];
		}
		val[now]++;
	}
	void build (){
		for (int i=0;i<=25;i++)	
			if (ch[0][i])
				fail[ch[0][i]]=0,q.push(ch[0][i]);
		while (!q.empty()){
			int u=q.front();
			q.pop();
			for (int i=0;i<=25;i++){
				if (ch[u][i])	fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
				else ch[u][i]=ch[fail[u]][i];
			}
		}
	}
	//s从1开始
	int query (char *s){
		int ans=0,now=0,v;
		while (*(++s)){
			v=(*s)-'A';
			now=ch[now][v];
			int temp=now;
			while (temp&&~val[temp])	ans+=val[temp],val[temp]=-1,temp=fail[temp];
		}
		return ans;
	}
}AC;
int main ()
{
	scanf("%d",&n);
	while(n--){
		scanf("%s",str+1);
		AC.insert(str);
	}
	AC.build();
	scanf("%s",str+1);
	printf("%d",AC.query(str));
	return 0;
}
