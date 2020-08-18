#include<bits/stdc++.h>
using namespace std;

int sum[200005];
int parent[200005];

void makeset(int n) {
    for(int i=1;i<=n+1000;i++) {
        sum[i]=1;
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
    if(u!=v) {
        parent[u]=v;
        sum[v]+=sum[u];
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        int id=1;
        map<string,int> M;
        makeset(n);
        for(int i=1;i<=n;i++) {
            string a,b;
            cin>>a>>b;
            if(!M[a]) M[a]=id++;
            if(!M[b]) M[b]=id++;
            Union(M[a],M[b]);
            printf("%d\n",sum[Find(M[b])]);
        }
    }
    return 0;
}
