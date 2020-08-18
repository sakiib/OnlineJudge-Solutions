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

bool ok( int id ) {
    LL f = Hashing.GetForwardHash( str , 0 , id );
    int len = strlen( str );
    for( int i = 0; i+id < len; i++ ) {
        LL r = Hashing.GetBackwardHash( str , i , i+id );
        if( f == r ) return true;
    }
    return false;
}
int BS( int l , int h ) {
    int lo = l , hi = h , ret = 0;
    while( lo <= hi ) {
        int mid = ( lo+hi )/2;
        if( ok( mid ) ) {
            ret = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    Hashing.GeneratePower( );
    int t;
    scanf("%d",&t);
    while( t-- ) {
        scanf("%s",str);
        Hashing.BuildHash( str );
        int id = BS( 0 , strlen( str )-1 );
        for( int i = id; i >= 0; i-- ) printf("%c",str[i]);
        printf("\n");
    }
    return 0;
}
