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

int cost[ 505 ][ 505 ];

void setup( int n ) {
    for( int i = 0; i < n; i++ ) {
        for( int j = 0; j < n; j++ ) {
            if( i == j ) cost[i][j] = 0;
            else cost[i][j] = inf;
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n , m;
        scanf("%d%d",&n,&m);
        setup( n );
        for( int i = 1; i <= m; i++ ) {
            int u , v , w;
            scanf("%d%d%d",&u,&v,&w);
            cost[u][v] = cost[v][u] = min( w , cost[u][v]);
        }
        int f;
        scanf("%d",&f);
        for( int k = 0; k < n; k++ ) {
            for( int i = 0; i < n; i++ ) {
                for( int j = 0; j < n; j++ ) {
                    cost[i][j] = min( cost[i][j] , max( cost[i][k],cost[k][j]));
                }
            }
        }
        printf("Case %d:\n",tc);
        for( int i = 0; i < n; i++ ) {
            if( cost[f][i] == inf ) printf("Impossible\n");
            else printf("%d\n",cost[f][i]);
        }
    }
    return 0;
}

