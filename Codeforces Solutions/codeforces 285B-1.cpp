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

#define FOR1(i,a,b)     for(int i=a; i<=b ;i++)
#define FOR0(i,a)       for(int i=0; i<a ;i++)
#define CLR(a,n)        FOR0(i,n) a[i].clear()
#define MEM(a,x)        memset(a, x ,sizeof(a))

#define scanI(a)        scanf("%d",&a)
#define scanI2(a,b)     scanI(a), scanI(b)
#define scanI3(a,b,c)   scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a)        scanf("%lld",&a)
#define scanL2(a,b)     scanL(a), scanL(b)
#define scanL3(a,b,c)   scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define Read            freopen("input.txt", "r" ,stdin)
#define Write           freopen("output.txt", "w" ,stdout)

int ara[N];
vector<int> V[N];
int cost[N];

void bfs(int start) {
    memset(cost,-1,sizeof(cost));
    cost[start]=0;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()) {
        int f=Q.front();
        Q.pop();
        for(int i=0;i<V[f].size();i++) {
            int next=V[f][i];
            if(cost[next]==-1||(cost[next]>cost[f]+1)) {
                cost[next]=cost[f]+1;
                Q.push(next);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    int n,s,t;
    scanf("%d%d%d",&n,&s,&t);
    for(int i=1;i<=n;i++) {
        scanf("%d",&ara[i]);
        V[i].push_back(ara[i]);
    }
    bfs(s);
    printf("%d\n",cost[t]);
    return 0;
}



