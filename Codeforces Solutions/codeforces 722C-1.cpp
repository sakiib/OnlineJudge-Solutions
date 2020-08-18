#include<bits/stdc++.h>
using namespace std;

const int N=100005;
typedef long long LL;
const LL inf=2e14;
LL a[N];

struct segment {
    LL sum,max_suf,max_pref,ans;

    segment(){sum=0; max_suf=0; max_pref=0; ans=0;}

    segment(LL sum,LL max_suf,LL max_pref,LL ans) {
        this->sum=sum;
        this->max_pref=max_pref;
        this->max_suf=max_suf;
        this->ans=ans;
    }
}tree[4*N];

void build(LL node,LL b,LL e) {
    if(b>e) return;
    if(b==e) {
        tree[node].sum=a[b];
        tree[node].max_suf=a[b];
        tree[node].max_pref=a[b];
        tree[node].ans=a[b];
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].max_pref=max(tree[left].max_pref,tree[left].sum+tree[right].max_pref);
    tree[node].max_suf=max(tree[right].max_suf,tree[right].sum+tree[left].max_suf);

    tree[node].ans=max(tree[left].ans,tree[right].ans);
    tree[node].ans=max(tree[node].ans,tree[left].max_suf+tree[right].max_pref);
}
void update(LL node,LL b,LL e,LL pos,LL val) {
    if(pos>e||pos<b) return;
    if(b==e&&b==pos) {
        tree[node].sum=val;
        tree[node].max_pref=val;
        tree[node].max_suf=val;
        tree[node].ans=val;
        return;
    }
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    update(left,b,mid,pos,val);
    update(right,mid+1,e,pos,val);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].max_pref=max(tree[left].max_pref,tree[left].sum+tree[right].max_pref);
    tree[node].max_suf=max(tree[right].max_suf,tree[right].sum+tree[left].max_suf);

    tree[node].ans=max(tree[left].ans,tree[right].ans);
    tree[node].ans=max(tree[node].ans,tree[left].max_suf+tree[right].max_pref);
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    //printf("%lld %lld %lld %lld\n",tree[1].max_suf,tree[1].max_pref,tree[1].sum,tree[1].ans);
    for(int i=1;i<=n;i++) {
        LL pos;
        scanf("%lld",&pos);
        update(1,1,n,pos,-inf);
        if(tree[1].ans==-inf) printf("0\n");
        else printf("%lld\n",tree[1].ans);
    }
    return 0;
}
