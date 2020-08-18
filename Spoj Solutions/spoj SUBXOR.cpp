#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
typedef long long LL;

int n , k;
int a[ N ];

struct BINARY_INDEXED_TREE {

        static const int MAXN = 1e6 + 5;

        int BIT[ MAXN + 5 ];

        inline void Initialize( ) {
                memset( BIT , 0 , sizeof( BIT ) );
        }
        inline int RQuery ( int l , int r ) {
                return PQuery( r ) - PQuery( l - 1 );
        }
        inline void PUpdate ( int idx , int v ) {
                if( idx <= 0 ) return;
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
        }
        inline int PQuery ( int idx ) {
                int ret = 0;
                for( ;idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ];
                return ret;
        }
        inline void RUpdate ( int idx , int idy , int v ) {
                for( ;idx <= MAXN; idx += ( idx & -idx ) ) BIT[ idx ] += v;
                idy++ , v *= -1;
                for( ;idy <= MAXN; idy += ( idy & -idy ) ) BIT[ idy ] += v;
        }
} bit;

LL solve( ) {
        bit.Initialize( );
        int xo = 0;
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                xo = xo ^ a[i];
                ans += 1LL * bit.RQuery( 1 , (xo^k) - 1 );
                bit.PUpdate( xo , +1 );
        }
        return ans;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%d %d",&n,&k);
                for( int i = 1; i <= n; i++ ) scanf("%d",&a[i]);
                printf("%lld\n",solve( ));
        }
        return 0;
}















