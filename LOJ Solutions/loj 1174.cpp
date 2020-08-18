#include<bits/stdc++.h>
using namespace std;

const int INF=100000;
vector<int> graph[105];
int dist1[105];
int dist2[105];

void bfs1(int s) {
    queue<int> Q;
    Q.push(s);
    dist1[s]=0;
    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        for(int i=0;i<graph[f].size();i++) {
            if(dist1[graph[f][i]]>dist1[f]+1) {
                dist1[graph[f][i]]=dist1[f]+1;
                Q.push(graph[f][i]);
            }
        }
    }
}
void bfs2(int d) {
    queue<int> Q;
    Q.push(d);
    dist2[d]=0;
    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        for(int i=0;i<graph[f].size();i++) {
            if(dist2[graph[f][i]]>dist2[f]+1) {
                dist2[graph[f][i]]=dist2[f]+1;
                Q.push(graph[f][i]);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        for(int i=0;i<105;i++) {
            dist1[i]=INF;
            dist2[i]=INF;
        }
        for(int i=0;i<105;i++) graph[i].clear();
        int n;
        scanf("%d",&n);
        int edge;
        scanf("%d",&edge);
        for(int i=1;i<=edge;i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        int s,d;
        scanf("%d%d",&s,&d);
        bfs1(s);
        bfs2(d);
        int mx=0;
        for(int i=0;i<n;i++) {
            mx=max(mx,dist1[i]+dist2[i]);
        }
        printf("Case %d: %d\n",tc,mx);
    }
    return 0;
}
