#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL block=450;
LL ara[200005],cnt[1000005],ans[200005];
LL n,q,sum=0;

struct query {
    LL l,r,id;
    bool operator<(const query q) const {
        LL block_a=l/block;
        LL block_b=q.l/block;
        if(block_a==block_b) return (r<q.r);
        else return (block_a<block_b);
    }
}Q[200005];

void add(LL x) {
    LL c=cnt[x];
    sum+=x*(c+c+1);
    cnt[x]++;
}
void rem(LL x) {
    LL c=cnt[x];
    sum-=x*(c+c-1);
    cnt[x]--;
}
void MO() {
    sort(Q,Q+q);
    int l=0,r=-1;
    for(int i=0;i<q;i++) {
        while(l>Q[i].l) add(ara[--l]);
        while(r<Q[i].r) add(ara[++r]);
        while(r>Q[i].r) rem(ara[r--]);
        while(l<Q[i].l) rem(ara[l++]);
        ans[Q[i].id]=sum;
    }
}
int main(int argc,char const *argv[]) {
    scanf("%lld%lld",&n,&q);
    //block=sqrt(n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&ara[i]);
    }
    for(int i=0;i<q;i++) {
        scanf("%lld%lld",&Q[i].l,&Q[i].r);
        Q[i].l--; Q[i].r--;
        Q[i].id=i;
    }
    MO();
    for(int i=0;i<q;i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}
