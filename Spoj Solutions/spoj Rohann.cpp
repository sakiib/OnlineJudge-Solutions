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


LL cost[ 100 ][ 100 ];

int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int n;
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                scanf("%lld",&cost[i][j]);
            }
        }
        for( int k = 1; k <= n; k++ ) {
            for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                    cost[i][j] = min( cost[i][j] , cost[i][k]+cost[k][j] );
                }
            }
        }
        int q;
        scanf("%d",&q);
        LL ans = 0;
        while( q-- ) {
            int x , y;
            scanf("%d %d",&x,&y);
            ans += cost[x][y];
        }
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}

