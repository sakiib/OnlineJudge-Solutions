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
    inline LL GetFHash( char *s , int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return HashF[ r ];
        LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline LL GetBHash( char *s , int l , int r ) {
        l ++ , r ++;
        int len = strlen( s );
        if( r == len ) return HashR[ l ];
        LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline bool IsPalindrome( char *s , int l , int r ) {
        if( r < l ) return false;
        return ( GetFHash( s , l , r ) == GetBHash( s , l , r ) );
    }
};

RabinKarpRollingHash H;

vector < int > valid;

int main( int argc, char const *argv[] ) {
    H.GeneratePower();

    scanf("%s",str);

    H.BuildHash( str );

    int len = strlen( str );

    for( int i = 0; i < len-1; i++ ) {
        if( H.GetFHash( str, 0, i ) == H.GetFHash( str, len-1-i, len-1 ) ) {
            valid.push_back( i+1 );
        }
    }
    if( valid.empty() ) return printf("Just a legend\n") , 0;
    int ans = -1;
    int lo = 0 , hi = valid.size()-1;
    while( lo <= hi ) {
        int mid = ( lo+hi )>>1;
        bool ok = false;
        for( int i = 1; i+valid[mid]-1 < len-1; i++ ) {
            if( H.GetFHash( str, i, i+valid[mid]-1 ) == H.GetFHash( str, 0, valid[mid]-1 ) ) {
                ok = true;
                break;
            }
        }
        if( ok ) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    if( ans == -1 ) return printf("Just a legend\n") , 0;
    for( int i = 0; i < valid[ans]; i++ ) printf("%c",str[i]);
    return 0;
}

