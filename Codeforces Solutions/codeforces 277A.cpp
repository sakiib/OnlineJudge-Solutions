#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
bool visited[100005];

void dfs(int start) {
    visited[start]=true;
    for(auto x: graph[start]) {
        if(!visited[x]) {
            dfs(x);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,m;
    cin>>n>>m;
    int un=0;
    for(int i=1;i<=n;i++) {
        int l;
        cin>>l;
        if(l==0) un++;
        for(int j=1;j<=l;j++) {
            int lang;
            cin>>lang;
            graph[i].push_back(lang+1000);
            graph[lang+1000].push_back(i);
        }
    }
    if(un==n) {
        cout<<n<<endl;
        return 0;
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
