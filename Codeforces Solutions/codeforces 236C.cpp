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

LL LCM( LL a , LL b) {
    return a*b/__gcd(a , b);
}
int main( int argc, char const *argv[] ) {
    LL n;
    scanf("%lld",&n);
    LL f = max( 1LL , n-50 );
    LL ans = 0;
    for( LL i = f; i <= n; i++ ) {
        for( LL j = i; j <= n; j++ ) {
            for( LL k = j; k <= n; k++ ) {
               ans = max( ans , LCM(LCM( i , j ), k ) );
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

