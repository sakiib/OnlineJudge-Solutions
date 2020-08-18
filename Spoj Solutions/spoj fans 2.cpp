#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N=1000005;

LL tree[4*N];

void update(LL n,LL b,LL e,LL pos,LL val) {
    if(pos<b||pos>e) return;
    if(b==e&&b==pos) {
        tree[n]+=val;
        return;
    }
    LL left=2*n; LL right=2*n+1; LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[n]=tree[left]+tree[right];
}
LL query(LL n,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[n];
    LL left=2*n; LL right=2*n+1; LL mid=(b+e)/2;
    LL q1=query(left,b,mid,i,j);
    LL q2=query(right,mid+1,e,i,j);
    return q1+q2;
}
int main(int argc,char const *argv[]) {
    LL n,q;
    scanf("%lld%lld",&n,&q);
    memset(tree,0,sizeof(tree));
    for(int i=1;i<=q;i++) {
        char str[100];
        LL l,r;
        scanf("%s %lld%lld",str,&l,&r);
        if(strcmp(str,"add")==0) update(1,1,n,l,r);
        else printf("%lld\n",query(1,1,n,l,r));
    }
    return 0;
}
