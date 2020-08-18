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

int n;
string s[ N ] , r[ N ];
LL cost[ N ];
LL dp[ N ][ 2 ];

LL solve( int idx , int lastrev ) {
        if( idx > n ) return 0;
        if( dp[idx][lastrev] !=-1 ) return dp[idx][lastrev];
        LL ret = INF;
        if( lastrev ) {
                if( s[idx] >= r[idx-1] ) ret = min( ret , solve( idx + 1 , 0 ) );
                if( r[idx] >= r[idx-1] ) ret = min( ret , solve( idx + 1 , 1 ) + cost[idx] );
        }
        else {
                if( s[idx] >= s[idx-1] ) ret = min( ret , solve( idx + 1 , 0 ) );
                if( r[idx] >= s[idx-1] ) ret = min( ret , solve( idx + 1 , 1 ) + cost[idx] );
        }
        return dp[idx][lastrev] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >>n;
        for( int i = 1; i <= n; i++ ) cin >> cost[i];
        for( int i = 1; i <= n; i++ ) {
                cin >> s[i];
                r[i] = s[i];
                reverse( r[i].begin() , r[i].end() );
        }
        for( int i = 1; i <= n; i++ ) {
                for(int j = 0; j <= 1; j++ ) {
                        dp[i][j] = INF;
                }
        }
        dp[1][0] = 0 , dp[1][1] = cost[1];
        for( int i = 2; i < n; i++ ) {
                for( int j = 0; j <= 1; j++ ) {
                        if( j == 0 ) {

                        }
                        else {

                        }
                }
        }
        return 0;
}















