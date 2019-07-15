#include <iostream>
#include <cstring>
#define ll long long
using namespace std;
const int maxn = 205;
const ll mod = 998244353;
//矩阵乘法a*b，就是a的第i行的每个值乘以b的第j列（相对应）的每个值作为新的矩阵的第i行第j列的值 
//所以要求a的行数和b的列数相同
//**注！** 用的时候注意行列的变化！！ 
struct Matrix{
	int line,row;//几行几列
	long long rec[maxn][maxn];
	Matrix (){
		line=0,row=0;
		memset(rec,0,sizeof(rec));
	}
	friend istream & operator >>(istream & is,Matrix &x){
		is>>x.line>>x.row;//输入行列
		for (int i=1;i<=x.line;++i)
			for (int j=1;j<=x.row;++j)
				is>>x.rec[i][j];
	}
	friend ostream & operator <<(ostream & os,Matrix y){
		for (int i=1;i<=y.line;++i){
			for (int j=1;j<=y.row;++j)
				os<<y.rec[i][j]<<" ";
			os<<endl;
		}
	}
	Matrix operator = (const Matrix &a){
		line=a.line,row=a.row;
		for (int i=1;i<=line;++i)
			for (int j=1;j<=row;++j)
				rec[i][j]=a.rec[i][j];
		return *this;
	}
	friend Matrix operator * (const Matrix &a,const Matrix &b){
		Matrix t;
		t.line=a.line,t.row=b.row;
		for (int i=1;i<=a.line;++i)
			for (int j=1;j<=b.row;++j)
				for (int k=1;k<=a.row;++k)
					t.rec[i][j]=(t.rec[i][j]+a.rec[i][k]*b.rec[k][j])%mod;
		return t;
	}
	Matrix operator ^ (int b){
		Matrix s,a;
		a=*this;
		s.line=line>row?line:row,s.row=s.line;
		for (int i=1,j=s.line;i<=j;++i)	s.rec[i][i]=1;
		for (;b;b>>=1,a=a*a)
			if (b&1)	s=s*a;
		return s;
	}
};
