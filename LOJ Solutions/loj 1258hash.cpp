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
    inline LL GetFHash( char *s , int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return HashF[ r ];
        LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ]);
        return Hash;
    }
    inline LL GetBHash( char *s , int l , int r ) {
        l ++ , r ++;
        int len = strlen( s );
        if( r == len ) return HashR[ l ];
        LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ]);
        return Hash;
    }
    inline bool IsPalindrome( char *s , int l , int r ) {
        if( r < l ) return false;
        return ( GetFHash( s , l , r ) == GetBHash( s , l , r ) );
    }
};

RabinKarpRollingHash H;

const int Base = 31;

int main( int argc, char const *argv[] ) {
    H.GeneratePower();
    int t;
    scanf("%d",&t);
    for( int tc = 1; tc <= t; tc++ ) {
        scanf("%s",str);
        int len = strlen( str );
        int res = 0;
        LL HashF = 0 , HashB = 0;
        for( int i = len-1; i >= 0; i-- ) {
            HashF = HashF*Base+str[i];
            HashB += H.Pow[len-i-1]*str[i];
            if( HashF == HashB ) {
                res = len-i;
            }
        }
        int add = len-res;
        printf("Case %d: %d\n",tc,len+add);
    }
    return 0;
}


