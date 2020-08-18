#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , a[ 10*N ];
LL dp[ 10*N ];

LL solve( int pos ) {
        if( pos > n ) return 0LL;
        if( dp[pos] != -1 ) return dp[pos];
        LL ret = 0;
        ret = max( solve( pos+1 ) , solve( pos+3 )+a[pos] );
        return dp[pos] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        memset( dp , -1 , sizeof(dp) );
        cout << solve( 1 ) << endl;
        return 0;
}






