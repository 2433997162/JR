int quick_pow_mod (int a,int b,int c)//return a^b%c
{
	int s = 1;
	while (b){
		if (b & 1)	s=s * a % c;
		a = a * a % c;
		b >>= 1;
	}
	return s;
}
