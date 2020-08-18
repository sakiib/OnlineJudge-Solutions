#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)1e18;
const int N = 100005;
const LL MOD = 1000000007;
const double EPS = 1e-7;
const double PI = acos( -1.0 );



const int sz = 10*N;

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

char str[ 10*N ];

int main( int argc , char const *argv[] ) {

    Hashing.GeneratePower( );

    while( scanf("%s",str) != EOF ) {
        int len = strlen( str );
        Hashing.BuildHash( str );
        int l = 0;
        int idx = 0;
        while( l <= len-1 ) {
            if( Hashing.IsPalindrome( str , l , len-1 ) ) {
                idx = l-1;
                break;
            }
            l++;
        }
        if( idx == -1 ) printf("%s\n",str);
        else {
            printf("%s",str);
            for( int i = idx; i >= 0; i-- ) printf("%c",str[i]);
            printf("\n");
        }
    }
    return 0;
}
