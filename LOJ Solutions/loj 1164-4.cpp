#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
struct segment {
    LL sum,lazy;
} tree[4*N];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node].sum=0;
        tree[node].lazy=0;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=tree[left].lazy+tree[right].lazy;
}
void update(LL node,LL b,LL e,LL i,LL j,LL val) {
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        tree[node].sum+=(e-b+1)*val;
        tree[node].lazy+=val;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(tree[node].lazy*(e-b+1));
}
LL query(LL node,LL b,LL e,LL i,LL j,LL carry=0) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) {
        return tree[node].sum+carry*(e-b+1);
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    LL p1=query(left,b,mid,i,j,tree[node].lazy+carry);
    LL p2=query(right,mid+1,e,i,j,tree[node].lazy+carry);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    LL t,tc;
    scanf("%lld",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,q;
        scanf("%lld%lld",&n,&q);
        build(1,1,n);
        printf("Case %lld:\n",tc);
        while(q--) {
            LL op;
            scanf("%lld",&op);
            LL l,r,val;
            switch(op) {
            case 0: scanf("%d%d%d",&l,&r,&val);
            update(1,1,n,l+1,r+1,val);
            break;
            case 1: scanf("%lld%lld",&l,&r);
            printf("%lld\n",query(1,1,n,l+1,r+1));
            break;
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
