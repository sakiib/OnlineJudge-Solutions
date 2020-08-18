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

int parent[ sz ];
int n , m;

struct data {
    int u , v , w;
    bool operator <( const data &q ) const {
        return ( w < q.w );
    }
};

vector <data> V;
vector <ii> graph[ sz ];
int ans[ sz ];

void makeset( int n ) {
    for( int i = 0; i < n; i++ ) parent[i] = i;
}
int Find( int x ) {
    return (parent[x] == x ? x : parent[x] = Find( parent[x] ) );
}
void Union( int a , int b ) {
    int u = Find( a ) , v = Find( b );
    if( u != v ) parent[u] = v;
}
void MST_Kruskal( ) {
    sort( V.begin() , V.end() );
    int taken = 0;
    for( int i = 0; i < V.size(); i++ ) {
        int u = V[i].u , v = V[i].v , w = V[i].w;
        if( Find(u) != Find(v) ) {
            Union( u , v );
            graph[ u ].push_back( {v,w} );
            graph[ v ].push_back( {u,w} );
            taken ++;
        }
        if( taken == n-1 ) break;
    }
}
void dfs( int s , int p ) {
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        ii next = graph[ s ][ i ];
        int node = next.first;
        int cost = next.second;
        if( node == p ) continue;
        ans[ node ] = max( ans[s] , cost );
        dfs( node , s );
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d%d",&n,&m);
        makeset( n );
        for( int i = 0; i < m; i++ ) {
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w);
            V.push_back( {u,v,w} );
        }
        MST_Kruskal();
        int st;
        scanf("%d",&st);
        memset( ans , -1 , sizeof( ans ) );
        ans[ st ] = 0;
        dfs( st , -1 );
        printf("Case %d:\n",tc);
        for( int i = 0; i < n; i++ ) {
           if( ans[i] == -1 ) printf("Impossible\n");
           else printf("%d\n",ans[i]);
        }
        for( int i = 0; i < sz; i++ ) graph[i].clear();
        V.clear();
    }
    return 0;
}

