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

int n;
int dp[ 10*N ];

int solve( int x ) {
    if( x > n ) return inf;
    if( x == n ) return 0;
    if( dp[x] != -1 ) return dp[x];
    int mn = inf;
    for( int i = 1; i <= 5; i++ ) {
        mn = min( mn , solve( x+i )+1 );
    }
    return dp[x] = mn;
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    memset( dp , -1,sizeof( dp ) );
    printf("%d\n",solve( 0 ));
    return 0;
}
