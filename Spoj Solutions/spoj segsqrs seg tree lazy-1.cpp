#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=100005;
LL ara[N];

struct segment {
    LL val,sum,lazy,type;

    segment(){}

    segment(LL val,LL sum,LL lazy,LL type) {
        this->val=val;
        this->sum=sum;
        this->lazy=lazy;
        this->type=type;
    }
} tree[4*N];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node].val=ara[b];
        tree[node].sum=ara[b]*ara[b];
        tree[node].lazy=0;
        tree[node].type=0;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    tree[node].val=tree[left].val+tree[right].val;
    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].lazy=0; tree[node].type=0;
    return;
}
void update_set(LL node,LL b,LL e,LL i,LL j,LL val) {
    if(tree[node].lazy!=0) {
        tree[node].val=(e-b+1)*tree[node].lazy;
        tree[node].sum=(e-b+1)*tree[node].lazy*tree[node].lazy;
        if(b!=e) {
            tree[2*node].lazy=tree[node].lazy;
            tree[2*node+1].lazy=tree[node].lazy;
        }
        tree[node].lazy=0;
    }
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        tree[node].val=(e-b+1)*val;
        tree[node].sum=(e-b+1)*val*val;
        if(b!=e) {
            tree[2*node].lazy=tree[node].lazy;
            tree[2*node+1].lazy=tree[node].lazy;
        }
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    update_set(left,b,mid,i,j,val);
    update_set(right,mid+1,e,i,j,val);
    tree[node].val=tree[left].val+tree[right].val;
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update_add(LL node,LL b,LL e,LL i,LL j,LL val) {

}
LL query(LL node,LL b,LL e,LL i,LL j) {
   if(tree[node].lazy!=0) {
        tree[node].val=(e-b+1)*tree[node].lazy;
        tree[node].sum=(e-b+1)*tree[node].lazy*tree[node].lazy;
        if(b!=e) {
            tree[2*node].lazy=tree[node].lazy;
            tree[2*node+1].lazy=tree[node].lazy;
        }
        tree[node].lazy=0;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node].sum;
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    LL p1=query(left,b,mid,i,j);
    LL p2=query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc,n,q;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        for(int i=1;i<=q;i++) {
            int op;
            scanf("%d",&op);
            LL l,r,val,ans;
            switch(op) {
            case 0: scanf("%lld%lld%lld",&l,&r,&val);
                    update_set(1,1,n,l,r,val);
                    break;
            case 1: scanf("%lld%lld%lld",&l,&r,&val);
                    update_add(1,1,n,l,r,val);
                    break;
            case 2: scanf("%lld%lld",&l,&r);
                    ans=query(1,1,n,l,r);
                    printf("%lld\n",ans);
                    break;
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
