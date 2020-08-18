#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100];


void bfs(int from,int to) {
    queue<int> Q;
    int visited[1000]={0},level[1000];
    Q.push(from);
    visited[from]=1;
    level[from]=0;
    while(!Q.empty()) {
        int frnt=Q.front();
        Q.pop();
        for(int i=0;i<graph[frnt].size();i++) {
            if(!visited[graph[frnt][i]]) {
                visited[graph[frnt][i]]=1;
                level[graph[frnt][i]]=level[frnt]+1;
                Q.push(graph[frnt][i]);
            }
        }
    }
    printf("%2d to %2d: %d\n",from,to,level[to]);
}
int main(int argc,char const *argv[]) {
    int a;
    int tc=1;
    while(scanf("%d",&a)!=EOF) {
        while(a--) {
            int b;
            cin>>b;
            graph[1].push_back(b);
            graph[b].push_back(1);
        }
        for(int i=2;i<=19;i++) {
            int k;
            cin>>k;
            while(k--) {
              int b;
              cin>>b;
              graph[i].push_back(b);
              graph[b].push_back(i);
            }
        }
        int q;
        cin>>q;
        printf("Test Set #%d\n",tc);
        while(q--) {
            int from,to;
            cin>>from>>to;
            bfs(from,to);
            //printf("%d to %d: %d\n",from,to,visited[to]);
        }
        printf("\n");
        for(int i=0;i<=20;i++) graph[i].clear();
        tc++;
    }
    return 0;
}
