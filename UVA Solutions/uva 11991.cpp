#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ara[1000005];
vector<LL> V[1000005];

int main(int argc,char const *argv[]) {
    LL n,q;
    while(scanf("%lld%lld",&n,&q)!=EOF) {
        for(LL i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
            V[ara[i]].push_back(i);
        }
        while(q--) {
            LL k,val;
            scanf("%lld%lld",&k,&val);
            if(V[val].size()<k) printf("0\n");
            else printf("%lld\n",V[val][k-1]);
        }
    }
    return 0;
}
