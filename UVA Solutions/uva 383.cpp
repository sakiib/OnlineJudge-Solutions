#include<bits/stdc++.h>
using namespace std;

map<string,vector<string> > graph;
map<string,int> visited;

void bfs(string &st) {
    queue<string> Q;
    Q.push(st);
    visited[st]=0;
    while(!Q.empty()) {
        string frnt=Q.front();
        Q.pop();
        for(int i=0;i<graph[frnt].size();i++) {
            if(visited[graph[frnt][i]]==-1) {
                visited[graph[frnt][i]]=visited[frnt]+1;
                Q.push(graph[frnt][i]);
            }
        }
    }
}
int main(int argc,char const *argv) {
    int t,tc;
    cin>>t;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl;
    for(tc=1;tc<=t;tc++) {
        int n,e,q;
        cin>>n>>e>>q;
        vector<string> V;
        while(n--) {
            string str;
            cin>>str;
            V.push_back(str);
        }
        while(e--) {
            string a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout<<endl<<"DATA SET  "<<tc<<endl<<endl;
        while(q--) {
            int taka;
            string st,en;
            cin>>taka;
            cin>>st>>en;
            for(int i=0;i<V.size();i++) visited[V[i]]=-1;
            bfs(st);
            if(visited[en]>0) {
                cout<<"$"<<100*taka*visited[en]<<endl;
            }
            else {
                cout<<"NO SHIPMENT POSSIBLE"<<endl;
            }
        }
        graph.clear();
        visited.clear();
    }
    cout<<endl<<"END OF OUTPUT"<<endl;
    return 0;
}
