#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
char s[ N ];
typedef long long LL;

const int Mod[ 2 ] = { 1000000007 , 1000000009 };
const int Base[ 2 ] = { 31 , 37 };
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
void genPower( ) {
        Pow[ 0 ][ 0 ] = Pow[ 0 ][ 1 ] = 1;
        for( int i = 1; i < N; i++ ) {
                    Pow[ i ][ 0 ] =  Pow[ i-1 ][ 0 ] * Base[ 0 ] % Mod[ 0 ];
                    Pow[ i ][ 1 ] =  Pow[ i-1 ][ 1 ] * Base[ 1 ] % Mod[ 1 ];
        }
}
LL solve( ) {
        set <LL> S;
        for( int i = 0; i < len; i++ ) {
                for( int j = i; j < len; j++ ) {
                        S.insert( GetFHash( i , j ) );
                }
        }
        return (int)(S.size() );
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        genPower( );
        for( int tc = 1; tc <= t; tc++ ) {
                scanf("%s",s);
                BuildHash( );
                printf("%d\n",solve( ) );
        }
        return 0;
}















