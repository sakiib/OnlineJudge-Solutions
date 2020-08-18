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

string a , b , c;
int la , lb , lc;
int dp[55][55][55];

int solve( int i , int j , int k ) {
        if( i >= la || j >= lb || k >= lc ) return 0;
        if( a[i] == b[j] && a[i] == c[k] ) return 1+solve( i+1 , j+1 , k+1 );
        if( dp[i][j][k] != -1 ) return dp[i][j][k];
        int op1 = 0 , op2 = 0 , op3 = 0;
        op1 = solve( i+1 , j , k );
        op2 = solve( i , j+1 , k );
        op3 = solve( i , j , k+1 );
        return dp[i][j][k] = max( op1 , max( op2 , op3 ) );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> a >> b >> c;
                la = a.size() , lb = b.size() , lc = c.size();
                memset( dp , -1 , sizeof(dp) );
                cout << "Case " << tc << ": " << solve( 0 , 0 , 0 ) << endl;
        }
        return 0;
}






