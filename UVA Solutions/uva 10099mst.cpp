#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
const int inf=100000000;
struct data {
    int u,v,w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
vector<data> V;
vector<pii> graph[100005];
int parent[100005];
bool visited[100005];
int dist[100005];

void makeset(int n) {
    for(int i=1;i<=n;i++) {
        parent[i]=i;
    }
}
int Find(int x) {
    return parent[x]==x? x : parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a);
    int v=Find(b);
    if(u!=v) parent[u]=v;
}
int MST() {
    sort(V.begin(),V.end());
    for(int i=V.size()-1;i>=0;i--) {
        int u=V[i].u; int v=V[i].v; int w=V[i].w;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
    }
}
void dfs(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        pii next=graph[start][i];
        if(!visited[next.first]) {
            dist[next.first]=min(next.second,dist[start]);
            dfs(next.first);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,e,tc=1;
    while(scanf("%d%d",&n,&e)) {
        if(n==0&&e==0) break;
        makeset(n);
        for(int i=1;i<=e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            V.push_back({u,v,--w});
        }
        int st,en,tot;
        scanf("%d%d%d",&st,&en,&tot);
        MST();
        for(int i=1;i<=100004;i++) dist[i]=inf;
        dfs(st);
        printf("Scenario #%d\n",tc++);
        int mn=dist[en];
        int ans=(tot/mn);
        if(tot%mn!=0) ans++;
        printf("Minimum Number of Trips = %d\n",ans);

        printf("\n");

        V.clear();
        for(int i=1;i<=100004;i++) graph[i].clear();
        memset(visited,false,sizeof(visited));

    }
    return 0;
}
