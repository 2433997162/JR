#include <iostream>
using namespace std;
const int maxn = 1000006;
int n,opr,x;
struct Heap{
	int heap[maxn],size;
	void push (int x){
	       	int now=size,nxt;
		heap[++size]=x;
	       	while (now>1){
			nxt=now/2;
			if (heap[now]>=heap[nxt])	return;
			swap(heap[now],heap[nxt]);
			now=nxt;
		}
	}
	int top (){
		if (!size)	return 0;
		return heap[1];
	}
	void pop (){
		int now,nxt;
		if (!size)	return;
		heap[1]=heap[size--];
		now=1;
		while (now*2<=size){
			nxt=now*2;
			if (nxt<size&&heap[nxt+1]<heap[nxt])	++nxt;
			if (heap[now]<=heap[nxt])	break;
			swap(heap[now],heap[nxt]);
			now=nxt;
		}
	}
}h;
int main ()
{
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>opr;
		if (opr==1){
			cin>>x;
			h.push(x);
		}
		else if (opr==2)	cout<<h.top()<<endl;
		else h.pop();
	}
	return 0;
}
