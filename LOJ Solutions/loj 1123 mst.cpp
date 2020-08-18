#include<bits/stdc++.h>
using namespace std;

struct data {
    int u,v,w,idx;
    bool operator<(const data &q)const {
        return w<q.w;
    }
};
int parent[100005];
vector<data> V;
int n,e;

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
int MST(int index) {
    makeset(n);
    int ret=0;
    int cnt=0;
    for(int i=0;i<V.size();i++) {
        if(cnt==(n-1)) break;
        if(V[i].idx>index) continue;
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            ret+=w;
            cnt++;
        }
    }
    if(cnt==(n-1)) return ret;
    else return -1;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&e);
        int idx=0;
        printf("Case %d:\n",tc);
        for(int i=1;i<=e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            V.push_back({u,v,w,i});
        }
        sort(V.begin(),V.end());
        for(int i=1;i<=e;i++) {
            printf("%d\n",MST(i));
        }
        V.clear();
    }
    return 0;
}
