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

LL n;
LL A =1 , B =2 , C = 3 , D = 4;
map <ii,LL> dp;

LL solve( LL pos , LL cur ) {
    if( cur > n ) return 0;
    if( pos == D && cur == n ) return 1;
    if( pos != D && cur == n ) return 0;
    if( dp[{pos,cur}] != 0 ) return dp[{pos,cur}];
    LL ans1 = 0 , ans2 = 0 , ans3 = 0;
    if( pos == A ) {
        ans1 = solve( B , cur+1 );
        ans2 = solve( C , cur+1 );
        ans3 = solve( D , cur+1 );
    }
    else if( pos == B ){
        ans1 = solve( A , cur+1 );
        ans2 = solve( C , cur+1 );
        ans3 = solve( D , cur+1 );
    }
    else if( pos == C ) {
        ans1 = solve( B , cur+1 );
        ans2 = solve( A , cur+1 );
        ans3 = solve( D , cur+1 );
    }
    else if( pos == D ) {
        ans1 = solve( B , cur+1 );
        ans2 = solve( C , cur+1 );
        ans3 = solve( A , cur+1 );
    }
    return dp[{pos,cur}] = (ans1%MOD+ans2%MOD+ans3%MOD)%MOD;
}
int main( int argc, char const *argv[] ) {
    scanf("%lld",&n);
    printf("%lld\n", solve( D , 0 ) );
    return 0;
}

