#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const int inf=1000000000;

int ara[N];

struct segment {
    int mx,mn;
} tree[4*N];

void build(int node,int b,int e) {
    if(b>e) return;
    if(b==e) {
        tree[node].mx=tree[node].mn=ara[b];
        return;
    }
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].mx=max(tree[left].mx,tree[right].mx);
    tree[node].mn=min(tree[left].mn,tree[right].mn);
}
int query1(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 0;
    if(i<=b&&j>=e) return tree[node].mx;
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int q1=query1(left,b,mid,i,j);
    int q2=query1(right,mid+1,e,i,j);
    return max(q1,q2);
}
int query2(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return inf;
    if(i<=b&&j>=e) return tree[node].mn;
    int left=2*node; int right=2*node+1; int mid=(b+e)/2;
    int q1=query2(left,b,mid,i,j);
    int q2=query2(right,mid+1,e,i,j);
    return min(q1,q2);
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        int lo=1, hi=k;
        int res=-inf;
        while(hi<=n) {
            int rmx=query1(1,1,n,lo,hi);
            int rmn=query2(1,1,n,lo,hi);
            res=max(res,abs(rmx-rmn));
            lo++, hi++;
        }
        printf("Case %d: %d\n",tc,res);
    }
    return 0;
}
