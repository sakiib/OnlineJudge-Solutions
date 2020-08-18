#include <bits/stdc++.h>
using namespace std;

const int inf = 1e5;
const int N = 105;
string a , b , c;
int la , lb , lc;
int dp[ N ][ N ][ N ];
vector <int> pi;

vector <int> prefix_function( string &s ) {
        int n = (int)s.size();
        vector <int> pi( n );
        for ( int i = 1; i < n; i++ ) {
                int j = pi[i-1];
                while ( j > 0 && s[i] != s[j] ) j = pi[j-1];
                if ( s[i] == s[j] ) j++;
                pi[i] = j;
        }
        return pi;
}
int calc( int idv , int idx ) {
        while( idv > 0 && a[idx] != c[idv] ) idv = pi[idv];
        return idv + 1;
}
int solve( int idx , int idy , int idv ) {
        if( idv >= lc ) return -inf;
        if( idx >= la || idy >= lb ) return 0;
        if( dp[idx][idy][idv] != -1 ) return dp[idx][idy][idv];
        int ret = max( solve( idx + 1 , idy , idv ) , solve( idx , idy + 1 , idv ) );
        if( a[idx] == b[idy] ) {
                int cur = 0;
                cur = 1 + solve( idx + 1 , idy + 1 , calc( idv , idx ) );
                ret = max( ret , cur );
        }
        return dp[idx][idy][idv] = ret;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio( false ); cin.tie( NULL );
        cin >> a >> b >> c;
        la = a.size();
        lb = b.size();
        lc = c.size();
        pi = prefix_function( c );
        for(int i = 0; i < pi.size(); i++ ) cout << pi[i] << " "; cout << endl;
        memset( dp , -1 , sizeof( dp ) );
        int mx = solve( 0 , 0 , 0 );
        cout << "mx "<< mx << endl;
        return 0;
}







