#include<bits/stdc++.h>
using namespace std;

int parent[100005];
int sum[100005];
int mx;
void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
        sum[i]=1;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) {
        parent[u]=v;
        sum[v]+=sum[u];
        mx=max(mx,sum[v]);
    }
}
int main(int argc,char const *argv[]) {
    int t; scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n,k; scanf("%d%d",&n,&k);
        makeset(n);
        mx=1;
        for(int i=1;i<=k;i++) {
            int a,b; scanf("%d%d",&a,&b);
            Union(a,b);
        }
        printf("%d\n",mx);
    }
    return 0;
}
