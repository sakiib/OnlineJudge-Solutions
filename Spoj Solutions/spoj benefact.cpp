#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

vector<pii> V[100005];
bool visited[100005];
int dist[100005];
int now,mx=0;

void dfs(int start) {
    visited[start]=true;
    for(int i=0;i<V[start].size();i++) {
        pair<int,int> p=V[start][i];
        if(!visited[p.first]) {
           dist[p.first]=dist[start]+p.second;
           if(dist[p.first]>mx) {
            mx=dist[p.first];
            now=p.first;
           }
           dfs(p.first);
        }
    }
}
int dfs2(int start) {
    visited[start]=true;

    for(int i=0;i<V[start].size();i++) {
        pair<int,int> p=V[start][i];
        if(!visited[p.first]) {
            dist[p.first]=dist[start]+p.second;
            mx=max(mx,dist[p.first]);
            dfs2(p.first);
        }
    }
    return mx;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int e;
        scanf("%d",&e);
        for(int i=1;i<e;i++) {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            V[u].push_back({v,w});
            V[v].push_back({u,w});
        }
        now=0,mx=0;
        memset(dist,0,sizeof(dist));
        memset(visited,false,sizeof(visited));
        dfs(1);
        //printf("Now : %d\n",now);
        memset(visited,false,sizeof(visited));
        memset(dist,0,sizeof(dist));
        int ans=dfs2(now);
        //cout<<dist[1]<<" "<<dist[2]<<" "<<dist[3]<<" "<<dist[4]<<" "<<dist[6]<<endl;
        printf("%d\n",ans);
        for(int i=1;i<=100004;i++) V[i].clear();
    }
    return 0;
}
