#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;
int parent[1000005];

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    return parent[x]==x ? x : parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
int MST() {
    int ans=0;
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        int u=V[i].u;
        int v=V[i].v;
        int w=V[i].w;
        if(Find(u)!=Find(v)) {
            ans+=w;
            Union(u,v);
        }
    }
    return ans;
}
int main(int argc,char const *argv[]) {
    int n;
    bool flag=false;
    while(scanf("%d",&n)!=EOF) {
        int f=0;
        if(flag) printf("\n");
        flag=true;
        makeset(n);
        for(int i=1;i<n;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            f+=c;
        }
        printf("%d\n",f);
        int k;
        scanf("%d",&k);
        int a,b,c;
        for(int i=1;i<=k;i++) {
            scanf("%d%d%d",&a,&b,&c);
            V.push_back({a,b,c});
        }
        int m;
        scanf("%d",&m);
        for(int i=1;i<=m;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            V.push_back({a,b,c});
        }
        printf("%d\n",MST()); V.clear();
    }
    return 0;
}
