#include<bits/stdc++.h>
using namespace std;

bool yes;

void dfs(int start,int colour,int *visited,vector<int> *graph) {
    if(visited[start]!=0) {
        if(visited[start]!=colour) {yes=false; return;}
    }
    else {visited[start]=colour;
    for(int i=0;i<graph[start].size();i++) {
        int colour2;
        if(colour==1) colour2=2;
        else colour2=1;
        dfs(graph[start][i],colour2,visited,graph);
     }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    while(scanf("%d",&n)&&n!=0) {
        int e;
        cin>>e;
        int visited[100010];
        vector<int> graph[100010];
        while(e--) {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        memset(visited,0,sizeof(visited));
        yes=true;
        dfs(0,1,visited,graph);
        if(yes) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }
    return 0;
}
