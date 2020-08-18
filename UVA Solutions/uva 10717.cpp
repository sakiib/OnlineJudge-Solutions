#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=10000000000;

LL GCD(LL x,LL y) {
    return (y==0)?x:GCD(y,x%y);
}
LL LCM(LL x,LL y) {
    LL g=GCD(x,y);
    return x/g*y;
}

int main(int argc,char const *argv[]) {
    LL n,k;
    while(scanf("%lld%lld",&n,&k)) {
        if(n==0&&k==0) break;
        LL ara[100];
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        while(k--) {
            LL h;
            scanf("%lld",&h);
            LL mx=-INF,mn=INF;
            for(int i=1;i<=n;i++) {
                for(int j=i+1;j<=n;j++) {
                    for(int k=j+1;k<=n;k++) {
                        for(int l=k+1;l<=n;l++) {
                            LL lcm=LCM(ara[i],LCM(ara[j],LCM(ara[k],ara[l])));
                            LL sm=(floor)((double)h/lcm);
                            LL bg=(ceil)((double)h/lcm);
                            mx=max(mx,sm*lcm);
                            mn=min(mn,bg*lcm);
                        }
                    }
                }
            }
            printf("%lld %lld\n",mx,mn);
        }
    }
    return 0;
}
