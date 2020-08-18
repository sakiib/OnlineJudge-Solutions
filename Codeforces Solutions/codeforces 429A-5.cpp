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
int in[ N ] , fn[ N ];
vector <int> ans;

void dfs( int s , int p , int lvl , int cnt_odd , int cnt_even ) {
        if( lvl&1 ) {
                if( cnt_odd ) in[s] ^= 1;
        }
        if( lvl%2 == 0 ) {
                if( cnt_even ) in[s] ^= 1;
        }
        if( in[s] != fn[s] ) {
                ans.push_back( s );
                if( lvl&1 ) cnt_odd ^= 1;
                if( lvl%2 == 0 ) cnt_even ^= 1;
        }
        for( auto x : graph[s] ) {
                if( x != p ) {
                        dfs( x , s , lvl+1 , cnt_odd , cnt_even );
                }
        }
}
int main( int argc , char const *argv[] ) {
        scanf("%d",&n);
        for( int i = 1; i <= n-1; i++ ) {
                int u , v;
                scanf("%d %d",&u,&v);
                graph[u].push_back( v );
                graph[v].push_back( u );
        }
        for( int i = 1; i <= n; i++ ) cin >> in[i];
        for( int i = 1; i <= n; i++ ) cin >> fn[i];
        dfs( 1 , 0 , 0 , 0 , 0 );
        cout << ans.size() << endl;
        for( auto x : ans ) cout << x << endl;
        return 0;
}






