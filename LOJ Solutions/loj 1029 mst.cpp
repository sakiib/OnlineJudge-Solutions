#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;
int parent[100005];

void makeset(int n) {
    for(int i=0;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
int mst(int n) {
    sort(V.begin(),V.end());
    int ret=0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            ret+=w;
            Union(u,v);
        }
    }
    makeset(n);
    for(int i=V.size()-1;i>=0;i--) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            ret+=w;
            Union(u,v);
        }
    }
    return ret;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        makeset(n);
        int u,v,w;
        while(scanf("%d%d%d",&u,&v,&w)) {
            if(u==0&&v==0&&w==0) break;
            V.push_back({u,v,w});
        }
        int cost=mst(n);
        if(cost&1) printf("Case %d: %d/2\n",tc,cost);
        else printf("Case %d: %d\n",tc,cost/2);
        V.clear();
    }
    return 0;
}
