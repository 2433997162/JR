#include <cstdio>
using namespace std;
const int maxn = 3e6+5;
long long n,mod,inv[maxn];
int main ()
{
    /*
     * ax%p == 1 ，x叫a%p下的逆元
     * 线性求逆元
     * 求第i个逆元的时候
     * 设p = ki + r (r<i,1<i<p)
     * 可以得出ki + r ≡ 0 mod p (p mod p)
     * 设i'为i的逆元,r'为r的逆元 (头上带'表示逆元) 
     * 两边同时乘以i',r'
     * 得到 kr' + i' ≡ 0 mod p
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
