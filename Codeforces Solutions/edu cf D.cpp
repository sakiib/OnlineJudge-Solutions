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

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int q;
        cin >> q;
        while( q-- ) {
                LL n , m , k;
                cin >> n >> m >> k;
                if( n == m ) {
                        LL mn = n;
                        if( k < mn ) {
                                cout << -1 << endl;
                                continue;
                        }
                        LL rem = k - mn;
                        if( rem%2 == 0 ) {
                                cout << k << endl;
                                continue;
                        }
                        else cout << k - 2 << endl;
                }
                else {
                        LL mn = max( n , m );
                        if( k < mn ) cout << -1 << endl;
                        else {
                                LL ans = min( n , m );
                                LL rem = k - ans;
                                if( rem&1 ) cout << ans+rem << endl;
                                else cout << ans+rem-1 << endl;
                        }
                }
        }
        return 0;
}






