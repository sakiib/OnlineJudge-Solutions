#include<bits/stdc++.h>
using namespace std;

vector<int> V[10];
char ans[100];
bool visited[100][100];

void dfs(int start,int cur) {
    if(cur==9) {
        puts(ans);
        return;
    }
    for(int i=0;i<V[start].size();i++) {
        if(!visited[start][V[start][i]]) {
            ans[cur]=(V[start][i]+'0');
            visited[start][V[start][i]]=true;
            visited[V[start][i]][start]=true;
            dfs(V[start][i],cur+1);
            visited[start][V[start][i]]=false;
            visited[V[start][i]][start]=false;
        }
    }
}
int main(int argc,char const *argv[]) {
    V[1].push_back(2); V[1].push_back(3); V[1].push_back(5);
    V[2].push_back(1); V[2].push_back(3); V[2].push_back(5);
    V[3].push_back(1); V[3].push_back(2); V[3].push_back(4);
    V[3].push_back(5);
    V[4].push_back(3); V[4].push_back(5);
    V[5].push_back(1); V[5].push_back(2); V[5].push_back(3);
    V[5].push_back(4);
    for(int i=1;i<=5;i++) {
        sort(V[i].begin(),V[i].end());
    }
    memset(visited,false,sizeof(visited));
    ans[0]='1';
    ans[9]='\0';
    dfs(1,1);
    return 0;
}
