//请输入大写字母
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 151*71;
int n;
char str[151][71];
char T[1000005];
struct AC_automation{
	int ch[maxn][26],val[maxn],fail[maxn],trank[maxn],cnt;
	queue<int>q;
	//s从1开始
	void clear (){
		//清空 
		cnt=0;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
		memset(fail,0,sizeof(fail));
		memset(trank,0,sizeof(trank));
	}
	void insert (char *s,int id){
		//构造模式串的Trie树
		int now=0,v;
		while (*(++s)){
			v=(*s)-'A';
			if (!ch[now][v]) ch[now][v]=++cnt;
			now=ch[now][v];
		}
		val[now]++,trank[now]=id;
	}
	void build (){
		//建 fail数组 
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
	void query (char *s){
		//查询该文本串里模式串出现最多的是哪串，按输入顺序输出模式串 
		int ans[maxn],now=0,v,mx=-1;
		for (int i=0;i<=n;i++)ans[i]=0;
		while (*(++s)){
			v=(*s)-'A';
			now=ch[now][v];
			int temp=now;
			while (temp){
				if (val[temp]){
					ans[trank[temp]]+=val[temp];
					mx=max(mx,ans[trank[temp]]);
				}
				temp=fail[temp];
			}
		}
		printf("%d\n",mx);
		for (int i=1;i<=n;i++)
			if (ans[i]==mx)
				printf("%s\n",str[i]+1);
	}
}AC;
int main ()
{
	scanf("%d",&n);//当n不等于0时就一直输入 
	while(n){
		AC.clear();//n串模式串 
		for (int i=1;i<=n;i++)	scanf("%s",str[i]+1),AC.insert(str[i],i);
		AC.build();
		scanf("%s",T+1);//文本串 
		AC.query(T);
		scanf("%d",&n);
	}
	return 0;
}

