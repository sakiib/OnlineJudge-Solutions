#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

long long dp[ 105 ][ 105 ];

long long nCr( int n , int r ) {
        if( r == 1 ) return dp[n][r] = n;
        if( r == 0 ) return dp[n][r] = 1;
        if( n == r ) return dp[n][r] = 1;
        if( dp[n][r] != -1 ) return dp[n][r];
        return dp[n][r] = nCr( n-1 , r ) + nCr( n-1 , r-1 );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        int n , m;
        memset( dp , -1 , sizeof( dp ) );
        while( cin >> n >> m ) {
                if( n == 0 && m == 0 ) break;
                cout << n << " things taken "<< m << " at a time is " << nCr( n , m ) << " exactly." <<endl;
        }
        return 0;
}









