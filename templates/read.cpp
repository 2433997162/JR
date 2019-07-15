struct IO{
	template<class T>
	IO& operator>>(T&res)
	{
		res=0;
		bool flag=false;
		char ch;
		while ((ch=getchar())>'9'||ch<'0')	flag|=ch=='-';
		while (ch>='0'&&ch<='9')	res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
		if (flag) res=-res;
		return *this;
	}
}cin;
