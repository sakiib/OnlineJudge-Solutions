#include<bits/stdc++.h>
using namespace std;
const int MX=20005;

vector<int> graph[MX];
int color[MX];
int red=1,black=2,r,b;
int ans;

void dfs(int start) {
    for(int i=0;i<graph[start].size();i++) {
        if(color[graph[start][i]]==0) {
            if(color[start]==red) {
                color[graph[start][i]]=black;
                b++;
            }
            else {
                color[graph[start][i]]=red;
                r++;
            }
            dfs(graph[start][i]);
        }
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        for(int i=0;i<=MX;i++) graph[i].clear();
        memset(color,0,sizeof(color));
        int n;
        scanf("%d",&n);
        while(n--) {
            int a,b;
            scanf("%d%d",&a,&b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        ans=0;
        for(int i=1;i<=MX;i++) {
            if(!graph[i].empty()&&color[i]==0) {
                r=0,b=0;
                color[i]=red;
                r++;
                dfs(i);
                ans+=max(r,b);
            }
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}

