#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
vector<int> V;
bool visited[100005];
int ans = 0;

void dfs(int st,int k) {
    visited[st]=true;
    ans=max(ans,k);
    for(auto x: graph[st]) {
        if(!visited[x]) {
            dfs(x,k+1);
        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin>> val;
        if(val!=-1) graph[val].push_back(i);
        else V.push_back(i);
    }
    int s=(int)V.size();
    for(int i=0;i<s;i++) {
        dfs(V[i],1);
    }
    cout << ans << endl;
    return 0;
}
