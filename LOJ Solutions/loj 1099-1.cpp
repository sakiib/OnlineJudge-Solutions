#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
typedef pair<LL,LL> pll;

LL cost[ N ] , costB[ N ];
vector <pll> graph[ N ];

void process( int n ) {
    for( int i = 1; i <= n; i++ ) {
        cost[ i ] = INF;
    }
}
void dijkstra( ) {
    priority_queue<pll,vector<pll>,greater<pll> > Q;
    cost[ 1 ] = 0 , costB[ 1 ] = 0;
    Q.push( {cost[1] , 1} );
    while( !Q.empty( ) ) {
        pll t = Q.top();
        Q.pop();
        LL s = t.second;
        LL c = t.first;
        for( int i = 0; i < graph[ s ].size(); i++ ) {
            pll next = graph[ s ][ i ];
            LL co = next.second;
            LL so = next.first;
            if( cost[so] == INF || ( cost[so] > cost[s]+co) ) {
                costB[so] = cost[so];
                cost[so] = cost[s]+co;
                Q.push( {cost[so] , so} );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL n , e;
        scanf("%lld%lld",&n,&e);
        for( int i = 1; i <= e; i++ ) {
            LL u , v , w;
            scanf("%lld%lld%lld",&u,&v,&w);
            graph[ u ].push_back( {v,w} );
            graph[ v ].push_back( {u,w} );
        }
        process( n );
        dijkstra();
        printf("Case %d: %lld  %lld\n",tc,cost[n],costB[n]);
    }
    return 0;
}

