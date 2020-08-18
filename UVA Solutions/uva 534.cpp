/*MST-Kruskal's*/
#include<bits/stdc++.h>
using namespace std;

int a[100005],b[100005];

struct data {
    int u,v;
    double w;
    bool operator<(const data &q)const {
        return (w<q.w);
    }
};
int tc=1,n;
vector<data> V;
vector<int> graph[100005];
int parent[100005];
bool visited[100005];

void makeset(int n) {
    for(int i=1;i<=n;i++) parent[i]=i;
}
int Find(int x) {
    if(parent[x]==x) return x;
    else return parent[x]=Find(parent[x]);
}
void Union(int a,int b) {
    int u=Find(a); int v=Find(b);
    if(u!=v) parent[u]=v;
}
void MST() {
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        int u=V[i].u; int v=V[i].v;
        if(Find(u)!=Find(v)) {
            Union(u,v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
}
double dist(int i,int j) {
    int x1=a[i],y1=b[i],x2=a[j],y2=b[j];
    double sq=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return sq;
}
void dfs(int start,double mx) {
    visited[start]=true;
    if(start==2) {
        printf("Scenario #%d\n",tc++);
        cout<<"Frog Distance = "<<setprecision(3)<<fixed<<mx<<endl;
        return;
    }
    else for(int i=0;i<graph[start].size();i++) {
        int next=graph[start][i];
        if(!visited[next]) {
            mx=max(mx,dist(start,next));
            dfs(next,mx);
        }
    }
}
int main(int argc,char const *argv[]) {

    while(scanf("%d",&n)) {
        if(n==0) break;
        V.clear();
        for(int i=1;i<=100004;i++) graph[i].clear();
        memset(visited,false,sizeof(visited));

        for(int i=1;i<=n;i++) {
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                V.push_back({i,j,dist(i,j)});
            }
        }
        makeset(n);
        MST();
        double mx=0.0;
        dfs(1,mx);
        printf("\n");
    }
    return 0;
}
