#include<bits/stdc++.h>
using namespace std;

set<string> S;
map<string,vector<string> > graph;
map<string,int> visited;
map<string,bool> done;
int mx=0;

string fix(string &str) {
    for(int i=0;i<str.size();i++) {
        if(str[i]>='A'&&str[i]<='Z') str[i]-='A',str[i]+='a';
    } return str;
}
void dfs(string &start) {
    done[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        if(!done[graph[start][i]]) {
            visited[graph[start][i]]=visited[start]+1;
            dfs(graph[start][i]);
        }
    }
    //cerr<<"st : "<<start<<endl;
    mx=max(mx,visited[start]+1);
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        string a,b,c;
        cin>>a>>b>>c;
        string x=fix(a);
        string y=fix(c);
        visited[x]=0,visited[y]=0;
        S.insert(x);
        S.insert(y);
        //cout<<x<<" "<<y<<endl;
        //graph[x].push_back(y);
        graph[y].push_back(x);
    }
    //for(auto x:S) cout<<x<<endl;
    string st="polycarp";
    dfs(st);
    cout<<mx<<endl;
    return 0;
}
