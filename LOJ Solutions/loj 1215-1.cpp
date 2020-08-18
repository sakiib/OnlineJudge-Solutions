#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL GCD(LL x,LL y) {
    if(x<y) swap(x,y);
    return (y==0)?x:GCD(y,x%y);
}
LL LCM(LL x,LL y) {
    LL g=GCD(x,y);
    return (x/g*y);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL a,b,l;
        scanf("%lld%lld%lld",&a,&b,&l);
        LL lcm=LCM(a,b);
        if(l%lcm!=0) {
            printf("Case %d: impossible\n",tc);
            continue;
        }
        LL k=l/lcm;
        if(k==1||(GCD(k,lcm)==1)) {
            printf("Case %d: %lld\n",tc,k);
            continue;
        }
        LL temp;
        while((temp=GCD(lcm,k))!=1) {
            lcm/=temp;
            k*=temp;
        }
        printf("Case %d: %lld\n",tc,k);
    }
    return 0;
}
