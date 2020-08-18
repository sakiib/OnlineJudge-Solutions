#include<bits/stdc++.h>
using namespace std;

const int N=350;

int ara[N];
string str[N];
vector<int> graph[N];
bool visited[N][N];

void dfs(int parent,int child) {
    visited[parent]=true;
    for(int i=0;i<graph[start].size();i++) {
        if(!visited[graph[start][i]]) {

        }
    }
}
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>ara[i];
    }
    for(int i=0;i<n;i++) {
        cin>>str[i];
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(str[i][j]=='1') {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(str[i][j]=='1') {
               if(i>j) swap(i,j);
               if(ara[i]>ara[j]) {
                swap(ara[i],ara[j]);

               }
            }
        }
    }
    for(int i=0;i<n;i++) cout<<ara[i]<< " ";

    return 0;
}
