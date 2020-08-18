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

LL SumofDigit( LL x ) {
    LL ret = 0;
    while( x ) {
        ret += x%10;
        x /= 10;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    LL n , s;
    cin >> n >> s;
    LL lo = 1 , hi = n;
    LL mn = -1;
    while( lo <= hi ) {
        LL mid = (lo+hi)/2;
        if( mid-SumofDigit(mid) >= s ) {
            mn = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    if( mn == - 1 ) cout << 0 <<endl;
    else cout << ( n-mn+1 ) << endl;
    return 0;
}

