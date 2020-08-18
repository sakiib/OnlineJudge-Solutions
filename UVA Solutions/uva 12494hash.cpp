#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

const int sz = 300;

char str[ sz ];
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
    inline LL GetHash( char *s ) {
        LL Hash = 0;
        int len = strlen( s );
        for( int i = 1; i <= len; i++ ) {
            Hash = ( Hash*Base+s[ i-1 ] ) % Mod;
            Hash %= Mod;
        }
        return Hash;
    }
    inline void BuildHash( char *s ) {
        int len = strlen( s );
        HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
        for( int i = 1; i <= len; i++ ) {
            HashF[ i ] = ( HashF[ i-1 ]*Base+s[ i-1 ] ) % Mod;
            HashR[ len-i+1 ] = ( HashR[ len-i+2 ]*Base+s[ len-i ] ) % Mod;
        }
    }
    inline LL GetForwardHash( char *s , int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return HashF[ r ];
        LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline LL GetBackwardHash( char *s , int l , int r ) {
        l ++ , r ++;
        int len = strlen( s );
        if( r == len ) return HashR[ l ];
        LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline bool IsPalindrome( char *s , int l , int r ) {
        if( r < l ) return false;
        return ( GetForwardHash( s , l , r ) == GetBackwardHash( s , l , r ) );
    }
};

RabinKarpRollingHash Hashing;

int main( int argc, char const *argv[] ) {

    Hashing.GeneratePower( );
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%s",str);
        Hashing.BuildHash( str );
        int win = 1 , len = strlen( str );
        set < LL > S;
        while( win <= len ) {
            int st = 0 , en = win-1;
            while( en < len ) {
                LL Hash = Hashing.GetForwardHash( str , st , en );
                S.insert( Hash );
                st++ , en++;
            }
            cout << S.size( ) << endl;
            win++;
        }
        LL ans = S.size();
        printf("%lld\n",ans);
    }
    return 0;
}

