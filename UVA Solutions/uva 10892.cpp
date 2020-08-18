#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL LCM(LL x,LL y) {
    LL g=__gcd(x,y);
    LL lcm=x/g*y;
    return lcm;
}
int main(int argc,char const *argv[]) {
    LL n,y,l;
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld",&n);
        for(int i=1;i<=n;i++) {
            for(int j=i;j<=n;j++) {
                if(LCM(i,j)==n) {
                    cout<<i<<" "<<j<<endl;
                }
            }
        }
    }
    return 0;
}
