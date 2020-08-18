#include<bits/stdc++.h>
using namespace std;

map<string,vector<string> > graph;
map<string,bool> visited;
map<string,string> path;

void BFS(string &st,string &en) {
    queue<string> Q;
    visited[st]=false;
    Q.push(st);
    while(!Q.empty()) {
        string frnt=Q.front();
        if(frnt==en) return;
        Q.pop();
        for(int i=0;i<graph[frnt].size();i++) {
            if(!visited[graph[frnt][i]]) {
                Q.push(graph[frnt][i]);
                path[graph[frnt][i]]=frnt;
                visited[graph[frnt][i]]=true;
            }
        }
    }
}
void print_path(string &en,string &st) {
    if(st==en) {
     printf("%c",st[0]);
     return;
    }
    print_path(path[en],st);
    printf("%c",en[0]);
    return;
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    bool f=false;
    while(t--)  {
        int n,q;
        scanf("%d%d",&n,&q);
        if(f) printf("\n");
        f=true;
        graph.clear();
        while(n--) {
            string a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        while(q--) {
            string st,en;
            cin>>st>>en;
            visited.clear();
            path.clear();
            BFS(st,en);
            print_path(en,st);
            printf("\n");
        }
    }
    return 0;
}
