#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n;
vector <int> graph[ N ];
int dp[ N ][ 2 ];

int dfs( int s , int p , int put ) {
        int ret = 0;
        if( dp[s][put] != -1 ) return dp[s][put];
        for( auto x : graph[s] ) {
                if( x != p ) {
                        if( !put ) ret += dfs( x , s , 1 );
                        else ret += min( dfs( x , s , 0 ) , dfs( x , s , 1 ) );
                }
        }
        //cout << "finish : " << s << " " << put << " " << ret << endl;
        return dp[s][put] = ( ret + put );
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        memset( dp , -1 , sizeof(dp) );
        cout << min( dfs( 1 , 0 , 0 ) , dfs( 1 , 0 , 1 ) ) << endl;
        return 0;
}






