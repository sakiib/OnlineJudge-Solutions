#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

LL Set( LL N , int pos )    { return N = N | ( 1LL << pos ); }
LL Reset( LL N , int pos )  { return N = N & ~( 1LL << pos ); }
bool Check( LL N , int pos ) { return (bool)( N & ( 1LL << pos ) ); }

string s;
int m;
int cnt[ 10 ];
LL dp[ (1 << 18)+1  ][ 101 ];
LL fact[ 11 ];
int len;

void calc( ) {
    fact[0] = 1LL;
    for( int i = 1; i <= 10; i++ ) fact[i] = fact[i-1]*i;
}
LL solve( int mask , int rem ) {
    if( mask == ( 1 << len )-1 ) return ( rem%m == 0 );
    if( dp[mask][rem] != -1 ) return dp[mask][rem];
    LL ret = 0;
    for( int i = 0; i < len; i++ ) {
        if( Check( mask , i ) ) continue;
        int num = s[i]-'0';
        if( __builtin_popcount(mask) == 0 && num == 0 ) continue;
        int cur_mask = mask;
        cur_mask = Set( cur_mask , i );
        ret += solve( cur_mask , (rem*10+num)%m );
    }
    return dp[mask][rem] = ret;
}
int main( int argc, char const *argv[] ) {
    ios_base::sync_with_stdio(0);cin.tie(0);

    calc( );
    cin >> s >> m;
    len = s.size();
    for( int i = 0; i < s.size(); i++ ) cnt[ s[i]-'0' ]++;
    memset( dp , -1 , sizeof(dp) );
    LL tot = solve( 0 , 0 );
    for( int i = 0; i <= 9; i++ ) tot /= fact[ cnt[i] ];
    cout << tot << endl;
    return 0;
}






