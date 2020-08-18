#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

LL tree[4*100005],lazy[4*100005];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node]=0;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void Update(LL node,LL b,LL e,LL i, LL j,LL val) {
    if(lazy[node]!=-1) {
        tree[node]+=(lazy[node]*(e-b+1));
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e||j<b) return;
    if(i<=b&&e<=j) {
        tree[node]+=(val*(e-b+1));
        if(b!=e) {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    Update(left,b,mid,i,j,val);
    Update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
}
LL Query(LL node,LL b,LL e,LL i,LL j) {
    if(lazy[node]!=-1) {
        tree[node]+=(lazy[node]*(e-b+1));
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=-1;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&e<=j) return tree[node];
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    LL p1=Query(left,b,mid,i,j);
    LL p2=Query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        memset(tree,0,sizeof(0));
        memset(lazy,-1,sizeof(lazy));
        LL n,q;
        scanf("%lld%lld",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            LL op;
            scanf("%lld",&op);
            if(op==0) {
                LL l,r,val;
                scanf("%lld%lld%lld",&l,&r,&val);
                l++,r++;
                Update(1,1,n,l,r,val);
            }
            else if(op==1) {
                LL l,r;
                scanf("%lld%lld",&l,&r);
                l++,r++;
                LL ans=Query(1,1,n,l,r);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
