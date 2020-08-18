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
    LL n;
    while(scanf("%lld",&n)) {
        if(n==0) break;
        vector<LL> fact;
        LL k=sqrt(n);
        for(LL i=1;i<=k;i++) {
            if(n%i==0){
                if(n/i!=i) {
                    fact.push_back(n/i);
                    fact.push_back(i);
                }
                else fact.push_back(i);
            }
        }
        int ans=1;
        for(int i=0;i<fact.size();i++) {
            for(int j=i+1;j<fact.size();j++) {
                if(LCM(fact[i],fact[j])==n) ans++;
            }
        }
        printf("%lld %d\n",n,ans);
    }
    return 0;
}
