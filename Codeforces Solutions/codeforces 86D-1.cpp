#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL block=450,n,q,l=0,r=-1;
LL ara[200005];
LL cnt[1000005],sum=0,ans[200005];
struct query {
    LL l,r,id;
    bool operator<(const query &q)const {
        LL block_a=l/block;
        LL block_b=q.l/block;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
}Q[200005];
void add(LL idx) {
    sum-=cnt[ara[idx]]*cnt[ara[idx]]*ara[idx];
    cnt[ara[idx]]++;
    sum+=cnt[ara[idx]]*cnt[ara[idx]]*ara[idx];
}
void rem(LL idx) {
    sum-=cnt[ara[idx]]*cnt[ara[idx]]*ara[idx];
    cnt[ara[idx]]--;
    sum+=cnt[ara[idx]]*cnt[ara[idx]]*ara[idx];
}
void MO() {
    sort(Q,Q+q);
    for(int i=0;i<q;i++) {
        while(l<Q[i].l) rem(l++);
        while(r<Q[i].r) add(++r);
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) rem(r--);
        ans[Q[i].id]=sum;
    }
}
int main(int argc,char const *argv[]) {
    scanf("%lld%lld",&n,&q);
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
