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

const LL mod = 1e8;

LL foot , horse , flim , hlim;
LL dp[ 101 ][ 101 ][ 11][ 11 ];

LL solve( LL ft , LL ht , LL fl , LL hl ) {
    if( ft > foot || ht > horse ) return 0;
    if( fl > flim || hl > hlim ) return 0;
    if( ft == foot && ht == horse ) return 1;
    if( dp[ft][ht][fl][hl] != -1 ) return dp[ft][ht][fl][hl];
    LL ans1 = 0 , ans2 = 0;
    ans1 = solve( ft+1 , ht , fl+1 , 0 );
    ans2 = solve( ft , ht+1 , 0 , hl+1 );
    return dp[ft][ht][fl][hl] = (ans1+ans2)%mod;
}
int main( int argc, char const *argv[] ) {
    scanf("%lld%lld%lld%lld",&foot,&horse,&flim,&hlim);
    memset( dp , -1 , sizeof(dp) );
    LL res = solve( 0 , 0 , 0 , 0 ) % mod;
    printf("%lld\n",res);
    return 0;
}

