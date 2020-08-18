#include<bits/stdc++.h>
using namespace std;

const int N=100010;

int cat[N];
int n,m;

vector<int> graph[N];
bool visited[N];
int ans;

void bfs() {
    ans=0;
    queue<pair<int,int> > Q;
    Q.push({1,cat[1]});
    visited[1]=true;
    while(!Q.empty()) {
        pair<int,int> T=Q.front();
        int s=T.first;
        int c=T.second;
        Q.pop();
        if(c>m) continue;
        if(graph[s].size()==1&&s!=1) {ans++; continue;}
        for(int i=0;i<graph[s].size();i++) {
            if(!visited[graph[s][i]]) {

                if(cat[graph[s][i]]==1) {
                    Q.push({graph[s][i],c+1});
                }
                else Q.push({graph[s][i],0});
                visited[graph[s][i]]=true;
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>cat[i];
    }
    for(int i=1;i<n;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs();
    cout<<ans<<endl;
    return 0;
}
