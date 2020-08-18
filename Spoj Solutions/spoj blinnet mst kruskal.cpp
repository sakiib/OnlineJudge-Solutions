#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return w<q.w;
    }
};
vector<data> V;
int parent[10005];

void makeset(int val) {
    for(int i=1;i<=val;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    return parent[x]==x ? x : parent[x]=Find(parent[x]);
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
            ret+=w;
            Union(u,v);
        }
    } return ret;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int city;
        scanf("%d",&city);
        makeset(city);
        for(int i=1;i<=city;i++) {
            char str[100];
            scanf("%s",str);
            int n;
            scanf("%d",&n);
            while(n--) {
                int v,c;
                scanf("%d%d",&v,&c);
                V.push_back({i,v,c});
            }
        }
        printf("%d\n",mst_kruskal());
        V.clear();
    }
    return 0;
}
