#include<bits/stdc++.h>
using namespace std;
int block=180,n,q,res=0,l=0,r=-1;
int ara[30005],ans[200005],cnt[1000005];
struct query {
    int l,r,id;
    bool operator<(const query &q)const {
        int block_a=l/block;
        int block_b=q.l/block;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
}Q[200005];
void rem(int idx) {
    if(cnt[ara[idx]]>=1) res--;
    cnt[ara[idx]]--;
    if(cnt[ara[idx]]>=1) res++;
}
void add(int idx) {
    if(cnt[ara[idx]]>=1) res--;
    cnt[ara[idx]]++;
    if(cnt[ara[idx]]>=1) res++;
}
void MO() {
    sort(Q,Q+q);
    for(int i=0;i<q;i++) {
        while(r<Q[i].r) add(++r);
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) rem(r--);
        while(l<Q[i].l) rem(l++);
        ans[Q[i].id]=res;
    }
}
int main(int argc,char const *argv[]) {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&ara[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++) {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].l--; Q[i].r--;
        Q[i].id=i;
    }
    MO();
    for(int i=0;i<q;i++) {
        printf("%d\n",ans[i]);
    }
    return 0;
}
