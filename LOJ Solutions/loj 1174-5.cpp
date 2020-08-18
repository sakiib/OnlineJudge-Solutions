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
int st , en;
int dist1[ N ] , dist2[ N ];

void bfs1( int st ) {
    memset( dist1 , -1 , sizeof(dist1) );
    queue <int> Q;
    dist1[st] = 0;
    Q.push( st );
    while( !Q.empty() ) {
        int f = Q.front();
        Q.pop();
        for( int i = 0; i < graph[ f ].size(); i++ ) {
            int next = graph[ f ][ i ];
            if( dist1[ next ] == -1 ||( dist1[next] > dist1[f]+1) ) {
                dist1[ next ] = dist1[f]+1;
                Q.push( next );
            }
        }
    }
}
void bfs2( int en ) {
    memset( dist2 , -1 , sizeof(dist2) );
    queue <int> Q;
    dist2[en] = 0;
    Q.push( en );
    while( !Q.empty() ) {
        int f = Q.front();
        Q.pop();
        for( int i = 0; i < graph[ f ].size(); i++ ) {
            int next = graph[ f ][ i ];
            if( dist2[ next ] == -1 ||( dist2[next] > dist2[f]+1) ) {
                dist2[ next ] = dist2[f]+1;
                Q.push( next );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , e;
        scanf("%d%d",&n,&e);
        for( int i = 1; i <= e; i++ ) {
            int u , v;
            scanf("%d%d",&u,&v);
            graph[ u ].push_back( v );
            graph[ v ].push_back( u );
        }
        scanf("%d%d",&st,&en);
        bfs1( st );
        bfs2( en );
        int ans = 0;
        for( int i = 0; i < n; i++ ) {
            ans = max( ans , dist1[i]+dist2[i] );
        }
        printf("Case %d: %d\n",tc,ans);
        for( int i = 0; i < N; i++ ) graph[i].clear();
    }
    return 0;
}

