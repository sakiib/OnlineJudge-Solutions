#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int MOD = 1000000007;
const int N = 1e5 + 5;

string s;
int len;
LL dp[ N ][ 2 ][ 2 ];

LL solve( int idx , int fb , int fa ) {
        if( idx >= len ) return ( fb == 1 && fa == 1 );
        if( dp[idx][fb][fa] != -1 ) return dp[idx][fb][fa];
        LL ret = 0;
        if( s[idx] == 'b' ) {
                ret += solve( idx + 1 , 1 , fa );
                //ret += solve( idx + 1 , 0 , fa );
                ret %= MOD;
        }
        else if( s[idx] == 'a' ) {
                if( fb == 1 ) ret += solve( idx + 1 , fb , 1 );
                ret += solve( idx + 1 , fb , fa );
                ret %= MOD;
        }
        else ret += solve( idx + 1 , fb , fa );
        return dp[idx][fb][fa] = ret%MOD;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> s;
        len = s.size();
        memset( dp , -1 , sizeof( dp ) );
        LL ans = 0;
        for( int i = 0; i < len; i++ ) {
                if( s[i] == 'a' ) {
                        ans++;
                        ans %= MOD;
                        ans += solve( i + 1 , 0 , 0 )%MOD;
                        ans %= MOD;
                }
        }
        cout << ans << endl;
        return 0;
}










