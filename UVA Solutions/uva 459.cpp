#include<bits/stdc++.h>
using namespace std;

vector<int> V[10010];
map<int,bool> visited;

void dfs(int st) {
    visited[st]=true;
    for(int i=0;i<V[st].size();i++) {
        if(!visited[V[st][i]]) {
        visited[V[st][i]]=true;
        dfs(V[st][i]);
        }
    }
    return;
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    scanf("\n");
    while(t--) {
        visited.clear();
        string s;
        cin>>s;
        int n=s[0]-'A';
        for(char i=0;i<=n;i++) V[i].clear();
        string str;
        cin.ignore();
        while(getline(cin,str)&&str[0]) {
            V[str[0]-'A'].push_back(str[1]-'A');
            V[str[1]-'A'].push_back(str[0]-'A');
        }
        int cnt=0;
        for(char i=0;i<=n;i++) {
            if(!visited[i]) {
                dfs(i);
                cnt++;
            }
        }
        cout<<cnt<<endl;
        if(t!=0) cout<<endl;
    }
    return 0;
}

