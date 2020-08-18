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

int TC;
string a , b;
vector <int> lo , hi;
int vis[ 55 ][ 2 ][ 2 ][ 20 ][ 20 ][ 20 ];
LL dp[ 55 ][ 2 ][ 2 ][ 20 ][ 20 ][ 20 ];

void convert( string a , string b ) {
        while( a.size() < b.size() ) a = '0' + a;
        lo.clear();
        hi.clear();
        for( int i = 0; i < a.size(); i++ ) lo.push_back( a[i]-'0' );
        for( int i = 0; i < b.size(); i++ ) hi.push_back( b[i]-'0' );
        //for( auto x : a ) cout << x << " "; cout <<endl;
        //for( auto x : b ) cout << x << " "; cout <<endl;
}
LL solve( int pos , bool eqlo , bool eqhi , int t , int s , int n ) {
        //cout << pos << " " << t << " " << s << " " << n << endl;
        if( pos == hi.size() ) return ( t == s && s == n && t > 0 );
        if( vis[pos][eqlo][eqhi][t][s][n] == TC ) return dp[pos][eqlo][eqhi][t][s][n];
        vis[pos][eqlo][eqhi][t][s][n] = TC;
        if( t >= 17 || s >= 17 || n >= 17 ) return 0;
        int lor = 0 , hir = 9;
        if( eqlo ) lor = lo[pos];
        if( eqhi ) hir = hi[pos];
        LL ret = 0;
        for( int i = lor; i <= hir; i++ ) {
                ret += solve( pos + 1 , eqlo && ( i == lo[pos] ) , eqhi && ( i == hi[pos] ) ,
                                         t + ( i == 3 ) , s + ( i == 6 ) , n + ( i == 9 ) );
                ret %= MOD;
        }
        return dp[pos][eqlo][eqhi][t][s][n] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        TC = 0;
        memset( vis , 0 , sizeof( vis ) );
        while( t-- ) {
                cin >> a >> b;
                convert( a , b );
                ++TC;
                cout << solve( 0 , 1 , 1 , 0 , 0 , 0 ) << endl;
        }
        return 0;
}











