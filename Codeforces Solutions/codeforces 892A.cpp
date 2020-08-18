#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    LL tot=0;
    for(int i=1;i<=n;i++) {
        LL x;
        scanf("%lld",&x);
        tot+=x;
    }
    LL ara[100005];
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    sort(ara+1,ara+n+1);
    LL cap=ara[n]+ara[n-1];
    if(tot<=cap) puts("YES");
    else puts("NO");
    return 0;
}
