const int h = 29;
ull hash (char *s,int len)
{
	ull res=0;
	for (int i=1;i<=len;++i)	res=res*h+s[i]-'a';
	return res;
}
