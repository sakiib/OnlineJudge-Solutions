#include<bits/stdc++.h>
using namespace std;

bool cycle;
bool visited[1000];
vector<int> graph[1000];

void dfs(int start,int parent) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            dfs(next,start);
        }
        else if(visited[next]&&next!=parent) {
            cycle=true;
            return;
        }
    }
}
int main(int argc,char const *argv[]) {
    graph[1].push_back(3);
    graph[3].push_back(1);
    graph[3].push_back(2);
    graph[2].push_back(3);
    cycle=false;
    for(int i=1;i<=3;i++) {
        if(!visited[i]) {
            dfs(i,-1);
            if(cycle) break;
        }
    }
    if(cycle) printf("Found Cycle\n");
    else printf("No Cycle\n");
    return 0;
}
