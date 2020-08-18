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

set < LL > S;

void dfs( LL x , LL f , LL s ) {
    if( x > 0 && f == s ) S.insert( x );
    if( x > inf ) return;
    dfs( 10*x+4 , f+1 , s );
    dfs( 10*x+7 , f , s+1 );
}
int main( int argc, char const *argv[] ) {
    dfs( 0 , 0 , 0 );
    LL n;
    scanf("%lld",&n);
    cout << *S.upper_bound( n-1 ) <<endl;
    return 0;
}

