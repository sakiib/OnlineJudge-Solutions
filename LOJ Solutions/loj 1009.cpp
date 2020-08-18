#include<bits/stdc++.h>
using namespace std;
const int MX=20005;

vector<int> graph[MX];
bool visited[MX];
int color[MX];
int red=1,black=2,r,b;
int ans;

void bfs(int start) {
    queue<int> Q;
    Q.push(start);
    color[start]=red;
    r++;
    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        for(int i=0;i<graph[f].size();i++) {
            if(color[graph[f][i]]==0) {
                if(color[f]==red) {
                    color[graph[f][i]]=black;
                    b++;
                }
                else {
                    color[graph[f][i]]=red;
                    r++;
                }
                Q.push(graph[f][i]);
            }
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
                bfs(i);
                //cerr<<"r : b "<<r<<b<<endl;
                ans+=max(r,b);
            }
        }
        printf("Case %d: %d\n",tc,ans);
    }
    return 0;
}
