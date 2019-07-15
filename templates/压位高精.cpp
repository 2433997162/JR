#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10001;
const int power = 4;//压多少位 达到10位把int 改为 long long 
const int base = 10000;//10的几次方 
//输入不是cin而是a.in()
//输出不是cout而是a.out()
//不能++
//有这些运算符可用 + += - -= * *= / /= < <= > >=
struct Int {
	int num[maxn];
	Int (){memset(num,0,sizeof(num));}
	void add (int k){if (k||num[0])	num[++num[0]]=k;}
	void re(){reverse (num+1,num+num[0]+1);}
	friend bool operator < (const Int & x,const Int & y){
		if (x.num[0]<y.num[0])	return true;
		if (x.num[0]>y.num[0])	return false;
		for (int i=x.num[0];i>=1;--i)
			if (x.num[i]!=y.num[i])	return x.num[i]<y.num[i];
		return false;
	}
	friend bool operator <= (const Int & x,const Int & y){
		if (x.num[0]<y.num[0])	return true;
		if (x.num[0]>y.num[0])	return false;
		for (int i=x.num[0];i>=1;i--)
			if (x.num[i]!=y.num[i])	return x.num[i]<y.num[i];
		return true;
	}
	friend bool operator == (const Int & x,const Int & y){
		for (int i=0;i<=x.num[0];i++)	if (x.num[i]!=y.num[i])	return false;
		return true;
	}
	friend bool operator > (const Int & x,const Int & y){
		return !(x<=y);
	}
	friend bool operator >= (const Int & x,const Int & y){
		return !(x<y);
	}
	void in(){
		int k=base,len;
		char s[maxn];
		scanf("%s",s+1);
		len=strlen(s+1);//从后往前读 
		for (int i=len;i>=1;--i,k*=10){
			if (k==base)	++num[0],k=1;
			num[num[0]]=num[num[0]]+k*(s[i]-'0');
		}
	}
	void out (){
		printf("%d",num[num[0]]);
		for (int i=num[0]-1;i>=1;--i)	printf("%0*d",power,num[i]);
		printf("\n");
	}
	Int operator = (Int x){
		memset(num,0,sizeof(num));
		for (int i=0;i<=x.num[0];i++)	num[i]=x.num[i];
		return *this;
	}
	Int operator = (long long x){
		memset(num,0,sizeof(num));
		while (x)	num[++num[0]]=x%base,x/=base;
		return *this;
	}
	Int operator + (Int x){
		Int y;
		y.num[0]=max(num[0],x.num[0])+1;
		for (int i=1;i<=y.num[0];i++){
			y.num[i]+=num[i]+x.num[i];
			y.num[i+1]+=y.num[i]/base;
			y.num[i]%=base;
		}
		while (!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator += (Int x){
		*this=*this+x;
		return *this;
	}
	Int operator - (Int x){
		Int y;
		for (int i=1;i<=y.num[0];++i){
			y.num[i]+=num[i]-x.num[i];
			if (y.num[i]<0)	y.num[i]+=base,--y.num[i+1];
		}	
		while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator -= (Int x){
		for (int i=1;i<=num[0];++i){
			num[i]-=x.num[i];
			if (num[i]<0)	num[i]+=base,--num[i+1];
		}	
		while (num[0]&&!num[num[0]])	--num[0];
		return *this;
	}
	Int operator * (Int x){
		Int y;
		y.num[0]=num[0]+x.num[0];
		for (int i=1;i<=num[0];++i)
			for (int j=1;j<=x.num[0];++j){
				y.num[i+j-1]+=num[i]*x.num[j];
				y.num[i+j]+=y.num[i+j-1]/base;
				y.num[i+j-1]%=base;
			}
		while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator *= (Int x){
		*this=*this*x;
		return *this;
	}
	Int operator / (Int x){
		Int ans,y,z;
		z.num[1]=z.num[0]=1;
		for (int i=num[0];i>=1;--i){
			y.add(num[i]);
			y.re();
			while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
			while (y>=x&&y>=z)	y-=x,++ans.num[i];
			y.re();
		}
		ans.num[0]=num[0];
		while (ans.num[0]&&!ans.num[ans.num[0]])	--ans.num[0];
		return ans;
	}
	Int operator /= (Int x){
		*this=*this/x;
		return *this;
	}
	Int operator % (Int x){
		Int y;
		for (int i=num[0];i>=1;--i){
			y.add(num[i]);
			y.re();
			while (y>=x)	y-=x;
			y.re();
		}
		while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator %= (Int x){
		*this=*this%x;
		return *this;
	}
};
