#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
const  int inf = 1e9;
const  LL INF = 1e18;
const  int N = 100005;
const  int MOD = 1e9+7;
const  double EPS = 1e-6;
const  double PI = acos(-1.0);

#define FOR1(i,a,b)  for(int i=a; i<=b ;i++)
#define FOR0(i,a)    for(int i=0; i<a ;i++)
#define CLR(a,n)     FOR0(i,n) a[i].clear()
#define MEM(a,x)     memset(a, x ,sizeof(a))
#define Read         freopen("input.txt", "r" ,stdin)
#define Write        freopen("output.txt", "w" ,stdout)

string str;
vector<ii> graph[N];
int cost[10005];

void dijkstra(int st) {
    for(int i=1;i<=10000;i++) {
        cost[i]=inf;
    }
    cost[st]=0;
    priority_queue<ii,vector<ii>,greater<ii> > Q;
    Q.push({cost[st],st});

    while(!Q.empty()) {
        ii tp=Q.top();
        Q.pop();
        int ac=tp.first;
        int as=tp.second;
        for(int i=0;i<graph[as].size();i++) {
            ii next=graph[as][i];
            int ns=next.first;
            int nc=next.second;
            if(cost[ns]==inf||(cost[ns]>cost[as]+nc)) {
                cost[ns]=cost[as]+nc;
                Q.push({cost[ns],ns});
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);

        map<string,int> M;

        for(int i=1;i<=n;i++) {
           cin>>str;
           M[str]=i;
           int k;
           scanf("%d",&k);
           int id=i;
           while(k--) {
             int v,c;
             scanf("%d%d",&v,&c);
             graph[id].push_back({v,c});
           }
        }
        int q;
        scanf("%d",&q);
        while(q--) {
            string a,b;
            cin>>a>>b;
            int st=M[a];
            int en=M[b];
            dijkstra(st);
            printf("%d\n",cost[en]);
        }
        CLR(graph,N-1);
        M.clear();
    }
    return 0;
}




