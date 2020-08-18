#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;

int parent[1005];

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    if(parent[x]==x) return x;
    return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
int mst_kruskal() {
    int ret=0;
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
       int u=V[i].u; int v=V[i].v; int w=V[i].w;
       if(Find(u)!=Find(v)) {
        Union(u,v);
        ret+=w;
       }
    } return ret;
}
int main(int argc,char const *argv[]){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int taka; scanf("%d",&taka);
        int n; scanf("%d",&n);
        makeset(n);
        int e; scanf("%d",&e);
        for(int i=1;i<=e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            V.push_back({u,v,w});
        }
        int tot=mst_kruskal();
        printf("%d\n",(tot*taka));
        V.clear();
    }
    return 0;
}
