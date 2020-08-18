#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
int n , k;
int a[ 105 ];
int dp[105][55][55][105];

int solve( int pos , int odd , int even , int cost ) {
        if( pos > n ) return ( cost > k ? -inf : 0 );
        if( cost > k ) return -inf;
        if( dp[pos][odd][even][cost] != -1 ) return dp[pos][odd][even][cost];
        int op1 = -inf , op2 = -inf;
        int add = 0 , ret = 0;
        if( odd == even && odd > 0 ) add = abs(a[pos] - a[pos-1]) , ret = 1;
        op1 = max( op1 , solve( pos+1 , odd+(a[pos]%2 == 1) , even+(a[pos]%2 == 0) , add+cost ) )+ret;
        op2 = max( op2 , solve( pos+1 , odd+(a[pos]%2 == 1) , even+(a[pos]%2 == 0) , cost ) );
        return dp[pos][odd][even][cost] = max( op1 , op2 );
}
int main( int argc, char const *argv[] ) {
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        a[n+1] = a[n];
        memset( dp , -1 , sizeof(dp) );
        cout << solve( 1 , 0 , 0 , 0 ) << endl;
        return 0;
}






