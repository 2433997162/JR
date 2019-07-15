#include <cstdio>
using namespace std;
const int maxn = 3e6+5;
long long n,mod,inv[maxn];
int main ()
{
    /*
     * ax%p == 1 ��x��a%p�µ���Ԫ
     * ��������Ԫ
     * ���i����Ԫ��ʱ��
     * ��p = ki + r (r<i,1<i<p)
     * ���Եó�ki + r �� 0 mod p (p mod p)
     * ��i'Ϊi����Ԫ,r'Ϊr����Ԫ (ͷ�ϴ�'��ʾ��Ԫ) 
     * ����ͬʱ����i',r'
     * �õ� kr' + i' �� 0 mod p
     * i' = -kr' mod p
     * i' = -p/i * (p mod i)' mod p
     */
    scanf("%lld%lld",&n,&mod);
    printf("1\n");
    inv[1]=1;
    for (int i=2;i<=n;i++){
        inv[i]=-mod/i*inv[mod%i]%mod;
        inv[i]=(inv[i]+mod)%mod;
        printf("%lld\n",inv[i]);
    }
    return 0;
}
