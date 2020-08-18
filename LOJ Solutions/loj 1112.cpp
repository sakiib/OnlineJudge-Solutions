#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=100005;
LL ara[N];
LL tree[N*4];

void Update(LL Node,LL b,LL e,LL pos,LL add) {
    if(pos>e||pos<b) return;
    if(b==e) {
        tree[Node]+=add;
        return;
    }
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    Update(Left,b,mid,pos,add);
    Update(Right,mid+1,e,pos,add);
    tree[Node]=tree[Left]+tree[Right];
}
void BuildSegmentTree(LL Node,LL b,LL e) {
    if(b==e) {
        tree[Node]=ara[b];
        return;
    }
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    BuildSegmentTree(Left,b,mid);
    BuildSegmentTree(Right,mid+1,e);
    tree[Node]=tree[Left]+tree[Right];
}
int Query(LL Node,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return 0;
    if(b>=i&&e<=j) return tree[Node];
    LL Left=2*Node;
    LL Right=2*Node+1;
    LL mid=(b+e)/2;
    LL p1=Query(Left,b,mid,i,j);
    LL p2=Query(Right,mid+1,e,i,j);
    return (p1+p2);
}
int main(int argc,char const *argv[]) {
    LL t,tc;
    scanf("%lld",&t);
    for(tc=1;tc<=t;tc++) {
        LL n,query;
        scanf("%lld%lld",&n,&query);
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        BuildSegmentTree(1,1,n);
        printf("Case %lld:\n",tc);
        while(query--) {
            LL x;
            scanf("%lld",&x);
            if(x==1) {
                LL k;
                scanf("%lld",&k);
                k++;
                printf("%lld\n",ara[k]);
                Update(1,1,n,k,-ara[k]);
                ara[k]=0;
            }
            else if(x==2) {
                LL add,pos;
                scanf("%lld%lld",&pos,&add);
                pos++;
                ara[pos]+=add;
                Update(1,1,n,pos,add);
            }
            else if(x==3) {
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
