#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL ara[500010];

void calc() {
    for(LL i=1;i<=500005;i++) {
        for(LL j=i;j<=500005;j+=i) {
            ara[j]+=i;
        }
    }
}
int main(int argc,char const *argv[]) {
    calc();
    int t;
    scanf("%d",&t);
    while(t--) {
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",ara[n]-n);
    }
    return 0;
}
