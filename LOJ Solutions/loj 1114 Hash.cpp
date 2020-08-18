#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 105;
const int MOD[ 2 ] = { 1000000097 , 1000000007 };
const int Base[ 2 ] = { 37 , 31 };
LL P[ N ][ 2 ];
map <LL,int> M;
string s;

void genPower( ) {
        P[0][1] = P[0][0] = 1;
        for( int i = 1; i < N; i++ ) {
                P[i][0] = ( P[i-1][0] % MOD[0] * Base[0] % MOD[0] ) % MOD[0];
                P[i][1] = ( P[i-1][1] % MOD[1] * Base[1] % MOD[1] ) % MOD[1];
        }
}
LL getUnorderedHash( string s ) {
        int l = s.size();
        LL Hash1 = s[0] , Hash2 = s[0];
        for( int i = 1; i < l - 1; i++ ) {
                Hash1 = ( Hash1 % MOD[0] +  P[ s[i] ][0] % MOD[0] ) % MOD[0];
                Hash2 = ( Hash2 % MOD[1] +  P[ s[i] ][1] % MOD[1] ) % MOD[1];
        }
        Hash1 = ( Hash1 % MOD[0] +  P[ l-1 ][0] % MOD[0] ) % MOD[0];
        Hash2 = ( Hash2 % MOD[1] +  P[ l-1 ][1] % MOD[1] ) % MOD[1];
        return ( Hash1 << 31 ) | Hash2;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        genPower( );

        //freopen( "input.txt" , "r" , stdin );
        //freopen( "output.txt" , "w" , stdout );

        //cout << getUnorderedHash( "gnoig" ) << endl;
        //cout << getUnorderedHash( "going" ) << endl;

        //cout << getUnorderedHash( "xbikasy" ) << endl;
        //cout << getUnorderedHash( "xsakiby" ) << endl;

        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                M.clear();
                int n;
                cin >> n;
                for( int i = 1; i <= n; i++ ) {
                        cin >> s;
                        //if( s.size() > 3 ) sort( s.begin() + 1 , s.end() - 1 );
                        //cout << s << " " << getUnorderedHash( s ) << endl;
                        M[ getUnorderedHash( s ) ]++;
                }

                for( auto x : M ) cout << x.first << " " << x.second <<endl;
                cout << "Case " << tc << ":" << endl;
                int q;
                cin >> q;
                cin.ignore( );
                while( q-- ) {
                        getline( cin , s );
                        stringstream iss( s );
                        vector <string> V;
                        string temp;
                        while( iss >> temp ) V.push_back( temp );
                        LL ans = 1;
                        for( auto x : V ) {
                                s = x;
                                //if( s.size() > 3 ) sort( s.begin() + 1 , s.end() - 1 );
                                //cout << s << " "<< getUnorderedHash( s ) << " "<< M[ getUnorderedHash( s ) ]<< endl;
                                ans *= 1LL * M[ getUnorderedHash( s ) ];
                        }
                        cout << ans << endl;
                }
        }
        return 0;
}










