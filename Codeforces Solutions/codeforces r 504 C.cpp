#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL D , A , M , B , X;

bool ok( LL days ) {
        LL full = days/(M+1);
        LL rem = days%(M+1);
        LL tot = D + full * ( M * A + B ) + rem * A;
        return ( tot >= X );
}
LL solve( ) {
        LL lo = 1 , hi = inf , ret = -1;
        while( lo <= hi ) {
                LL mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) {
                        ret = mid;
                        hi = mid - 1;
                }
                else lo = mid + 1;
        }
        return ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        while( t-- ) {
                cin >> D >> A >> M >> B >> X;
                cout << solve( ) << endl;
        }
        return 0;
}






