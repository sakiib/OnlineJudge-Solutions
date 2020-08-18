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

int ara[ N ];

int main( int argc, char const *argv[] ) {
    int n;
    double k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    double lo = 0.0 , hi = 100000.0;
    while( hi-lo >= EPS ) {
        double mid = (lo+hi)/2.0;
        double t = 0.0;
        for( int i = 1; i <= n; i++ ) {
            if( ara[i] >= mid ) t += ( ara[i]-mid )*( 100.0-k )/100.0;
            else t -= ( mid-ara[i] );
        }
        if( t >= 0.0 ) lo = mid;
        else hi = mid;
    }
    cout << setprecision( 10 ) << hi << endl;
    return 0;
}

