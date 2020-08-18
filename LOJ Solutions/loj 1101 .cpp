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

struct data {
    int  u , v , w;
    data(){}
    data( int _u , int _v , int _w ) {u = _u , v = _v , w = _w;}
    bool operator <( const data &q ) const {
        return ( w < q.w );
    }
};

const int level = 20;
vector < data > V;
int par[ N ];

int n , m;
vector < pair<int,int> > graph[ N ];
int parent[ N ][ level+5 ];
int mx[ N ][ level+5 ];
int depth[ N ];
map < pair<int,int> , int > M;

void AddEdge( int u , int v , int w ) {
    graph[u].push_back( make_pair( v , w ) );
    graph[v].push_back( make_pair( u , w ) );
    M[ make_pair( u , v ) ] = w;
    M[ make_pair( v , u ) ] = w;
}
void MakeSet( ) {
    for( int i = 1; i < N; i++ ) par[i] = i;
}
int Find( int x ) {
    return ( par[x] == x ? x : par[x] = Find( par[x] ) );
}
void Union( int a , int b ) {
    int u = Find( a ) , v = Find( b );
    if( u != v ) par[u] = v;
}
void MST( ) {
    sort( V.begin() , V.end() );
    for( int i = 0; i < V.size(); i++ ) {
        int u = V[i].u , v = V[i].v , w = V[i].w;
        if( Find( u ) != Find( v ) ) {
            Union( u , v );
            AddEdge( u , v , w );
        }
    }
}
void dfs( int s , int p ) {
    parent[s][0] = p;
    depth[s] = depth[p] + 1;
    for( int i = 0; i < graph[s].size(); i++ ) {
        pair <int,int> k = graph[s][i];
        int next = k.first , cost = k.second;
        if( next == p ) continue;
        dfs( next , s );
    }
}
void Precompute_LCA( ) {
    for( int i = 1; i <= n; i++ ) {

    }
    for( int i = 1; i <= level; i++ ) {
        for( int node = 1; node <= n; node++ ) {
            if( parent[node][i-1] != -1 ) {
                parent[node][i] = parent[parent[node][i-1]][i-1];
                mx[node][i] = max( mx[node][i-1] , mx[parent[node][i-1]][i-1] );
            }
        }
    }
}
int LCA( int u , int v ) {
    if( depth[u] > depth[v] ) swap( u , v );
    int dif = depth[v] - depth[u];
    for( int i = 0; i <= level; i++ ) {
        if( ( dif >> i )&1 ) v = parent[v][i];
    }
    if( u == v ) return u;
    for( int i = level; i >= 0; i-- ) {
        if( parent[u][i] != parent[v][i] ) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int MaxEdge( int u , int v ) {
    int lca = LCA( u , v );
    int ret = 0;
    if( depth[u] > depth[v] ) swap( u , v );
    int dif = depth[v] - depth[u];
    for( int i = 0; i <= level; i++ ) {
        if( ( dif >> i )&1 ) ret = max( ret , mx[v][i] ) , v = parent[v][i];
    }
    if( u == v ) return ret;
    for( int i = level; i >= 0; i-- ) {
        if( parent[u][i] != parent[v][i] ) {
            ret = max( ret , mx[u][i] );
            ret = max( ret , mx[v][i] );
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    ret = max( ret , mx[u][0] );
    ret = max( ret , mx[v][0] );
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d %d",&n,&m);
        int u , v , w;
        for( int i = 1; i <= m; i++ ) {
            scanf("%d %d %d",&u,&v,&w);
            V.push_back( data(u,v,w) );
        }
        MakeSet( );
        MST( );

        memset( parent , -1 , sizeof( parent ) );
        memset( mx , 0 , sizeof( mx ) );

        depth[0] = 0;
        dfs( 1 , 0 );
        Precompute_LCA( );

        printf("Case %d:\n",tc);
        int q;
        scanf("%d",&q);
        while( q-- ) {
            int u , v;
            scanf("%d %d",&u,&v);
            printf("%d\n",MaxEdge( u , v ) );
        }
        for( int i = 1; i < N; i++ ) graph[i].clear();
        M.clear();
    }
    return 0;
}








