#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10000];
int indegree[10000];

int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        int cnt=1;
        map<string,int> M;
        memset(indegree,0,sizeof(indegree));
        char a[20],b[20];
        for(int i=1;i<=n;i++) {
            scanf("%s %s",a,b);
            if(M[a]==0) M[a]=cnt++;
            if(M[b]==0) M[b]=cnt++;
            graph[M[a]].push_back(M[b]);
            indegree[M[b]]++;
        }
        priority_queue<int,vector<int>,greater<int> > Q;
        int ans=0;
        for(int i=1;i<cnt;i++) {
            if(indegree[i]==0) Q.push(i);
        }
        while(!Q.empty()) {
            int top=Q.top();
            Q.pop();
            ans++;
            for(int i=0;i<graph[top].size();i++) {
                int next=graph[top][i];
                indegree[next]--;
                if(indegree[next]==0) Q.push(next);
            }
        }
        if((cnt-1)!=ans) printf("Case %d: No\n",tc);
        else printf("Case %d: Yes\n",tc);
        for(int i=1;i<=cnt+5;i++) graph[i].clear();
    }
    return 0;
}

