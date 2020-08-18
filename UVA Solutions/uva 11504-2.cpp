#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
vector<int> ans;
int indegree[100005];
bool visited[100005];

void top_sort(int n) {
    queue<int> Q;

    for(int i=1;i<=n;i++) if(indegree[i]==0) Q.push(i);

    while(!Q.empty()) {
        int f=Q.front(); Q.pop();
        ans.push_back(f);
        //cerr<<"*********"<<endl;
        for(int i=0;i<graph[f].size();i++) {
            int next=graph[f][i];
            if(indegree[next]>0) {
                indegree[next]--;
                if(indegree[next]==0) {
                    Q.push(next);
                }
            }
        }
    }
    //cout<<"-----------"<<endl;
    //for(int i=0;i<ans.size();i++) {
    //    cout<<"ans : "<<ans[i]<<endl;
    //}
}
void dfs(int start) {
    visited[start]=true;
    for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    while(t--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            indegree[v]++;
            graph[u].push_back(v);
        }
        top_sort(n);
        int res=0;
        memset(visited,false,sizeof(visited));
        for(int i=0;i<ans.size();i++) {
            if(!visited[ans[i]]) {
                //cerr<<"===== "<<ans[i]<<endl;
                res++;
                dfs(ans[i]);
            }
        }
        printf("%d\n",res);
        for(int i=1;i<=100005;i++) {
            graph[i].clear();
            indegree[i]=0;
        }
        ans.clear();
    }
    return 0;
}
