#include<bits/stdc++.h>
using namespace std;

int ara[100010];
bool visited[100010];
vector<int> graph[100010];
int pos,tot;

pair<int,int> dfs(int start) {
    bool found=false;
    int mx=0;
    //cerr<<tot<<endl;
    for(int i=0;i<graph[start].size();i++) {
        if(ara[graph[start][i]]>mx) {
            visited[graph[start][i]]=true;
            mx=ara[graph[start][i]];
            pos=graph[start][i];
            found=true;
        }
    }
    if(!found) { return {tot,pos}; }
    tot+=mx;
    dfs(pos);
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
        memset(visited,false,sizeof(visited));
        for(int i=0;i<=1010;i++) {
            graph[i].clear();
        }
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++) {
            cin>>ara[i];
        }
        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
        }
        pos=0,tot=0;
        pair<int,int> p=dfs(0);
        cout<<"Case "<<tc<<": "<<p.first<< " " <<p.second<<endl;
    }
    return 0;
}
