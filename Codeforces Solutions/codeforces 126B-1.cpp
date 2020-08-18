#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 5;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
char s[ N ];
LL Pow[ N ][ 2 ];
LL HashF[ N ][ 2 ] , HashR[ N ][ 2 ];
int len;

void BuildHash( ) {
        len = strlen( s );
        HashF[0][0] = 0 , HashR[len+1][0] = 0;
        HashF[0][1] = 0 , HashR[len+1][1] = 0;
        for( int i = 1; i <= len; i++ ) {
                    HashF[i][0] = ( HashF[i-1][0] * Base[0] + s[i-1] ) % Mod[0];
                    HashR[len-i+1][0] = ( HashR[len-i+2][0] * Base[0] + s[len-i] ) % Mod[0];
                    HashF[i][1] = ( HashF[i-1][1] * Base[1] + s[i-1] ) % Mod[1];
                    HashR[len-i+1][1] = ( HashR[len-i+2][1] * Base[1] + s[len-i] ) % Mod[1];
        }
}
LL GetFHash( int l , int r ) {
        l ++ , r ++;
        if( l == 1 ) return ( HashF[ r ][ 0 ] << 31 ) | HashF[ r ][ 1 ];
        LL Hash1 = ( HashF[ r ][ 0 ] - HashF[ l-1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashF[ r ][ 1 ] - HashF[ l-1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetBHash( int l , int r ) {
        l ++ , r ++;
        if( r == len ) return ( HashR[ l ][ 0 ] << 31 ) | HashR[ l ][ 1 ];
        LL Hash1 = ( HashR[ l ][ 0 ] - HashR[ r+1 ][ 0 ] * Pow[ r-l+1 ][ 0 ] % Mod[ 0 ] );
        Hash1 = ( Hash1 + Mod[ 0 ] ) % Mod[ 0 ];
        LL Hash2 = ( HashR[ l ][ 1 ] - HashR[ r+1 ][ 1 ] * Pow[ r-l+1 ][ 1 ] % Mod[ 1 ] );
        Hash2 = ( Hash2 + Mod[ 1 ] ) % Mod[ 1 ];
        return ( Hash1 << 31 ) | Hash2;
}
LL GetHash( int l ) {
        LL Hash1 = 0 , Hash2 = 0;
        for( int i = 1; i <= l; i++ ) {
                    Hash1 = ( Hash1 * Base[ 0 ] + s[ i-1 ] ) % Mod[ 0 ] , Hash1 %= Mod[ 0 ];
                    Hash2 = ( Hash2 * Base[ 1 ] + s[ i-1 ] ) % Mod[ 1 ] , Hash2 %= Mod[ 1 ];
        }
        return ( Hash1 << 31 ) | Hash2;
}
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}

vector <int> Length;

bool ok( int l ) {
        for( int i = 1; i + Length[l] - 1 < len - 1; i++ ) {
                if( GetFHash( i , i + Length[l] - 1 ) == GetFHash( 0 , Length[l] - 1 ) ) return true;
        }
        return false;
}
int main( int argc , char const *argv[] ) {
        genPower( );
        scanf("%s",s);
        BuildHash( );
        for( int i = 0; i < len - 1; i++ ) {
                if( GetFHash( 0 , i ) == GetFHash( len - 1 - i , len - 1 ) ) {
                        Length.push_back( i + 1 );
                }
        }
        if( !(int)Length.size() ) return printf("Just a legend\n"),0;
        int lo = 0 , hi = Length.size() - 1 , mx = -1;
        while( lo <= hi ) {
                int mid = ( lo + hi ) >> 1;
                if( ok( mid ) ) {
                        mx = mid;
                        lo = mid + 1;
                }
                else hi = mid - 1;
        }
        if( mx == -1 ) return printf("Just a legend\n"),0;
        for( int i = 0; i < Length[mx]; i++ ) printf("%c",s[i]);
        return 0;
}









