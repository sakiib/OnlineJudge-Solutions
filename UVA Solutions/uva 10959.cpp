#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
int visited[100010];

void bfs(int start) {
    queue<int> Q;
    Q.push(start);
    visited[start]=0;
    while(!Q.empty()) {
        int frnt=Q.front();
        Q.pop();
        for(int i=0;i<graph[frnt].size();i++) {
            if(visited[graph[frnt][i]]==-1) {
                visited[graph[frnt][i]]=visited[frnt]+1;
                Q.push(graph[frnt][i]);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    bool blank=false;
    while(t--) {
        int p,d;
        cin>>p>>d;
        for(int i=1;i<=d;i++) {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(visited,-1,sizeof(visited));
        bfs(0);
        for(int i=1;i<=p-1;i++) {
            cout<<visited[i]<<endl;
        }
        if(t!=0) printf("\n");
        for(int i=0;i<=100010;i++) graph[i].clear();
    }
    return 0;
}
