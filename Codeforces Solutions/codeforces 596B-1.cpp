#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 200005;

int n;
LL a[ N ];
LL ans = 0;

struct BinaryIndexedTree {

    LL BIT[ N+10 ];

    inline void Init( ) { memset( BIT , 0 , sizeof( BIT ) ); }

    inline LL RQuery ( int l , int r ) { return PQuery( r ) - PQuery( l-1 ); }

    inline void PUpdate ( int idx , LL val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
    }
    inline LL PQuery ( int idx ) {
        LL ret = 0;
        for( ; idx > 0; idx -= ( idx & -idx ) ) ret += BIT[ idx ]; return ret;
    }
    inline void RUpdate ( int idx , int idy , LL val ) {
        for( ; idx <= N; idx += ( idx & -idx ) ) BIT[ idx ] += val;
        idy++ , val *= -1;
        for( ; idy <= N; idy += ( idy & -idy ) ) BIT[ idy ] += val;
    }
} bit;

int main( int argc , char const *argv[] ) {
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n; i++ ) {
                LL cur = bit.PQuery( i );
                if( cur == a[i] ) continue;
                bit.RUpdate( i , n , a[i]-cur );
                ans += abs( a[i]-cur );
        }
        cout << ans << endl;
        return 0;
}



