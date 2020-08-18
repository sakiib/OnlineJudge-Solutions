#include <bits/stdc++.h>
using namespace std;

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

int n;
LL dp[ 100 ];

LL solve( int len ) {
        if( len > n ) return 0;
        if( len == n ) return 1;
        if( dp[len] != -1 ) return dp[len];
        LL ret = 0;
        ret += solve( len + 1 );
        ret += solve( len + 2 );
        return dp[len] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        while( cin >> n ) {
                if( n == 0 ) break;
                memset( dp , -1 , sizeof( dp ) );
                cout << solve( 0 ) << endl;
        }
        return 0;
}











