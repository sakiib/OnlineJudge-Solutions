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

LL LCM( LL x , LL y ) {
    return x*y/__gcd(x,y);
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    LL lo = max( 1LL , n-50 );
    LL mx = 0;
    for( LL i = lo; i <= n; i++ ) {
        for( LL j = lo; j <= n; j++ ) {
            for( LL k = lo; k <= n; k++ ) {
                mx = max( mx , LCM( i,LCM( j , k ) ));
            }
        }
    }
    cout << mx << endl;
    return 0;
}

