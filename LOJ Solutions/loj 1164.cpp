#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=100005;

LL ara[N];

struct segment {
    LL sum,prop;
    segment () {sum=0,prop=0;}
    segment(LL _sum,LL _prop) {
        sum=_sum,prop=_prop;
    }
}tree[4*N];

LL Query(LL Node,LL b,LL e,LL i,LL j,LL carry) {
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j) {return tree[Node].sum+(e-b+1)*carry;}
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    LL p1=Query(Left,b,mid,i,j,carry+tree[Node].prop);
    LL p2=Query(Right,mid+1,e,i,j,carry+tree[Node].prop);
    return (p1+p2);
}
void Update(LL Node,LL b,LL e,LL i,LL j,LL add) {
    if(i>e||j<b) return;
    if(b>=i&&e<=j) {
        tree[Node].sum+=((e-b+1)*add);
        tree[Node].prop+=add;
        return;
    }
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    Update(Left,b,mid,i,j,add);
    Update(Right,mid+1,e,i,j,add);
    tree[Node].sum=tree[Left].sum+tree[Right].sum+(e-b+1)*tree[Node].prop;
}
void BuildSegmentTree(LL Node,LL b,LL e) {
    if(b==e) {
        tree[Node].sum=0;
        return;
    }
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    BuildSegmentTree(Left,b,mid);
    BuildSegmentTree(Right,mid+1,e);
    tree[Node].sum=0;
}
int main(int argc,char const *argv[]) {
    LL t,tc;
    scanf("%lld",&t);
    for(tc=1;tc<=t;tc++) {
        memset(tree,0,sizeof(tree));
        memset(ara,0,sizeof(0));
        LL n,q;
        scanf("%lld%lld",&n,&q);
        BuildSegmentTree(1,1,n);
        printf("Case %lld:\n",tc);
        while(q--) {
            LL k;
            scanf("%lld",&k);
            if(k==0) {
                LL l,r,add;
                scanf("%lld%lld%lld",&l,&r,&add);
                l++,r++;
                Update(1,1,n,l,r,add);
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
