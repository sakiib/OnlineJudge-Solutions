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

bool EqualTo( double a , double b ) { return ( fabs ( a - b ) <= eps ); }
bool NotEqual( double a , double b ) { return ( fabs ( a - b ) > eps ); }
bool LessThan( double a , double b ) { return ( a + eps < b ); }
bool LessThanEqual( double a , double b ) { return ( a < b + eps ); }
bool GreaterThan( double a , double b ) { return ( a > b + eps ); }
bool GreaterThanEqual( double a , double b ) { return ( a + eps > b ); }

int lift[ N ] , land[ N ];
int n , m;

double ok( double tot ) {
        for( int i = 1; i <= n; i++ ) {
               tot -= ( 1.0*tot/lift[i] );
               tot -= ( 1.0*tot/land[i+1] );
        }
        return tot;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) cin >> lift[i];
        for( int i = 1; i <= n; i++ ) cin >> land[i];
        lift[n+1] = lift[1] , land[n+1] = land[1];
        double lo = 0.0 , hi = inf , ans = -1.0;
        int it = 350;
        while( it-- ) {
                double mid = (lo+hi)/2.0;
                double w = m*1.0+mid;
                double cur = ok( w );
                if( EqualTo( cur , m ) ) {
                        ans = mid;
                        hi = mid;
                }
                else if( LessThan( cur , m ) ) lo = mid;
                else hi = mid;

        } return cout << setprecision(10) << fixed << ans << endl,0;
        return 0;
}






