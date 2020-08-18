#include<bits/stdc++.h>
using namespace std;

const int N=100005;
const int INF=100000000;
int ara[N];
int tree[4*N];

int Query(int Node,int b,int e,int i,int j) {
    if(i>e||j<b) return INF;
    if(b>=i&&e<=j) return tree[Node];
    int Left=2*Node;
    int Right=2*Node+1;
    int mid=(b+e)/2;
    int p1=Query(Left,b,mid,i,j);
    int p2=Query(Right,mid+1,e,i,j);
    return min(p1,p2);
}
void BuildSegmentTree(int Node,int b,int e) {
    if(b==e) {
        tree[Node]=ara[b];
        return;
    }
    int Left=2*Node;
    int Right=2*Node+1;
    int mid=(b+e)/2;
    BuildSegmentTree(Left,b,mid);
    BuildSegmentTree(Right,mid+1,e);
    tree[Node]=min(tree[Left],tree[Right]);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n,query;
        scanf("%d%d",&n,&query);
        for(int i=1;i<=n;i++) {
            scanf("%d",&ara[i]);
        }
        BuildSegmentTree(1,1,n);
        printf("Case %d:\n",tc);
        while(query--) {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=Query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
