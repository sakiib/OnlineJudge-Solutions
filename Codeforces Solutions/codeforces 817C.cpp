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

LL SumDigit( LL num ) {
    LL ret = 0;
    while( num ) {
        ret += num%10;
        num /= 10;
    }
    return ret;
}
LL Binary_Search( LL n , LL s ) {
    LL lo = 1 , hi = n , res = 0;
    while( lo <= hi ) {
        LL mid = ( lo+hi )/2;
        if( mid-SumDigit( mid) >= s ) {
            res = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return res;
}
int main( int argc, char const *argv[] ) {
    LL n , s;
    cin >> n >> s;
    LL mn = Binary_Search( n , s );
    cout << ( mn == 0 ? 0 : ( n-mn+1 ) ) <<endl;
    return 0;
}

