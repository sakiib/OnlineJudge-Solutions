#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 2e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

#define pll pair < LL , LL >

vector < pll > graph[ N ];

LL cost[ N ];
LL ans;

void B0F1S( int s ) {
   // memset( cost , -1 , sizeof(cost) );
   for( int i = 1; i < N ; i++ ) cost[i] = INF;
    deque < LL > Q;
    cost[s] = 0;
    Q.push_front( s );
    while( !Q.empty( ) ) {
        LL t = Q.front();
        Q.pop_front();
        for( int i = 0; i < graph[t].size(); i++ ) {
            pll nxt = graph[t][i];
            LL nc = nxt.second;
            LL ns = nxt.first;
            if( cost[ns] > cost[s]+nc ) {
                cost[ns] = cost[s]+nc;
                if( nc == 0 ) Q.push_front( ns );
                else Q.push_back( ns );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int n , m;
    scanf("%d %d",&n,&m);
    for( int i = 1; i <= m; i++ ) {
        int u , v;
        scanf("%d %d",&u,&v);
        graph[u].push_back( {v,0} );
        graph[v].push_back( {u,1} );
    }
    B0F1S( 1 );
    if( cost[n] == INF ) printf("-1\n");
    else printf("%lld\n",cost[n]);
    return 0;
}

