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

LL H[ N ] , C[ N ];
int n;

LL calc( LL x ) {
    LL ret = 0;
    for( int i = 1; i <= n; i++ ) ret += ( abs(x-H[i])*C[i] );
    return ret;
}
LL TernarySearch( ) {
    LL lo = 0 , hi = 1000000 , it = 100 , ret = INF;
    while( it-- ) {
        LL midL = ( 2*lo+hi )/3;
        LL midR = ( lo+2*hi )/3;
        if( calc( midL ) < calc( midR ) ) {
            ret = min( ret , calc( midL ) );
            hi = midR;
        }
        else lo = midL;
    }
    ret = min( ret , min( calc( lo ) , calc( hi ) ) );
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%d",&n);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&H[i]);
        for( int i = 1; i <= n; i++ ) scanf("%lld",&C[i]);
        printf("%lld\n",TernarySearch( ) );
    }
    return 0;
}

