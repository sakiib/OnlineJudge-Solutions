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
char str[ sz ] , s[ sz ] , res[ sz ];


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

bool used[ N ];
vector < pair <int , string > > ans;

int main( int argc, char const *argv[] ) {
    H.GeneratePower( );
    int len;
    scanf("%d %s",&len,str);
    H.BuildHash( str );
    int n;
    scanf("%d",&n);
    while( n-- ) {
        scanf("%s",s);
        int l = strlen( s );
        strcpy( res , s );
        for( int i = 0; i < l; i++ ) {
            if( s[i] >= 'A' && s[i] <= 'Z' ) s[i] -= 'A' , s[i] += 'a';
        }
        LL x = H.GetHash( s );
        int lf = 0 , rf = l-1;
        while( rf < len ) {
            LL h = H.GetBHash( str , lf , rf );
            if( h == x && !used[lf] && !used[rf] ) {
                for( int i = lf; i <= rf; i++ ) {
                    used[i] = true;
                }
                ans.push_back( make_pair(lf , res) );
                break;
            }
            rf++ , lf++;
        }
    }
    sort( ans.begin() , ans.end() );
    for( auto  x : ans ) cout << x.second << " ";
    return 0;
}

