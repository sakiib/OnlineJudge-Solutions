#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL BigMod(LL b,LL p,LL mod) {
    if(p==0) return 1LL;
    if(p==1) return b%mod;
    if(p%2==0) {
        LL ans=BigMod(b,p/2,mod);
        return (ans%mod*ans%mod)%mod;
    }
    else {
        LL temp=b%mod;
        LL ans=BigMod(b,p/2,mod);
        return (temp%mod*ans%mod*ans%mod)%mod;
    }
}
int main(int argc,char const *argv[]) {
    LL B,P,M;
    while(scanf("%lld%lld%lld",&B,&P,&M)!=EOF) {
        LL ans=BigMod(B,P,M);
        printf("%lld\n",ans);
    }
    return 0;
}
