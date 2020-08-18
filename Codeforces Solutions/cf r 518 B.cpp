#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL INF = 1e18;

LL gcd( LL a , LL b ) {
        return !b ? a : gcd( b , a%b );
}
LL lcm( LL a , LL b ) {
        return a/gcd( a , b ) * b;
}

int main( int argc , char const *argv[] ) {
        LL n , m , k , l;
        cin >> n >> m >> k >> l;
        if( n < m ) return cout << -1 << endl,0;
        LL mx = 0;
        LL lo = 1 , hi = INF;
        while( lo <= hi ) {
                LL mid = ( lo + hi ) >> 1;
                if( n/mid >= m ) mx = mid , lo = mid + 1;
                else hi = mid - 1;
        }
        lo = 1 , hi = mx;
        LL ans = -1;
        while( lo <= hi ) {
                LL mid = ( lo + hi ) >> 1;
                LL tot = m * mid;
                LL now = tot - k;
                if( now >= l ) ans = mid , hi = mid - 1;
                else lo = mid + 1;
        }
        cout << ans << endl;
        return 0;
}













