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

string s;
int len;
int dp[ 2*N ][ 30 ];

int solve( int idx , int prev ) {
        if( idx >= len ) return 0;
        if( dp[idx][prev] != -1 ) return dp[idx][prev];
        int ret = inf;
        for( char i = 'a'; i <= 'z'; i++ ) {
                if( ( i - 'a' ) == prev ) continue;
                int add = 0;
                if( i != s[idx] ) add = 1;
                ret = min( ret , solve( idx + 1 , i - 'a' ) + add );
        }
        return dp[idx][prev] = ret;
}
void print( int idx , int prev ) {
        if( idx >= len ) return;
        int mn = inf;
        int c = 0;
        for( char i = 'a'; i <= 'z'; i++ ) {
                if( ( i - 'a' ) == prev ) continue;
                int add = 0;
                if( i != s[idx] ) add = 1;
                int val = solve( idx + 1 , i - 'a' ) + add;
                if( val < mn ) mn = val , c = i - 'a';
        }
        cout << (char)( c + 'a' ) , print( idx + 1 , c );
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> s;
        len = s.size();
        memset( dp , -1 , sizeof( dp ) );
        int ans = inf , st = 0;
        for( char i = 'a'; i <= 'z'; i++ ) {
                int add = 0;
                if( i != s[0] ) add = 1;
                int cur = solve( 1 , i - 'a' ) + add;
                if( cur < ans ) ans = cur , st = i - 'a';
        }
        //cout <<"Min : "<< ans << " " << st << endl;
        cout << (char)( st + 'a' ) , print( 1 , st );
        return 0;
}















