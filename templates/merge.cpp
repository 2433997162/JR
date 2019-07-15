const int maxn = 200005;
int nx;
int tmp[maxn];
void merge(int l,int r)
{
	if (l>=r)	return ;
	int mid=(l+r)>>1,i=l,j=mid+1,k=l-1;
	merge(l,mid);
	merge(r,mid+1);
	while (i<=mid&&j<=r){
		if (a[i]<=a[j])	tmp[++k]=a[i++];
		else	tmp[++k]=a[j++],nx+=mid-i+1;
	}
	while (i<=mid)	tmp[++k]=a[i++];
	while (j<=r)	tmp[++k]=a[j++];
	for (i=l;i<=r;++i)	a[i]=tmp[i];
}
