void write(int x)
{
	if (x<0)putchar('-'),x=-x;
	if (!x)return;
	write(x/10);
	putchar(x%10+'0');
}
