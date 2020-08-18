#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all( V ) V.begin( ),V.end( )
#define Unique( V ) sort( all( V ) ), V.erase( unique( all( V ) ), V.end() )

typedef long long int LL;
const int N = 100005;

int n , q;
LL a[ 2*N ];
map < LL , LL > cnt;
vector < LL > V;

LL solve( LL val ) {
        LL ans = 0;
        for( auto x : V ) {
               LL t = val/x;
               ans += min( t , cnt[x] );
               val -= min( t , cnt[x] )*( x );
        }
        if( val == 0 ) return ans;
        else return -1;
}
int main( int argc, char const *argv[] ) {
        fast_io;
        cin >> n >> q;
        for( int i = 1; i <= n; i++ ) cin >> a[i] , cnt[ a[i] ]++ , V.push_back( a[i] );
        Unique( V );
        reverse( all(V) );
        while( q-- ) {
                LL val;
                cin >> val;
                cout << solve( val ) << endl;
        }
        return 0;
}






