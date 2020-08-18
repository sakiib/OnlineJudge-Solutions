#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
LL ara[100005];

struct segment {
    LL sum,lazy;
}tree[4*N];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node].sum=ara[b];
        tree[node].lazy=0;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=0;
}
void update(LL n,LL b LL e,LL i,LL j) {
    if(tree[node].lazy!=0) {

    }
}
int main(int argc,char const *argv[]) {
    LL n;
    int tc=1;
    while(scanf("%lld",&n)!=EOF) {
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        build(1,1,n);
        LL q;
        scanf("%lld",&q);
        LL l,r;
        printf("Case #%d:\n",tc++);
        while(q--) {
            LL op;
            scanf("%lld",&op);
            switch(op) {
            case 0 : scanf("%lld%lld",&l,&r);
                     update(1,1,n,l,r);
                     break;
            case 1: scanf("%lld%lld",&l,&r);
                    ans=query(1,1,n,l,r);
                    printf("%lld\n",ans);
                    break;
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
