#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long LL;
LL tree[4*N],lazy[4*N];

void update(LL node,LL b,LL e,LL i,LL j,LL val) {
    if(lazy[node]!=0) {
        tree[node]+=(lazy[node]*(e-b+1));
        if(b!=e) {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
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
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
}
LL query(LL node,LL b,LL e,LL i,LL j) {
    if(lazy[node]!=0) {
        tree[node]+=(lazy[node]*(e-b+1));
        if(b!=e) {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node];
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    LL p1=query(left,b,mid,i,j);
    LL p2=query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);

    for(tc=1;tc<=t;tc++) {
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        LL n,q;
        scanf("%lld%lld",&n,&q);
        printf("Case %d:\n",tc);
        while(q--) {
            LL op;
            scanf("%lld",&op);
            LL l,r,val;
            switch(op) {
                case 0: scanf("%lld%lld%lld",&l,&r,&val);
                        update(1,1,n,l+1,r+1,val);
                        break;
                case 1: scanf("%lld%lld",&l,&r);
                        printf("%lld\n",query(1,1,n,l+1,r+1));
                        break;
            }
        }
    }
    return 0;
}
