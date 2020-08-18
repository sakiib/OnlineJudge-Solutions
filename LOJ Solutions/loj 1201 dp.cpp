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

const int sz = 1005;

int n , m;
vector <int> graph[ sz ];
bool visited[ sz ];
int dp[ sz ][ 2 ];

int solve( int s , int p , int killed ) {
        int ret = 1;
        visited[s] = true;
        if( graph[s].size() == 0 ) return 0;
        if( dp[s][killed] != -1 ) return dp[s][killed];
        for( int i = 0; i < graph[s].size(); i++ ) {
                int next = graph[s][i];
                if( next != p ) {
                        if( killed ) ret += solve( next , s , 0 );
                        else {
                              ret += max( solve( next , s , 1 ) , solve( next , s , 0 ) );
                        }
                }
        }
        return dp[s][killed] = ret + killed;
}
int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
               scanf("%d %d",&n,&m);
               for( int i = 1; i <= m; i++ ) {
                      int u , v;
                      scanf("%d %d",&u,&v);
                      graph[u].push_back( v );
                      graph[v].push_back( u );
               }
               memset( dp , -1 , sizeof(dp) );
               memset( visited , false , sizeof(visited) );
               int ans = 0;

               for( int i = 1; i <= n; i++ ) {
                    if( !visited[i] ) {
                            ans += max( solve( i , 0 , 0 ) , solve( i , 0 , 1 ) );
                    }
               }
               printf("Case %d: %d\n",tc,ans);

               for( int i = 1; i < sz; i++ ) graph[i].clear();
        }
        return 0;
}







