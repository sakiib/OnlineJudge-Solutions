#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 305;

LL cost[ N ][ N ];

int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= n; j++ ) {
            scanf("%lld",&cost[i][j]);
        }
    }
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        int x , y;
        LL c;
        scanf("%d %d %lld",&x,&y,&c);
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
            for( int j = 1; j <= n; j++ ) {
                cost[i][j] = min( cost[i][j] , cost[i][x]+c+cost[y][j] );
                cost[i][j] = min( cost[i][j] , cost[i][y]+c+cost[x][j] );
                ans += cost[i][j];
            }
        }
        printf("%lld ",ans/2);
    }
    return 0;
}

