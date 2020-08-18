#include<bits/stdc++.h>
using namespace std;

map<string,int> visited;//I can also count the number of moves
map<string,vector<string> > graph;
map<string,string> path;//For keeping the track of path

int BFS(string &st,string &en) {
    queue<string> Q;
    Q.push(st);
    visited[st]=0;
    while(!Q.empty()) {
        string frnt=Q.front();
        Q.pop();
        if(frnt==en) return visited[frnt];
        for(int i=0;i<graph[frnt].size();i++) {
            if(visited[graph[frnt][i]]==-1) {// age aschi kina? na ashle dhukbo
                //cerr<<graph[frnt][i]<<endl;
                visited[graph[frnt][i]]=visited[frnt]+1;//number of moves
                path[graph[frnt][i]]=frnt;//the parent of graph[frnt][i] is frnt//Path
                Q.push(graph[frnt][i]);
            }
        }
    }
    return -1;
}
void print_path(string st,string en) {
    if(st==en) return;
    print_path(path[st],en);
    cout<<path[st]<< " " <<st<<endl;
}
int main(int argc,char const *argv[]) {
    int n;
    bool done=false;
    while(scanf("%d",&n)!=EOF) {
        graph.clear();
        visited.clear();
        path.clear();
        while(n--) {
        string from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
        visited[from]=-1;
        visited[to]=-1;
        }
        string st,en;
        cin>>st>>en;
        int k=0;
        k=BFS(st,en);
        //cerr<<"K : "<<k<<endl;
        if(done) printf("\n");
        done=true;
        if(k!=-1) print_path(en,st);
        else cout<<"No route"<<endl;
    }
    return 0;
}
