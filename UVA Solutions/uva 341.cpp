#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > graph[15];
map<int,int> path;
int dist[15];
const int inf=100000000;
vector<int> P;
int from,to;

void dijkstra(int from,int to) {
    for(int i=1;i<=15;i++) {
        dist[i]=inf;
    }
    dist[from]=0;
    priority_queue<int,vector<int>,greater<int> > Q;
    Q.push(from);
    while(!Q.empty()) {
        int top=Q.top();
        Q.pop();
        for(int i=0;i<graph[top].size();i++) {
            pair<int,int> p=graph[top][i];
            int cost=p.second;
            int next=p.first;
            if(dist[next]==inf||(dist[next]>dist[top]+cost)) {
                dist[next]=dist[top]+cost;
                Q.push(next);
                path[next]=top;
            }
        }
    }
}
void path_print(int to,int from) {
    if(to==from) {
        P.push_back(to);
        return;
    }
    path_print(path[to],from);
    P.push_back(to);
}
int main(int argc,char const *argv[]) {
    int n,tc=1;
    while(scanf("%d",&n)) {
        if(n==0) break;
        for(int i=1;i<=n;i++) {
            int k;
            scanf("%d",&k);
            for(int j=1;j<=k;j++) {
                int x,d;
                scanf("%d%d",&x,&d);
                graph[i].push_back({x,d});
            }
        }
        scanf("%d%d",&from,&to);
        dijkstra(from,to);
        path_print(to,from);
        printf("Case %d: Path = ",tc++);
        for(int i=0;i<P.size();i++) {
            if(i==0) printf("%d",P[i]);
            else printf(" %d",P[i]);
        }
        printf("; ");
        printf("%d second delay\n",dist[to]);
        path.clear();
        for(int i=1;i<=14;i++) graph[i].clear();
        P.clear();
    }
    return 0;
}
