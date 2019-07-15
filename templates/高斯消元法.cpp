#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 205;
const double eps = 1e-7;
int n,loc;
double divi;
double ans[maxn];
double map[maxn][maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n+1;++j)
			scanf("%lf",&map[i][j]);
	for (int i=1;i<=n;++i){//枚举列
		loc=i;
		for (int j=i+1;j<=n;++j)//找到系数最大的一列
			if (fabs(map[loc][i])<fabs(map[j][i]))
				loc=j;
		if (fabs(map[loc][i])<eps){
			printf("No Solution\n");
			return 0;
		}
		if (loc!=i)	swap(map[i],map[loc]);//将那行换到现在这行来，防止重复计算
		divi=map[i][i];
		for (int j=i;j<=n+1;++j)	map[i][j]/=divi;
		for (int j=i+1;j<=n;++j){
			divi=map[j][i];//第ｉ行要乘的系数
			for (int k=i;k<=n+1;++k)
				map[j][k]-=map[i][k]*divi;//相当于消去第ｉ列上的数，都减去第ｉ行第ｋ列乘以需要乘的系数
		}
	}
	ans[n]=map[n][n+1];//回带过程
	for (int i=n-1;i>=1;--i){
		ans[i]=map[i][n+1];//先等于右边的常数
		for (int j=i+1;j<=n;++j)
			ans[i]-=map[i][j]*ans[j];
	}
	for (int i=1;i<=n;++i)	printf("%.2lf\n",ans[i]);
	return 0;
}
