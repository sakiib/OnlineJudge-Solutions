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

LL ara[ N ];

int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
            scanf("%lld",&ara[i]);
        }
        int c , d , s;
        cin >> c >> d >> s;
        double f = 0.0;
        if( c == 2 ) {
           for( int i = 1; i <= n; i++ ) {
             f += ( ara[i] *1.0 )+( 1.0*d/s);
           }
           cout << setprecision( 10 ) << fixed << f-(ara[1]*1.0+1.0*d/s) << endl;
        }
    }
    return 0;
}

