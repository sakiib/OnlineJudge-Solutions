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
int ara[ 105 ];
LL dp[ 105 ];

LL solve( int idx ) {
    if( idx > n ) return 1LL;
    if( dp[idx] != -1 ) return dp[idx];
    LL one = 0 , ret = 0;
    for( int i = idx; i<= n; i++ ) {
        if( ara[i] == 1 ) one++;
        if( one == 1 ) ret += solve( i+1 );
    }
    return dp[idx] = ret;
}
int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    memset( dp , -1 , sizeof(dp) );
    cout << solve( 1 ) << endl;
    return 0;
}

