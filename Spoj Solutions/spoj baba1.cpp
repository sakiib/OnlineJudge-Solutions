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
const double EPS = 1e-12;
const double PI = acos(-1.0);

int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        double c , A;
        cin >> c >> A;
        double lo = 0.0 , hi = c;
        int it = 550;
        while( it-- ) {
            double mid = ( lo+hi )*0.5;
            double base = mid;
            double height = sqrt( c*c-base*base );
            double area = 0.0;
            area = 0.5*base*height;
            if( area > A ) hi = mid;
            else lo = mid;
        }
        double x = lo;
        double y = sqrt( c*c-x*x );
        double h = (c*c);
        if( x > y ) swap( x , y );
        if( y <= EPS || ( h/4 < A ) ) {
            cout << -1 <<endl;
            continue;
        }
        cout <<setprecision(6)<<fixed;
        cout << x << " " << y <<" "<< c << endl;
    }
    return 0;
}

