#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(V) V.begin(), V.end()
#define Unique(V) sort(all(V)), V.erase(unique(all(V)), V.end())
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int LL;
const int N = 1e5 + 5;
const int inf = 1e9;

int n , a[ 1005 ];
int dp[ 1005 ][ 1005 ][ 2 ];

int solve( int x , int y , int turn ) {
        if( x > y ) return 0;
        if( x == y ) return a[x];
        if( dp[x][y][turn] != -1 ) return dp[x][y][turn];
        int ret = -inf;
        if( turn == 0 ) {
                ret = max( ret , a[x] - solve( x+1 , y , 1 ) );
                ret = max( ret , a[y] - solve( x , y-1 , 1 ) );
        }
        else {
                if( a[x] >= a[y] ) ret = max( ret , a[x] - solve( x+1 , y , 0 ) );
                else ret = max( ret , a[y] - solve( x , y - 1 , 0 ) );
        }
        return dp[x][y][turn] = ret;
}
int main( ) {
        FIO;
        #ifdef OFFLINE
            freopen( "input.txt" , "r" , stdin );
        #endif // OFFLINE
        int tc = 0;
        while( cin >> n ) {
                if( n == 0 ) break;
                for( int i = 1; i <= n; i++ ) cin >> a[i];
                memset( dp , -1 , sizeof( dp ) );
                int ans = solve( 1 , n , 0 );
                cout << "In game " << ++tc <<
                ", the greedy strategy might lose by as many as " << ans << " points." << endl;
        }
        return 0;
}
