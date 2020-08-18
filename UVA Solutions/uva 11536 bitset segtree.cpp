#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int N = 1e6 + 1;
int n , m , k;
int a[ N ];

void generate_seq( ) {
        for( int i = 1; i <= n; i++ ) {
                if( i <= 3 ) a[i] = i;
                else a[i] = ( a[i-1] + a[i-2] + a[i-3] )%m + 1;
        }
}
int solve( ) {
        int ans = inf;
        int l = 1 , r = 1;
        bitset <N> bit;
        while( l <= n && r <= n ) {
                while( r <= n ) {
                        if( bit.count() == k ) break;
                        if( a[r] <= k ) bit[ a[r] ] = 1;
                        r++;
                }
                while( l <= n ) {
                        if( bit.count() != k ) break;
                        if( bit.count() == k ) ans = min( ans , r - l + 1 );
                        bit[ a[l] ] = 0;
                        l++;
                }
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











