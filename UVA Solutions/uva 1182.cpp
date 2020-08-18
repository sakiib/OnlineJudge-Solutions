#include <bits/stdc++.h>
using namespace std;

const int inf = 1000000000;
string a , b;
int len_a , len_b;
int dp[55][55][2][2];

int go( int x , int y , int f1 , int f2 ) {
        if( x >= len_a || y >= len_b ) return 0;
        int ret = 0;
        if( dp[x][y][f1][f2] != -1 ) return dp[x][y][f1][f2];
        if( a[x] == b[y] ) ret = 2+go( x+1 , y+1 , 0 , 0 );
        ret = -inf;
        ret = max( ret , go( x+1 , y , 0 , 1 ) - (f2^1) );
        ret = max( ret , go( x , y+1 , 1 , 0 ) - (f1^1) );
        return dp[x][y][f1][f2] = ret;
}
int main( int argc , char const *argv[] ) {
        int t;
        cin >> t;
        while( t-- ) {
                cin >> a >> b;
                len_a = a.size() , len_b = b.size();
                memset( dp , -1 , sizeof(dp) );
                cout << go( 0 , 0 , 0 , 0 ) << endl;
        }
        return 0;
}
