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

LL Num_Diagonal( LL x ) {
    return ( x*(x-3)/2 );
}
LL solve( LL n ) {
    LL tot = n , lo = 4 , hi = inf , ret = 0;
    while( lo <= hi ) {
        LL mid = (lo+hi)/2;
        LL dia = Num_Diagonal( mid );
        if( dia >= tot ) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    LL n;
    int tc = 1;
    while( scanf("%lld",&n) ) {
        if( n == 0 ) break;
        LL ans = solve( n );
        printf("Case %d: %lld\n",tc++,ans);
    }
    return 0;
}

