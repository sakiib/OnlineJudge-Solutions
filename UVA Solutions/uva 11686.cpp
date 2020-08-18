#include<bits/stdc++.h>
using namespace std;
vector<int> graph[1000005];
int indegree[1000005];
int main(int argc,char const *argv[]) {
    int n,k;
    while(scanf("%d%d",&n,&k)) {
        if(n==0&&k==0) break;
        for(int i=1;i<1000005;i++) {
            graph[i].clear();
            indegree[i]=0;
        }
        for(int i=1;i<=k;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            indegree[v]++;
        }
        queue<int> Q;
        for(int i=1;i<=n;i++) {
            if(indegree[i]==0) Q.push(i);
        }
        int cnt=0;
        vector<int> ans;
        while(!Q.empty()) {
            int t=Q.front();
            Q.pop();
            ans.push_back(t);
            cnt++;
            for(int i=0;i<graph[t].size();i++) {
                int next=graph[t][i];
                indegree[next]--;
                if(indegree[next]==0) Q.push(next);
            }
        }
        if(cnt!=n) printf("IMPOSSIBLE\n");
        else {
            for(int i=0;i<ans.size();i++) {
                printf("%d\n",ans[i]);
            }
        }
    }
    return 0;
}
