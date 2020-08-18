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

int  Set( int N , int pos )    { return N |= ( 1 << pos ); }
int  Reset( int N , int pos )  { return N = N & ~( 1 << pos ); }
bool Check( int N , int pos )  { return (bool)( N & ( 1 << pos ) );}
int  Toggle( int N , int pos ) { return ( N ^= ( 1 << pos ) ); }

char s[ 11 ];
int d;
LL fact[ 11 ];
int cnt[ 11 ];
int len;
LL dp[ 1 << 10 ][ 1001 ];

void gen_fact( ) {
        fact[0] = 1;
        for( int i = 1; i <= 10; i++ ) fact[i] = fact[i-1] * i;
}
LL solve( int mask , int rem ) {
        if( mask == ( 1 << len )-1 ) return rem == 0;
        LL ret = 0;
        if( dp[mask][rem] != -1 ) return dp[mask][rem];
        for( int i = 0; i < len; i++ ) {
                if( !Check( mask , i ) ) {
                        ret += solve( Set( mask , i ) , (rem*10+(s[i]-'0'))%d );
                }
        }
        return dp[mask][rem] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        gen_fact();
        for( int tc = 1; tc <= t; tc++ ) {
                memset( cnt , 0 , sizeof(cnt) );
                memset( dp , -1 , sizeof(dp) );
                scanf("%s %d",s,&d);
                len = strlen( s );
                for( int i = 0; i < len; i++ ) cnt[ s[i]-'0' ]++;
                LL ans = solve( 0 , 0 );
                for( int i = 0; i <= 9; i++ ) ans /= fact[ cnt[i] ];
                printf("Case %d: %lld\n",tc,ans);
        }
        return 0;
}






