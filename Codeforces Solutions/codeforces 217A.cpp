#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> p[1000];
bool visited[1000];

void dfs(int start) {
    visited[start]=true;
    for(int i=1;i<=n;i++) {
        if(p[i].first==p[start].first||p[i].second==p[start].second) {
            if(!visited[i]) dfs(i);
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        if(!visited[i]) {
            ans++;
            dfs(i);
        }
    }
    cout<<ans-1<<endl;
    return 0;
}
