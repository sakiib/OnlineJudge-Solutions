#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const int k=320; //~sqrt(100000)
int n,q,sum=0,l=1,r=0;
int ara[2*N];
int cnt[2*N],ans[2*N],freq[2*N];
map<int,int> M;

struct query {
    int l,r,id;

    query () {}
    query(int _l,int _r,int _id) {
        l=_l, r=_r, id=_id;
    }
    bool operator < (const query &q) const {
        int block_a=l/k, block_b=q.l/k;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
} Q[2*N];

void add(int x) {
    cnt[ara[x]]++;
    sum=max(sum,cnt[ara[x]]);
}
void rem(int x) {
    if(sum==cnt[ara[x]]) {
        sum--;
     }
    cnt[ara[x]]--;
}
void MO() {
    sort(Q+1,Q+q+1);
    l=1,r=0;
    for(int i=1;i<=q;i++) {
        while(l<Q[i].l) rem(l++);
        while(l>Q[i].l) add(--l);
        while(r<Q[i].r) add(++r);
        while(r>Q[i].r) rem(r--);
        freq[Q[i].id]=sum;
    }
}
int main(int argc,char const *argv[]) {

    while(scanf("%d",&n)) {
        if(n==0) break;
        sum=0;
        scanf("%d",&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
            ara[i]+=100000;
        }
        for(int i=1;i<=q;i++) {
            int le,ri;
            scanf("%d%d",&le,&ri);
            Q[i].l=le; Q[i].r=ri; Q[i].id=i;
        }
        MO();
        for(int i=1;i<=q;i++) {
            printf("%d\n",freq[i]);
        }
        for(int i=1;i<=2*N;i++) {
            ans[i]=0,cnt[i]=0;
        }
    }
    return 0;
}

