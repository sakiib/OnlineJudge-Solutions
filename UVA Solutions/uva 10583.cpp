#include<bits/stdc++.h>
using namespace std;

int parent[100005];
void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
int main(int argc,char const *argv[]) {
    int n,k,tc=1;
    while(scanf("%d%d",&n,&k)) {
        if(n==0&&k==0) break;
        makeset(n);
        int ans=n;
        while(k--) {
            int a,b;
            scanf("%d%d",&a,&b);
            if(Find(a)!=Find(b)) {
                ans--;
                Union(a,b);
            }
        }
        printf("Case %d: %d\n",tc++,ans);
    }
    return 0;
}
