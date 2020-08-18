#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=200010;
LL ara[N];
LL tree[4*N];

LL query(LL node,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) {
        return tree[node];
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    LL p1=query(left,b,mid,i,j);
    LL p2=query(right,mid+1,e,i,j);
    return (p1+p2);
}
void update(LL node,LL b,LL e,LL pos,LL val) {
    if(b>pos||e<pos) return;
    if(b==e&&b==pos) {
        tree[node]=val;
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[node]=tree[left]+tree[right];
}
void build(LL node,LL b,LL e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    LL left=2*node;
    LL right=2*node+1;
    LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
int main(int argc,char const *argv[]) {
    LL n;
    int tc=1;
    bool f=false;
    while(scanf("%lld",&n)) {
        if(n==0) break;
        if(f) puts("");
        f=true;
        for(int i=1;i<=n;i++) {
            scanf("%lld",&ara[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",tc++);
        while(true) {
            string str;
            cin>>str;
            if(str[0]=='E') break;
            if(str[0]=='S') {
                LL pos,val;
                scanf("%lld%lld",&pos,&val);
                update(1,1,n,pos,val);
            }
            else if(str[0]=='M') {
                LL l,r;
                scanf("%lld%lld",&l,&r);
                LL ans=query(1,1,n,l,r);
                printf("%lld\n",ans);
            }
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
