#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
#define pii pair<int,int>
int parent[20005];

struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};

bool visited[20005];
int dist[20005];
vector<data> V;
vector<pii> graph[20005];
int n,e;

void makeset(int n) {
    for(int i=0;i<n;i++) {
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
void mst(int n) {
    sort(V.begin(),V.end());
    int cnt=0;
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            cnt++;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
            Union(u,v);
        }
        if(cnt==n-1) break;
    }
}
void dfs(int st) {
    visited[st]=true;

    for(int i=0;i<graph[st].size();i++) {
        pii next=graph[st][i];
        if(!visited[next.first]) {
            dist[next.first]=max(dist[st],next.second);
            dfs(next.first);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        scanf("%d%d",&n,&e);
        makeset(n);
        for(int i=1;i<=e;i++) {
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            V.push_back({u,v,c});
        }
        mst(n);
        int st;
        scanf("%d",&st);
        memset(visited,false,sizeof(visited));
        memset(dist,-1,sizeof(dist));
        dist[st]=0;
        dfs(st);
        printf("Case %d:\n",tc);
        for(int i=0;i<n;i++) {
            if(dist[i]==-1) printf("Impossible\n");
            else printf("%d\n",dist[i]);
        }
        for(int i=0;i<20004;i++) graph[i].clear();
        V.clear();

    }
    return 0;
}
