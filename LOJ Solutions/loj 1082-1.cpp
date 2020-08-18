#include<bits/stdc++.h>
using namespace std;

int ara[100005];
int tree[4*100005];

void build(int node,int b,int e) {
    if(b==e) {
        tree[node]=ara[b];
        return;
    }
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int i,int j) {
    if(i>e||j<b) return 100000000;
    if(b>=i&&e<=j) return tree[node];
    int left=2*node;
    int right=2*node+1;
    int mid=(b+e)/2;
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
        for(int j=1;j<=q;j++) {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
