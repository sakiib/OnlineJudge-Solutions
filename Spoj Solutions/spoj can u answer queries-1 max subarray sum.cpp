#include<bits/stdc++.h>
using namespace std;

const int N=50005;
int ara[N];

struct segment {
    int lmax,rmax,tot,mx;
    segment(){}
    segment (int _lmax,int _rmax,int _tot,int _mx) {
        lmax=_lmax; rmax=_rmax; tot=_tot; mx=_mx;
    }
} tree[4*N];

void build_segment_tree(int node,int b,int e) {
    if(b==e) {
        tree[node].tot=ara[b];
        tree[node].lmax=tree[node].rmax=tree[node].mx=tree[node].tot;
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build_segment_tree(left,b,mid); build_segment_tree(right,mid+1,e);
    tree[node].tot=tree[left].tot+tree[right].tot;
    tree[node].lmax=max(tree[left].lmax,max(tree[left].tot,tree[left].tot+tree[right].lmax);
    tree[node].rmax=
}
int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
    }
    build_segment_tree(1,1,n);
    return 0;
}
