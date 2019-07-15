#include <iostream>
using namespace std;
const int maxn = 400005;
struct Segment_Tree{
	//{{{declare
	struct Seg_Tree{
		int l,r;
		long long val,lazy;
		Seg_Tree(){	l=r=val=lazy=0;}
	}seg_tree[maxn];
	long long num[maxn];
	//}}}
	//{{{define
	#define lt(k) seg_tree[k].l
	#define rt(k) seg_tree[k].r
	#define lazy(k) seg_tree[k].lazy
	#define val(k) seg_tree[k].val
	#define cr k<<1|1
	#define cl k<<1
	//}}}
	//{{{push_down(k)
	void push_down(int k)
	{
		lazy(cl)+=lazy(k);
		lazy(cr)+=lazy(k);
		val(cl)+=lazy(k)*(rt(cl)-lt(cl)+1);
		val(cr)+=lazy(k)*(rt(cr)-lt(cr)+1);
		lazy(k)=0;
	}
	//}}}
	//{{{modify(l,r,v,k)
	void modify (int l,int r,long long v,int k=1)
	{
		if (l<=lt(k)&&r>=rt(k)){
			val(k)+=(rt(k)-lt(k)+1)*v;
			lazy(k)+=v;
			return;
		}
		if (lazy(k))    push_down(k);
		int mid=(lt(k)+rt(k))>>1;
		if (l<=mid)	modify(l,r,v,cl);
		if (r>mid)	modify(l,r,v,cr);
		val(k)=val(cl)+val(cr);
	}
	//}}}
	//{{{query(l,r,k)
	long long query (int l,int r,int k=1)
	{
		if (l<=lt(k)&&r>=rt(k))	return val(k);
		if (lazy(k))	push_down(k);
		int mid=(lt(k)+rt(k))>>1;
		long long res=0;
		if (l<=mid)	res+=query(l,r,cl);
		if (r>mid)	res+=query(l,r,cr);
		return res;
	}
	//}}}
	//{{{build(l,r,k)
	void build (int l,int r,int k=1)
	{
		lt(k)=l,rt(k)=r;
		if (l==r){	val(k)=num[l];return;}
		int mid=(l+r)>>1;
		build(l,mid,cl),build(mid+1,r,cr);
		val(k)=val(cl)+val(cr);
	}
	//}}}
};
