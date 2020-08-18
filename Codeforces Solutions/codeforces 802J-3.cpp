#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

LL ara[ N ];

struct segment {
    LL s,sq;
} tree[ 4*N ];

const LL m = 1000000007;

LL BigMod (LL a,LL p,LL m) {
    LL res=1%m,x=a%m;
     while(p) {
        if(p&1) res=(res*x)%m;
        x=(x*x)%m;
        p>>=1;
    }
    return res;
}
LL ModInv(LL val) {
    return BigMod(val,m-2,m);
}
void build(LL n,LL b,LL e) {
    if(b>e) return;
    if(b==e) {
        tree[n].s=ara[b]%m;
        tree[n].sq=(ara[b]%m*ara[b]%m)%m;
        return;
    }
    LL left=2*n; LL right=2*n+1; LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[n].s=(tree[left].s%m+tree[right].s%m)%m;
    tree[n].sq=(tree[left].sq%m+tree[right].sq%m)%m;
}
void update(LL n,LL b,LL e,LL pos,LL val) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) {
        tree[n].s=val%m;
        tree[n].sq=(val%m*val%m)%m;
        return;
    }
    LL left=2*n; LL right=2*n+1; LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);
    tree[n].s=(tree[left].s%m+tree[right].s%m)%m;
    tree[n].sq=(tree[left].sq%m+tree[right].sq%m)%m;
}
pair<LL,LL> query(LL n,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return {0,0};
    if(i<=b&&j>=e) {
        return {tree[n].s%m,tree[n].sq%m};
    }
    LL left=2*n; LL right=2*n+1; LL mid=(b+e)/2;
    pair<LL,LL> q1=query(left,b,mid,i,j);
    pair<LL,LL> q2=query(right,mid+1,e,i,j);
    pair<LL,LL> ret = {(q1.first%m+q2.first%m)%m,(q1.second%m+q2.second%m)%m};
    return ret;
}
int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&ara[i]);
    }
    build(1,1,n);
    LL q;
    scanf("%lld",&q);
    while(q--) {
        int op;
        scanf("%d",&op);
        if(op==1) {
            LL pos,val;
            scanf("%lld%lld",&pos,&val);
            update(1,1,n,pos,val);
        }
        else {
            LL l,r;
            scanf("%lld%lld",&l,&r);
            if(r<l) swap(l,r);
            pair<LL,LL> p = query(1,1,n,l,r);
            LL res = (p.first%m*p.first%m)%m-p.second;
            if(res < 0) res+=m;
            res = (res%m * ModInv(2)%m)%m;
            printf("%lld\n",res);
        }
    }
    return 0;
}
