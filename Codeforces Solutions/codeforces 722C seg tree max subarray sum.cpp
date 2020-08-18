/*
 Similar problem : Spoj gss1(maximum sum sub-array)
 Data structure : Segment Tree
 Alternate Solution: Disjoint Set Union
 Query part is not essential for this problem.
*/
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
segment query(LL node,LL b,LL e,LL i,LL j) {
    if(i>e||j<b) return {-inf,-inf,-inf,-inf};
    if(i<=b&&j>=e) return tree[node];
    LL left=2*node; LL right=2*node+1; LL mid=(b+e)/2;
    segment s1=query(left,b,mid,i,j);
    segment s2=query(right,mid+1,e,i,j);
    segment ret;
    ret.sum=s1.sum+s2.sum;
    ret.max_pref=max(s1.max_pref,s1.sum+s2.max_pref);
    ret.max_suf=max(s2.max_suf,s2.sum+s2.max_suf);
    ret.ans=max(s1.ans,s2.ans);
    ret.ans=max(ret.ans,s1.max_suf+s2.max_pref);
    return ret;
}
int main(int argc,char const *argv[]) {
    LL n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    //printf("%lld %lld %lld %lld\n",tree[1].max_suf,tree[1].max_pref,tree[1].sum,tree[1].ans);
    //segment S=query(1,1,n,1,n);
    //printf("%lld %lld %lld %lld\n",S.max_suf,S.max_pref,S.sum,S.ans);
    for(int i=1;i<=n;i++) {
        LL pos;
        scanf("%lld",&pos);
        update(1,1,n,pos,-inf);
        segment S=query(1,1,n,1,n);
        if(S.ans==-inf) printf("0\n");
        else printf("%lld\n",S.ans);
    }
    return 0;
}
