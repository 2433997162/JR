int mu (int n)
{
	if (n==1)	return 1;
	int res=1;
	for (int i=2;i*i<=n;++i)
		if (n%i==0){
			++res;
			n/=i;
			if (n%i==0)	return 0;
		}
	if (res&1)	return -1;
	return 1;
}
