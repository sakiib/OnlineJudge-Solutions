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

int main( int argc, char const *argv[] ) {
    LL a , b , x , y;
    cin >> a >> b >> x >> y;
    LL g = __gcd( x , y );
    x /= g , y /= g;
    if( a < x || b < y ) {
        cout << "0 0" << endl;
        return 0;
    }
    LL lo = 1 , hi = max( a , b ) , ans = 1;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        if( mid*x <= a && mid*y <= b ) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    cout << ans*x << " " << ans*y << endl;
    return 0;
}




