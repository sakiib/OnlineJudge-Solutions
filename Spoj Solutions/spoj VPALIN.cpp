#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2e6 + 6;

unordered_map <LL,LL> M;
LL F[ N ] , B[ N ];
int Len[ N ];
const int MOD[2] = { 1000000009 , 1000000007 };
const int Base[2] = { 43 , 37 };
LL Pow[ N ][ 2 ];

void genPower( ) {
        Pow[0][0] = 1 , Pow[0][1] = 1;
        for( int i = 1; i < N; i++ ) {
                Pow[i][0] = ( Pow[i-1][0] * Base[0] ) % MOD[0];
                Pow[i][1] = ( Pow[i-1][1] * Base[1] ) % MOD[1];
        }
}
LL getFHash( string s ) {
        int len = s.size();
        LL hash1 = 0 , hash2 = 0;
        for( int i = 0; i < len; i++ ) {
                hash1 += ( Pow[i][0] * s[i] ) % MOD[0] , hash1 %= MOD[0];
                hash2 += ( Pow[i][1] * s[i] ) % MOD[1] , hash2 %= MOD[1];
        }
        return ( hash1 << 31 ) | hash2;
}
LL getBHash( string s ) {
        int len = s.size();
        LL hash1 = 0 , hash2 = 0;
        for( int i = len - 1; i >= 0; i-- ) {
                hash1 += ( Pow[len-1-i][0] * s[i] ) % MOD[0] , hash1 %= MOD[0];
                hash2 += ( Pow[len-1-i][1] * s[i] ) % MOD[1] , hash2 %= MOD[1];
        }
        return ( hash1 << 31 ) | hash2;
}
LL solve( int x , int y ) {
        LL mod = ( 1LL << 31 );
        LL forhx = F[x] , forhy = F[y];

        LL h2 = forhx%mod;
        LL t = ( forhx ^ h2 );
        LL h1 = ( t >> 31 );

        LL h22 = forhy%mod;
        t = ( forhy ^ h22 );
        LL h11 = ( t >> 31 );

        h2 += ( Pow[ Len[y] ][1] * h22 ) % MOD[1] , h2 %= MOD[1];
        h1 += ( Pow[ Len[y] ][0] * h11 ) % MOD[0] , h1 %= MOD[0];

        LL FHash = ( h1 << 31 ) | h2;

        ///............................

        LL bahx = B[x] , bahy = B[y];

        h2 = bahx%mod;
        t = ( bahx ^ h2 );
        h1 = ( t >> 31 );

        h22 = bahy%mod;
        t = ( bahy ^ h22 );
        h11 = ( t >> 31 );

        h22 += ( Pow[ Len[x] ][1] * h2 ) % MOD[1] , h22 %= MOD[1];
        h11 += ( Pow[ Len[x] ][0] * h1 ) % MOD[0] , h11 %= MOD[0];

        LL BHash = ( h11 << 31 ) | h22;
        if( FHash == BHash ) {
                //cout << x << " "<< y << " " << " yes" << endl;
                return 1;
        }
        else {
                //cout << x << " " << y << " " << FHash << " " << BHash << endl;
                return 0;
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        genPower( );
        int n;
        cin >> n;
        LL ans = 0;
        for( int i = 1; i <= n; i++ ) {
                int len;
                string s;
                cin >> len >> s;
                F[i] = getFHash( s );
                B[i] = getBHash( s );
                Len[i] = len;
        }
        for( int i = 1; i <= n; i++ ) {
                for( int j = 1; j <= n; j++ ) {
                        ans += solve( i , j );
                }
        }
        cout << ans << endl;
        return 0;
}










