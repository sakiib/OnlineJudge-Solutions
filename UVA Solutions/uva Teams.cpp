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

LL BigMod ( LL a , LL p , LL m ) {
     LL res = 1%m , x = a%m;
     while( p ) {
        if( p&1 ) res = ( res*x )%m;
        x = ( x*x )%m;
        p >>= 1;
    }
    return res;
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        LL n;
        scanf("%lld",&n);
        LL capt = n;
        LL rest = BigMod( 2 , n-1 , MOD);
        LL ans = ( capt%MOD * rest%MOD )%MOD;
        printf("Case #%d: %lld\n",tc,ans);
    }
    return 0;
}

