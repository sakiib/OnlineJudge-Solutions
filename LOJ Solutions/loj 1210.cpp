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

vector<int> G[ N ] , R[ N ];
stack <int> S;
bool visited[ N ];
int in[ N ] , out[ N ];
int same[ N ];
int scc = 0;

void dfs( int s ) {
    visited[ s ] = true;
    for( int i = 0; i < G[s].size(); i++ ) {
        int next = G[s][i];
        if( !visited[ next ] ) {
            dfs( next );
        }
    }
    S.push( s );
}
void Kosaraju( int s ) {
    visited[ s ] = true;
    for( int i = 0; i < R[s].size(); i++ ) {
        int next = R[s][i];
        if( !visited[ next ] ) {
            Kosaraju( next );
        }
    }
    same[s] = scc;
}
void Clear( ) {
    for( int i = 1; i < N; i++ ) {
        G[i].clear();
        R[i].clear();
    }
    memset( visited , false , sizeof( visited ) );
    memset( in , 0 , sizeof( in ) );
    memset( out , 0 , sizeof( out ) );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        Clear( );
        int n , e;
        scanf("%d%d",&n,&e);
        for( int i = 1; i <= e; i++ ) {
            int u , v;
            scanf("%d%d",&u,&v);
            G[ u ].push_back( v );
            R[ v ].push_back( u );
        }
        for( int i = 1; i <= n; i++ ) {
            if( !visited[i] ) {
                dfs( i );
            }
        }
        memset( visited , false , sizeof( visited ) );
        scc = 0;
        while( !S.empty( ) ) {
            int tp = S.top();
            S.pop();
            if( !visited[tp] ) {
                scc++;
                Kosaraju( tp );
            }
        }
        if( scc == 1 ) {
            printf("Case %d: 0\n",tc);
            continue;
        }
        for( int i = 1; i <= n; i++ ) {
            for( int j = 0; j < G[i].size(); j++ ) {
                int node = G[i][j];
                if( same[i] == same[node] ) continue;
                out[ same[i] ]++;
                in[ same[node] ]++;
            }
        }
        int x = 0 , y = 0;
        for( int i = 1; i <= scc; i++ ) {
            if( in[i] == 0 ) x++;
            if( out[i] == 0 ) y++;
        }
        printf("Case %d: %d\n",tc,max( x , y ) );
    }
    return 0;
}
