#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

/**
n common cubic dice are thrown.
What is the probability that the sum of all thrown dice is at least x?

*/
int n , x;
uLL dp[ 25 ][ 200 ];

uLL solve( int dice , int sum ) {
        if( dice > n ) return sum >= x;
        if( dp[dice][sum] != -1 ) return dp[dice][sum];
        LL ways = 0;
        for( int i = 1; i <= 6; i++ ) ways += solve( dice + 1 , sum + i );
        return dp[dice][sum] = ways;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        while( cin >> n >> x ) {
                if( n == 0 && x == 0 ) break;
                uLL tot = 1;
                for( int i = 1; i <= n; i++ ) tot *= 6;
                memset( dp , -1 , sizeof( dp ) );
                uLL res = solve( 1 , 0 );
                uLL g = __gcd( tot , res );
                res /= g , tot /= g;
                if( res == 0 ) cout << 0 << endl;
                else if( tot == 1 ) cout << res << endl;
                else cout << res << "/" << tot << endl;
        }
        return 0;
}











