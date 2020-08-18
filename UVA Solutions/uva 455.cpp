#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int Mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int len;
string s;
const int sz = N;

struct RabinKarpRollingHash {

        const int Base = 31;
        const LL Mod = 1000000009;

        LL Pow[ sz ] , HashF[ sz ] , HashR[ sz ];

        inline void GeneratePower( ) {
                Pow[ 0 ]= 1;
                for( int i = 1; i < sz; i++ ) {
                        Pow[ i ] =  Pow[ i-1 ]*Base % Mod;
                }
        }
        inline LL GetHash( ) {
                LL Hash = 0;
                for( int i = 1; i <= len; i++ ) {
                        Hash = ( Hash*Base+s[ i-1 ] ) % Mod;
                        Hash %= Mod;
                }
                return Hash;
        }
        inline void BuildHash( ) {
                HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
                for( int i = 1; i <= len; i++ ) {
                        HashF[ i ] = ( HashF[ i-1 ]*Base+s[ i-1 ] ) % Mod;
                        HashR[ len-i+1 ] = ( HashR[ len-i+2 ]*Base+s[ len-i ] ) % Mod;
                }
        }
        inline LL GetFHash( int l , int r ) {
                l ++ , r ++;
                if( l == 1 ) return HashF[ r ];
                LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ] % Mod );
                Hash = ( Hash+Mod ) % Mod;
                return Hash;
        }
        inline LL GetBHash( int l , int r ) {
                l ++ , r ++;
                if( r == len ) return HashR[ l ];
                LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ] % Mod );
                Hash = ( Hash+Mod ) % Mod;
                return Hash;
        }
        inline bool IsPalindrome( int l , int r ) {
                if( r < l ) return false;
                return ( GetFHash( l , r ) == GetBHash( l , r ) );
        }
} H;

bool ok( int l ) {
        set <LL> S;
        int f = 0 , t = f+l-1;
        while( t < len ) {
                S.insert( H.GetFHash( f , t ) );
                f = t+1 , t = f+l-1;
        }
        if( S.size() == 1 ) return true;
        return false;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        H.GeneratePower();
        bool f = false;
        int t;
        cin >> t;
        while( t-- ) {
                cin >> s;
                len = s.size();
                H.BuildHash();
                int sq = sqrt(len);
                vector <int> d;
                if( f ) cout << endl;
                f = true;
                for( int i = 1; i <= sq; i++ ) {
                        if( len%i == 0 ) {
                                d.push_back( i );
                                if( len/i != i ) {
                                        d.push_back( len/i );
                                }
                        }
                }
                sort( d.begin() , d.end() );
                for( auto x : d ) {
                        if( ok( x ) ) {
                                cout << x << endl;
                                break;
                        }
                }
        }
        return 0;
}





