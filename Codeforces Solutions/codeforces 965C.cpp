#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const int MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );

LL candy , people , most , tim;

LL calc( LL times ) {
    LL lo = 1 , hi = most , ret = -INF;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        LL y = candy/mid;
        LL p = y/people;
        if( y%people != 0 ) p++;
        if( p < times ) hi = mid-1;
        else {
            ret = max( ret , mid*times );
            lo = mid+1;
        }
    }
    return ret;
}
int main( int argc , char const *argv[] ) {
    cin >> candy >> people >> most >> tim;
    LL ans = 0;
    for( LL i = 1; i <= tim; i++ ) {
        ans = max( ans , calc( i ) );
    }
    cout << ans << endl;
    return 0;
}



