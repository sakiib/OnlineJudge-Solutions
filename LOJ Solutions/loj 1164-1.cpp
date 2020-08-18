#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ara[100005];
struct segment {
    LL sum,prop;
    segment () {sum=0,prop=0;}
    segment(LL _sum,LL _prop) {
        sum=_sum,prop=_prop;
    }
}tree[4*100005];

void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node].sum=0;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].sum=0;
}
void Update(LL node,LL b,LL e,LL i,LL j,LL val) {
    if(i>e||j<b) return;
    if(i<=b&&j>=e) {
        tree[node].sum+=((e-b+1)*val);
        tree[node].prop+=val;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    Update(left,b,mid,i,j,val);
    Update(right,mid+1,e,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
LL Query(LL node,LL b,LL e,LL i,LL j,LL carry) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) {
        return tree[node].sum+(e-b+1)*carry;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    LL p1=Query(left,b,mid,i,j,carry+tree[node].prop);
    LL p2=Query(right,mid+1,e,i,j,carry+tree[node].prop);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        memset(ara,0,sizeof(ara));
        memset(tree,0,sizeof(tree));
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            LL k;
            scanf("%lld",&k);
            if(k==0) {
                LL l,r,val;
                scanf("%lld%lld%lld",&l,&r,&val);
                l++,r++;
                Update(1,1,n,l,r,val);
            }
            else if(k==1) {
                LL l,r;
                scanf("%lld%lld",&l,&r);
                l++,r++;
                LL ans=Query(1,1,n,l,r,0);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
