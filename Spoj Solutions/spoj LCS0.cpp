#include <bits/stdc++.h>
using namespace std;

int dp[ 2 ][ 50001 ];
string a , b;
int la, lb;

int LCS( ) {
        la = a.size();
        lb = b.size();
        int id = 0;
        for( int i = 0; i <= la; i++ ) {
                id =  (id^1);
                for( int j = 0; j <= lb; j++ ) {
                        if( i == 0 || j == 0 ) dp[id][j] = 0;
                        else if( a[i-1] == b[j-1] ) dp[id][j] = 1 + dp[1^id][j-1];
                        else dp[id][j] = max( dp[1^id][j] , dp[id][j-1] );
                }
        }
        return dp[id][lb];
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> a >> b;
        cout << LCS( ) << endl;
        return 0;
}










