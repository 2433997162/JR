//�������д��ĸ
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
	//s��1��ʼ
	void clear (){
		//��� 
		cnt=0;
		memset(ch,0,sizeof(ch));
		memset(val,0,sizeof(val));
		memset(fail,0,sizeof(fail));
		memset(trank,0,sizeof(trank));
	}
	void insert (char *s,int id){
		//����ģʽ����Trie��
		int now=0,v;
		while (*(++s)){
			v=(*s)-'A';
			if (!ch[now][v]) ch[now][v]=++cnt;
			now=ch[now][v];
		}
		val[now]++,trank[now]=id;
	}
	void build (){
		//�� fail���� 
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
	//s��1��ʼ
	void query (char *s){
		//��ѯ���ı�����ģʽ�������������Ĵ���������˳�����ģʽ�� 
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
	scanf("%d",&n);//��n������0ʱ��һֱ���� 
	while(n){
		AC.clear();//n��ģʽ�� 
		for (int i=1;i<=n;i++)	scanf("%s",str[i]+1),AC.insert(str[i],i);
		AC.build();
		scanf("%s",T+1);//�ı��� 
		AC.query(T);
		scanf("%d",&n);
	}
	return 0;
}

