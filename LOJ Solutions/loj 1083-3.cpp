#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=100000000;
LL ara[30005];
LL tree[4*30005];
LL n;

LL query(LL node,LL b,LL e,LL i,LL j) { //for min index query
    if(i>e||j<b) return inf;
    if(i<=b&&j>=e) return tree[node];
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    LL p1=query(left,b,mid,i,j); LL p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}
LL get_area(LL b,LL e) {
    if(b>e) return 0;
    if(b==e) return ara[b];
    LL idx=query(1,1,n,b,e);
    LL ans=max(get_area(b,idx-1),max(get_area(idx+1,e),((e-b+1)*ara[idx])));
    return ans;
}
void build(LL node,LL b,LL e) { // for minimum index
    if(b==e) {
        tree[node]=b;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid); build(right,mid+1,e);
    if(ara[tree[left]]<ara[tree[right]]) tree[node]=tree[left];
    else tree[node]=tree[right];
}
int main(int argc,char const *argv[]) {
    LL t,tc;
    scanf("%lld",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%lld",&n);
        for(LL i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        build(1,1,n);

        for(int i=1;i<=11;i++) {
            printf("i %d : tree %d \n",i,tree[i]);
        }
        printf("1 3 : %d\n",query(1,1,n,1,3));
        printf("4 5 : %d\n",query(1,1,n,4,5));
        printf("2 4 : %d\n",query(1,1,n,2,4));

        LL ans=get_area(1,n);
        printf("Case %lld: %lld\n",tc,ans);
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
