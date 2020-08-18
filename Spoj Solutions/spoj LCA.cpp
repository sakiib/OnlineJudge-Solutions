#include <bits/stdc++.h>
using namespace std;

typedef pair < int , int > ii;
typedef pair < int , ii > iii;
typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );
#define pb                 push_back
#define sz( V )            (int)( V.size() )
#define all( V )           V.begin() , V.end()
#define mem( a , x )       memset( a, x, sizeof( a ) )
#define Fix( x )           setprecision( x ) << fixed
#define FOR( i , a , b )   for( int i = a; i <= b; i++ )
#define ROF( i , a , b )   for( int i = a; i >= b; i-- )

const int level = 20;

int n;
vector <int> graph[ N ];
int parent[ N ][ level+5 ];
int depth[ N ];

void dfs( int s , int p ) {
    parent[s][0] = p;
    depth[s] = depth[p] + 1;
    for( auto x : graph[s] ) if( x != p ) dfs( x , s );
}
void Precompute_LCA( ) {
    FOR( i , 1 , level ) {
        FOR( node , 1 , n ) {
            if( parent[node][i-1] != -1 ) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
            }
        }
    }
}
int LCA( int u , int v ) {
    if( depth[u] > depth[v] ) swap( u , v );
    int dif = depth[v] - depth[u];
    FOR( i , 0 , level ) if( ( dif >> i)&1 ) v = parent[v][i];
    if( u == v ) return u;
    ROF( i , level , 0 ) {
        if( parent[u][i] != parent[v][i] ) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    FOR( tc , 1 , t ) {
        cin >> n;
        FOR( i , 1 , n ) {
            int k;
            cin >> k;
            int v;
            FOR( kk , 1 , k ) cin >> v , graph[i].pb( v );
        }
        mem( parent , -1 );
        depth[0] = 0;
        dfs( 1 , 0 );
        Precompute_LCA( );
        int q;
        cin >> q;
        cout << "Case " << tc << ":" <<endl;
        while( q-- ) {
            int u , v;
            cin >> u >> v;
            cout << LCA( u , v ) << endl;
        }
        FOR( i , 1 , N ) graph[i].clear();
    }
    return 0;
}








