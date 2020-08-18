#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long int LL;
LL tree[4*N],lazy[4*N];

void Update(LL node,LL b,LL e,LL i,LL j,LL val) {
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
    Update(left,b,mid,i,j,val);
    Update(right,mid+1,e,i,j,val);
    tree[node]=tree[left]+tree[right];
    return;
}
LL Query(LL node,LL b,LL e,LL i,LL j) {
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
    LL p1=Query(left,b,mid,i,j);
    LL p2=Query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int tc,t;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,q;
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        scanf("%lld%lld",&n,&q);
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
