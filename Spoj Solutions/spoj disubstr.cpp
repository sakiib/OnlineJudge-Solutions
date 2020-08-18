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

const int sz = 1005;

char str[ sz ];


struct RabinKarpRollingHash {

    const int Base = 31;
    const LL Mod = 1000000009;

    LL Pow[ sz ] , HashF[ sz ] , HashR[ sz ];

    inline void GeneratePower( ) {
        Pow[ 0 ]= 1;
        for( int i = 1; i < sz; i++ ) {
            Pow[ i ] =  Pow[ i-1 ]*Base;
        }
    }
    inline LL GetHash( char *s ) {
        LL Hash = 0;
        int len = strlen( s );
        for( int i = 1; i <= len; i++ ) {
            Hash = ( Hash*Base+s[ i-1 ] );
        }
        return Hash;
    }
    inline void BuildHash( char *s ) {
        int len = strlen( s );
        HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
        for( int i = 1; i <= len; i++ ) {
            HashF[ i ] = ( HashF[ i-1 ]*Base+s[ i-1 ] );
            HashR[ len-i+1 ] = ( HashR[ len-i+2 ]*Base+s[ len-i ] );
        }
    }
    inline LL GetForwardHash( char *s , int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return HashF[ r ];
        LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ] );
        return Hash;
    }
    inline LL GetBackwardHash( char *s , int l , int r ) {
        l ++ , r ++;
        int len = strlen( s );
        if( r == len ) return HashR[ l ];
        LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ]  );
        return Hash;
    }
    inline bool IsPalindrome( char *s , int l , int r ) {
        if( r < l ) return false;
        return ( GetForwardHash( s , l , r ) == GetBackwardHash( s , l , r ) );
    }
};

RabinKarpRollingHash Hashing;

int main( int argc, char const *argv[] ) {

    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%s",str);
        int len = strlen( str );
        unordered_set < LL > S;
        for( int i = 0; i < len; i++ ) {
            LL Hash = 0;
            for( int j = i; j < len; j++ ) {
                Hash = Hash*MOD+str[j];
                S.insert( Hash );
            }
        }
        LL ans = S.size( );
        printf("%lld\n",ans);
    }
    return 0;
}
/**
ABCD
A AB ABC ABCD
B BC BCD
C CD
D
*/

