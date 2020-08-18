#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long LL;
LL ara[N];
LL cum[N];
LL res[N];

struct query {
    LL l,r,add;
    query(){l=0; r=0; add=0;}
    query(LL _l,LL _r,LL _add) {
        l=_l;
        r=_r;
        add=_add;
    }
} Q[N];

int main(int argc,char const *argv[]) {
    LL n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    for(int i=1;i<=m;i++) {
        LL a,b,c;
        scanf("%lld%lld%lld",&Q[i].l,&Q[i].r,&Q[i].add);
    }
    for(int i=1;i<=k;i++) {
        LL x,y;
        scanf("%lld%lld",&x,&y);
        cum[x]++;
        cum[y+1]--;
    }
    for(int i=1;i<=N;i++) {
        cum[i]+=cum[i-1];
    }
    for(int i=1;i<=m;i++) {
        res[Q[i].l]+=(Q[i].add*cum[i]);
        res[Q[i].r+1]-=(Q[i].add*cum[i]);
    }
    for(int i=1;i<=N;i++) {
        res[i]+=res[i-1];
    }
    for(int i=1;i<=n;i++) {
        printf("%lld ",ara[i]+res[i]);
    }
    return 0;
}

