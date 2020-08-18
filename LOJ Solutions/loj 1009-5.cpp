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

vector <int> graph[ N ];
bool visited[ N ];
int r  , b ;

void dfs( int s , int col ) {
    visited[ s ] = true;
    if( !col ) r++;
    else b++;
    for( int i = 0; i < graph[ s ].size(); i++ ) {
        int next = graph[ s ][ i ];
        if( !visited[ next ] ) {
            dfs( next  , !col );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++ ) {
            int u , v;
            scanf("%d%d",&u,&v);
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        int ans = 0;
        for( int i = 1; i <= 20000; i++ ) {
            if( !visited[ i ] && graph[i].size() > 0 ) {
                r = 0 , b = 0;
                dfs( i , 0 );
                ans += max( r , b );
            }
        }
        memset( visited , false , sizeof(visited) );
        printf("Case %d: %d\n",tc,ans );
        for( int i = 1; i < N; i++ ) {
            graph[ i ].clear();
        }
    }
    return 0;
}

