#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

vector < int > graph[ 3*N ];
int subTree[ 3*N ];
int parent[ 3*N ];

void dfs( int s , int p ) {
    subTree[s] = 1;
    parent[s] = p;
    for( int i = 0; i < graph[s].size(); i++ )  {
        int next = graph[s][i];
        if( next == p ) continue;
        dfs( next , s );
        subTree[s] += subTree[next];
    }
}
int main( int argc, char const *argv[] ) {
    int n , x , y;
    scanf("%d %d %d",&n,&x,&y);
    for( int i = 1; i <= n-1; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( v ) , graph[v].push_back( u );
    }

    dfs( x , 0 );

    LL tot = 1LL*n*(n-1);
    LL ysub = subTree[y];
    int k = y;
    while( parent[k] != x ) k = parent[k];
    LL xsub = n-subTree[k];
    LL ans = tot-xsub*ysub;

    printf("%lld\n",ans);
    return 0;
}





