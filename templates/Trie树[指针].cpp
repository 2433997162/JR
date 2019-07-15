//ע���������д��ĸ 
#include <cstdio>
using namespace std;
const int maxn = 20005;
int n,m;
char s[maxn];
struct Trie_Tree{
	int count;//�м���ǰ׺
	Trie_Tree *sons[27];//������
	bool exist;//�Ƿ�������Ϊ�յ�ĵ���
	Trie_Tree(){
		for (int i=0;i<=26;i++)	sons[i]=NULL;
		count=exist=0;
	}
}root;
void insert (char *str)
{
	Trie_Tree *node;
	node=&root;
	while (*(++ str)){
		int to = *str - 'A';
		if (node->sons[to]==NULL)	node->sons[to] = new Trie_Tree;
		node = node->sons[to];
		(node->count) ++;
	}
	node->exist=true;
}
bool find (char *str)
{
	Trie_Tree *node;
	node=&root;
	while (*(++ str)){
		int to = *str - 'A';
		if (!(node->sons[to]))	return false;
		node=node->sons[to];
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
