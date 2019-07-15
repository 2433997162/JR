#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 4000006;
const double pi = acos(-1.0);
struct IO{
	template<class T>
	IO operator >> (T &res){
		res=0;
		char ch;
		bool flag=false;
		while ((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while (ch>='0'&&ch<='9')	res=(res<<3)+(res<<1)+(ch^'0'),ch=getchar();
		if (flag)	res=~res+1;
		return *this;
	}
}cin;
struct complex {
	double x,y;
	complex (double xx=0,double yy=0) {x=xx,y=yy;}
};
complex operator + (complex a,complex b) { return complex(a.x+b.x,a.y+b.y);}
complex operator - (complex a,complex b) { return complex(a.x-b.x,a.y-b.y);}
complex operator * (complex a,complex b) { return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
int n,m,bit,len,val;
int rev[maxn];
complex a[maxn],b[maxn],ans[maxn],buf[maxn];
void FFT (complex *a,int len,int on_off)//on_off=1 : FFT      on_off=-1 : IFFT
{
	if (len==1)	return ;
	int mid=len/2;
	for (int i=0;i<=mid-1;++i)	buf[i]=a[i*2],buf[i+mid]=a[i*2+1];
	for (int i=0;i<=len;++i)	a[i]=buf[i];
	FFT(a,mid,on_off),FFT(a+mid,mid,on_off);
	complex wn=complex(cos(2*pi/len),on_off*sin(2*pi/len)),w(1,0);
	for (int i=0;i<=mid-1;++i){
		buf[i]=a[i]+w*a[i+mid];
		buf[i+mid]=a[i]-w*a[i+mid];
		w=w*wn;
	}
	for (int i=0;i<=len;++i)	a[i]=buf[i];
}
void FFT2 (complex *a,int len,int on_off)//on_off=1 : FFT     on_off=-1 : IFFT
{
	for (int i=0;i<=len-1;++i)
		if (i<rev[i])	swap(a[i],a[rev[i]]);
	for (int i=1;i<len;i<<=1){
		complex wn=complex (cos(pi/i),on_off*sin(pi/i));
		for (int j=0;j<len;j+=(i<<1)){
			complex w(1,0);
			for (int k=0;k<i;++k){
				complex u=a[j+k],t=w*a[i+j+k];
				a[j+k]=u+t;
				a[i+j+k]=u-t;
				w=w*wn;
			}
		}
	}
}
int main ()
{
	cin>>n>>m;
	for (int i=0;i<=n;++i)	cin>>val,a[i].x=val;
	for (int i=0;i<=m;++i)	cin>>val,b[i].x=val;
	len=1;
	while (len<=n+m)	++bit,len<<=1;
	for (int i=0;i<=len-1;++i)	rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
	FFT2(a,len,1);
	FFT2(b,len,1);
	for (int i=0;i<=len;++i)	ans[i]=a[i]*b[i];
	FFT2(ans,len,-1);
	for (int i=0;i<=n+m;++i)	printf("%d ",int(ans[i].x/len+0.5));
	return 0;
}
