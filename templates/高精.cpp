#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxl=100005;
//该Int 类型只能 ++i，不能i++
//不支持负数运算 
//{{{Int
struct Int{
	int num[maxl];
	bool fs;
	Int(){fs=false;memset(num,0,sizeof(num));}
	void re (){reverse(num+1,num+num[0]+1);}
	void add (int k){num[++num[0]]=k;}
	Int & operator = (Int x){
		memset(num,0,sizeof(num));
		for (int i=0;i<=x.num[0];i++)	num[i]=x.num[i];
		return *this;
	}
	Int operator = (long long x){
		memset(num,0,sizeof(num));
		while (x)	num[++num[0]]=x%10,x/=10;
		reverse(num+1,num+num[0]+1);
		return *this;
	}
	bool operator == (Int x){
		if (fs^x.fs||num[0]!=x.num[0])	return false;
		for (int i=1;i<=num[0];i++)	if (num[i]!=x.num[i])	return false;
		return true;
	}
	bool operator < (const Int x){
		if (num[0]<x.num[0])	return true;
		if (num[0]>x.num[0])	return false;
		for (int i=num[0];i>=1;--i)
			if (num[i]!=x.num[i])	return num[i]<x.num[i];
		return false;
	}
	bool operator < (long long x){
		long long y=x,len=0;
		while (y)	++len,y/=10;
		if ((num[0]==1&&num[1]==0)||!num[0]){
			if (x)	return true;
			else return false;
		}
		if (len==num[0])
			for (int i=num[0];i>=1;--i)	y=(y<<3)+(y<<1)+num[i];
		else return num[0]<len;
		return y<x;
	}
	bool operator <= (Int x){
		if (num[0]<x.num[0])	return true;
		if (num[0]>x.num[0])	return false;
		for (int i=num[0];i>=1;i--)
			if (num[i]!=x.num[i])	return num[i]<x.num[i];
		return true;
	}
	bool operator <= (long long x){
		long long y=x,len=0;
		while (y)	++len,y/=10;
		if (num[0]==1&&num[1]==0||!num[0])
			if (x)	return true;
		if (len==num[0])
			for (int i=num[0];i>=1;--i)	y=(y<<3)+(y<<1)+num[i];
		else return num[0]<=len;
		return y<=x;
	}
	bool operator > (Int x){
		return !(*this<=x);
	}
	bool operator > (long long x){
		return !(*this<=x);
	}
	inline bool operator >= (Int x){
		return !(*this<x);
	}
	inline bool operator >= (long long x){
		return !(*this<x);
	}
	Int operator * (Int x){
		Int y;
		y.num[0]=num[0]+x.num[0];
		for (int i=1;i<=num[0];i++)
			for (int j=1;j<=x.num[0];j++){
				y.num[i+j-1]+=num[i]*x.num[j];
				y.num[i+j]+=y.num[i+j-1]/10;
				y.num[i+j-1]%=10;	
			}
		while (y.num[0]>1&&!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator * (long long x){
		Int y;
		while (x){
			y.num[++y.num[0]]=x%10;
			x/=10;
		}
		return *this*y;
	}
	Int operator + (Int x){
		Int y;
		y.num[0]=max(num[0],x.num[0])+1;
		for (int i=1;i<=y.num[0];i++){
			y.num[i]+=x.num[i]+num[i];
			y.num[i+1]=y.num[i]/10;
			y.num[i]%=10;
		}
		while (y.num[0]>1&&!y.num[y.num[0]])	--y.num[0];
		return y;
	}
	Int operator + (long long x){
		Int y;
		while (x){
			y.num[++y.num[0]]=x%10;
			x/=10;
		}
		return (y+*this);
	}
	Int operator += (Int x){
		*this=*this+x;
		return *this;
	}
	Int operator += (long long x){
		*this=*this+x;
		return *this;
	}
	Int operator ++ (){
		*this=*this+1;
		return *this;
	}
	Int operator *= (Int x){
		*this=*this*x;
		return *this;
	}
	Int operator *= (long long x){
		*this=*this*x;
		return *this;
	}
	Int operator - (Int x){
		Int y;
		y.num[0]=num[0];
		for (int i=1;i<=num[0];i++){
			y.num[i]+=num[i]-x.num[i];
			if (y.num[i]<0){
				y.num[i]+=10;
				y.num[i+1]--;
			}
		}
		while (y.num[0]&&!y.num[y.num[0]])	y.num[0]--;
		return y;
	}
	Int operator -= (Int x){
		*this=*this-x;
		return *this;
	}
	Int operator / (Int x){
		Int y,tans;
		if (*this<x)	return y;
		for (int i=num[0];i>=1;--i){
			y.add(num[i]);
			y.re();
			while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
			while (y>=x&&y>0)	y-=x,++tans.num[i];
			y.re();
		}
		tans.num[0]=num[0];
		while (tans.num&&!tans.num[tans.num[0]])	--tans.num[0];
		return tans;
	}
	Int operator / (long long x){
		Int tans;
		long long t=0;
		for (int i=num[0];i>=1;--i){
			t=(t<<3)+(t<<1)+num[i];
			tans.num[i]=t/x;
			if (!tans.num[0]&&tans.num[i])	tans.num[0]=i;
			t%=x;
		}
		return tans;
	}
	Int operator /= (Int x){
		*this=*this/x;
		return *this;
	}
	Int operator /= (long long x){
		*this=*this/x;
		return *this;
	}
	Int operator % (Int x){
		Int y;
		if (*this<x)	return *this;
		for (int i=num[0];i>=1;--i){
			y.add(num[i]);
			y.re();
			while (y.num[0]&&!y.num[y.num[0]])	--y.num[0];
			while (y>=x&&y>0)	y-=x;
			y.re();
		}
		return y;
	}
	Int operator % (long long x){
		return *this-*this/x*x;
	}
	Int operator %= (Int x){
		*this=*this%x;
		return *this;
	}
	Int operator %= (long long x){
		*this=*this%x;
		return *this;
	}
	friend ostream & operator <<(ostream & os,Int x){
		if (x.num[0]==0){os<<0;return os;}
		if (x.fs)	os<<'-';
		for (int i=x.num[0];i;i--)	os<<x.num[i];
		return os;
	}
	friend istream & operator >>(istream & is,Int &x){
		char s[10001];
		is>>(s+1);
		x.num[0]=strlen(s+1);
		for (int i=x.num[0];i>0;i--)	x.num[i]=s[x.num[0]-i+1]-'0';
		if (x.num[0]<0){x.num[0]=-x.num[0];x.fs=true;}
		return is;
	}
};
//}}}
