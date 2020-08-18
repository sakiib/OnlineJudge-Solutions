#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int N = 1e6 + 1;
int n , m , k;
int a[ N ];
int cnt[ N ][ 101 ];

void generate_seq( ) {
        memset( cnt , 0 , sizeof( cnt ) );
        for( int i = 1; i <= n; i++ ) {
                if( i <= 3 ) a[i] = i;
                else a[i] = ( a[i-1] + a[i-2] + a[i-3] )%m + 1;
                for( int j = 1; j <= k; j++ ) {
                        cnt[i][j] += ( cnt[i-1][j] + ( a[i] == j ) );
                }
        }
}
bool ok( int len ) {
        for( int i = 1; i + len - 1 <= n; i++ ) {
                bool f = true;
                for( int j = 1; j <= k; j++ ){
                        int l = i , r = i + len - 1;
                        if( cnt[r][j] - cnt[l-1][j] <= 0 ) {
                                f = false; break;
                        }
                }
                if( f ) return true;
        }
        return false;
}
int solve( ) {
        int ans = inf;
        int lo = k , hi = n;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) ans = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d %d",&n,&m,&k);
                generate_seq( );
                int mn = solve( );
                if( mn == inf ) printf("Case %d: sequence nai\n",tc);
                else printf("Case %d: %d\n",tc,mn);
        }
        return 0;
}










