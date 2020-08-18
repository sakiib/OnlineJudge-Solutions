#include<bits/stdc++.h>
using namespace std;

map<string,vector<string> > M;
string f[1005],t[1005];
map<string,bool> visited;
vector<pair<string,string> > ans;

void dfs(string &start,string &origin) {
    visited[start]=true;
    if(M[start].size()==0) {
        ans.push_back({origin,start});
        return;
    }
    for(int i=0;i<M[start].size();i++) {
        string now=M[start][i];
        if(!visited[now]) {
            dfs(now,origin);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>f[i]>>t[i];
        M[f[i]].push_back(t[i]);
    }
    for(int i=1;i<=n;i++) {
        if(!visited[f[i]]) {
            dfs(f[i],f[i]);
        }
    }
    cout<<ans.size()<<endl;
    for(auto x: ans) {
        cout<<x.first<<" "<<x.second<<endl;
    }
    return 0;
}
