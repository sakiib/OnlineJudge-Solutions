#include<bits/stdc++.h>
using namespace std;

const int N = 50005;
typedef long long LL;
const int inf = 100005;
int a[ N ];

struct segment {
    int sum,max_suf,max_pref,ans;

    segment(){sum=-inf; max_suf=-inf; max_pref=-inf; ans=-inf;}

    segment(int sum,int max_suf,int max_pref,int ans) {
        this->sum=sum;
        this->max_pref=max_pref;
        this->max_suf=max_suf;
        this->ans=ans;
    }
}tree[4*N];

void build(int node,int b,int e) {
    if(b>e) return;
    if(b==e) {
        tree[node].sum=a[b];
        tree[node].max_suf=a[b];
        tree[node].max_pref=a[b];
        tree[node].ans=a[b];
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
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
segment query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return {-inf,-inf,-inf,-inf};
    if(i<=b&&j>=e) return tree[node];
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    segment s1=query(left,b,mid,i,j);
    segment s2=query(right,mid+1,e,i,j);
    segment ret;
    ret.sum=s1.sum+s2.sum;
    ret.max_pref=max(s1.max_pref,s1.sum+s2.max_pref);
    ret.max_suf=max(s2.max_suf,s2.sum+s1.max_suf);
    ret.ans=max(s1.ans,s2.ans);
    ret.ans=max(ret.ans,s1.max_suf+s2.max_pref);
    return ret;
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    build(1,1,n);
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++) {
        int op;
        int l,r;
        scanf("%d%d%d",&op,&l,&r);
        if( op == 0 ) {
            update( 1 , 1 , n , l , r );
        }
        else {
            segment S=query( 1 , 1 , n , l , r );
            printf("%d\n",S.ans);
        }
    }
    return 0;
}

