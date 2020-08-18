#include<bits/stdc++.h>
using namespace std;

const int inf=10000000;
const int N=100005;
int tree[4*N];
int ara[N];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)>>1;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return inf;
    if(i<=b&&j>=e) return tree[node];
    int left=node<<1;
    int right=(node<<1)+1;
    int mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",tc);
        while(q--) {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
        memset(tree,0,sizeof(tree));
    }
    return 0;
}
