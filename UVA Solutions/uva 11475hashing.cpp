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
    inline LL GetHash( string s ) {
        LL Hash = 0;
        int len = s.size( );
        for( int i = 1; i <= len; i++ ) {
            Hash = ( Hash*Base+s[ i-1 ] ) % Mod;
            Hash %= Mod;
        }
        return Hash;
    }
    inline void BuildHash( string s ) {
        int len = s.size( );
        HashF[ 0 ] = 0 , HashR[ len+1 ] = 0;
        for( int i = 1; i <= len; i++ ) {
            HashF[ i ] = ( HashF[ i-1 ]*Base+s[ i-1 ] ) % Mod;
            HashR[ len-i+1 ] = ( HashR[ len-i+2 ]*Base+s[ len-i ] ) % Mod;
        }
    }
    inline LL GetForwardHash( string s , int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return HashF[ r ];
        LL Hash = ( HashF[ r ]-HashF[ l-1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline LL GetBackwardHash( string s , int l , int r ) {
        l ++ , r ++;
        int len = s.size( );
        if( r == len ) return HashR[ l ];
        LL Hash = ( HashR[ l ]-HashR[ r+1 ]*Pow[ r-l+1 ] % Mod );
        Hash = ( Hash+Mod ) % Mod;
        return Hash;
    }
    inline bool IsPalindrome( string s , int l , int r ) {
        if( r < l ) return false;
        return ( GetForwardHash( s , l , r ) == GetBackwardHash( s , l , r ) );
    }

};

RabinKarpRollingHash Hashing;

int main( int argc , char const *argv[] ) {

    Hashing.GeneratePower( );
    string str;

    while( cin >> str ) {
        int len = str.size( );
        Hashing.BuildHash( str );
        int l = 0;
        int idx = 0;
        while( l <= len-1 ) {
            if( Hashing.IsPalindrome( str , l , len-1 ) ) {
                idx = l;
                break;
            }
            l++;
        }
        cout << str;
        for( int i = idx-1; i >= 0; i-- ) cout << str[i];
        cout << endl;
    }
    return 0;
}


