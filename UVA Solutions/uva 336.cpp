#include<bits/stdc++.h>
using namespace std;

map<int,int> visited;

void bfs(int start,map<int,vector<int> >graph) {
    queue<int> Q;
    Q.push(start);
    visited[start]=0;
    while(!Q.empty()) {
        int frnt=Q.front();
        Q.pop();
        for(int i=0;i<graph[frnt].size();i++) {
            int k=graph[frnt][i];
            if(!visited.count(k)) {
                visited[graph[frnt][i]]=visited[frnt]+1;
                Q.push(graph[frnt][i]);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,tc=1;
    while(scanf("%d",&n)&&(n!=0)) {
        map<int,vector<int> > graph;
        while(n--) {
            int a,b;
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int ttl,start;
        while(scanf("%d %d",&start,&ttl)&&(start!=0||ttl!=0)) {
            visited.clear();
            bfs(start,graph);
            int res=0;
            for(auto x:visited) {
                if(x.second>ttl) res++;
            }
            res+=(graph.size()-visited.size());
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",tc,res,start,ttl);
            tc++;
        }
    }
    return 0;
}
