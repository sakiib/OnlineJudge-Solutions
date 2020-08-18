#include <bits/stdc++.h>
using namespace std;

const int inf = 1e7;
const int N = 105;
string a , b , v;
int la , lb , lv;
int pi[ N ] , dp[ N ][ N ][ N ];

void prefix_function( string &s ) {
        int n = (int)s.size();
        pi[0] = -1;
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
}
int solve( int x , int y , int z ) {
        if( z >= lv ) return -inf;
        if( x >= la || y >= lb ) return 0;
        if( dp[x][y][z] != -1 ) return dp[x][y][z];
        int ret = 0;
        ret = max( solve( x + 1 , y , z ) , solve( x , y + 1 , z ) );
        if( a[x] == b[y] ) {
                ret = max( ret , 1 + solve( x+1 , y+1 ,  ) );
        }
        return dp[x][y][z] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> a >> b >> v;
        la = a.size();
        lb = b.size();
        lv = v.size();
        prefix_function( v );
        memset( dp , -1 , sizeof( dp ) );
        cout << solve( 0 , 0 , 0 ) << endl;
        return 0;
}










