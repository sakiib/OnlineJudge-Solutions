#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long LL;

LL ara[N];
LL cnt[N];
LL ans[N];

struct query {
    LL l,r,d;
    query() {l=0,r=0,d=0;}
    query(LL _l,LL _r,LL _d) {
        l=_l,r=_r,d=_d;
    }
}tree[N];

int main(int argc,char const *argv[]) {
    LL n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    for(int i=1;i<=m;i++) {
        scanf("%lld%lld%lld",&tree[i].l,&tree[i].r,&tree[i].d);
    }
    for(int i=1;i<=k;i++) {
        LL a,b;
        scanf("%lld%lld",&a,&b);
        cnt[a]++; cnt[b+1]--;
    }
    for(int i=1;i<=100000;i++) {
        cnt[i]+=cnt[i-1];
    }
    for(int i=1;i<=m;i++) {
        ans[tree[i].l]+=(tree[i].d*cnt[i]);
        ans[tree[i].r+1]-=(tree[i].d*cnt[i]);
    }
    for(int i=1;i<=100000;i++) {
        ans[i]+=ans[i-1];
    }
    for(int i=1;i<=n;i++) {
        printf("%lld ",(ara[i]+ans[i]));
    }
    return 0;
}
