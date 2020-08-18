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

const int sz = 505;

vector <ii> graph[ sz ];
int cost[ sz ];

void process( int n ) {
    for( int i = 0; i < n; i++ ) cost[i] = inf;
}
void dijkstra( int s ) {
    cost[ s ] = 0;
    priority_queue<ii,vector<ii>,greater<ii> > Q;
    Q.push( {cost[s],s} );
    while( !Q.empty() ) {
        ii t = Q.top();
        int s = t.second;
        int c = t.first;
        Q.pop();
        for( int i = 0; i < graph[ s ].size(); i++ ) {
            ii next = graph[ s ][ i ];
            int co = max( next.second , c );
            int so = next.first;
            if( cost[so] == inf || ( cost[so] > co ) ) {
                cost[so] = co;
                Q.push( {cost[so],so} );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , m;
        scanf("%d%d",&n,&m);
        for( int i = 1; i <= m; i++ ) {
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w);
            graph[ u ].push_back( {v,w} );
            graph[ v ].push_back( {u,w} );
        }
        int st;
        scanf("%d",&st);
        process( n );
        dijkstra( st );
        printf("Case %d:\n",tc);
        for( int i = 0; i < n; i++ ) {
            if( cost[i] == inf ) printf("Impossible\n");
            else printf("%d\n",cost[i]);
        }
        for( int i = 0; i < sz; i++ ) graph[i].clear();
    }
    return 0;
}

