#include<bits/stdc++.h>
using namespace std;

int block=350;
int n,q,l=0,r=-1,mx=0;
int ara[100005],ans[100005];
int  M[200005],N[200005];

struct query {
    int l,r,id;
    bool operator<(const query &q)const {
        int block_a=l/block;
        int block_b=q.l/block;
        if(block_a==block_b) return (r<q.r);
        return (block_a<block_b);
    }
}Q[100005];

void rem(int idx) {
    N[M[ara[idx]]]--;
    if(N[M[ara[idx]]]<=0) mx--;
    M[ara[idx]]--;
}
void add(int idx) {
    M[ara[idx]]++;
    N[M[ara[idx]]]++;
    mx=max(mx,M[ara[idx]]);
}
void MO() {
    sort(Q,Q+q);
    for(int i=0;i<q;i++) {
        while(r<Q[i].r) add(++r);
        while(l>Q[i].l) add(--l);
        while(r>Q[i].r) rem(r--);
        while(l<Q[i].l) rem(l++);
        ans[Q[i].id]=mx;
    }
}
int main(int argc,char const *argv[]) {
    while(scanf("%d",&n)) {
        if(n==0) break;
        scanf("%d",&q);
        l=0,r=-1,mx=0;
        for(int i=0;i<n;i++) {
            scanf("%d",&ara[i]);
            ara[i]+=100000;
        }
        for(int i=0;i<q;i++) {
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].l--; Q[i].r--;
            Q[i].id=i;
        }
        MO();
        for(int i=0;i<q;i++) {
            printf("%d\n",ans[i]);
        }
        memset(M,0,sizeof(M));
        memset(N,0,sizeof(N));
    }
    return 0;
}
