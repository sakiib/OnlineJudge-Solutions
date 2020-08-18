#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T> using
Treap = tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <long long,long long> pll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n;
LL a[ 3*N ];
vector <pll> graph[ 3*N ];
LL ans = -INF;

void dfs( int s , int p , LL cur ) {
        cur += a[s];
        ans = max( ans , cur );
        for( auto x : graph[s] ) {
                pll t = x;
                int ns = t.first;
                LL nc = t.second;
                if( ns == p ) continue;
                if( cur >= nc ) dfs( ns , s , cur - nc );
                dfs( ns , s , 0 );
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        cin >> n;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n - 1; i++ ) {
                int u , v , w;
                cin >> u >> v >> w;
                graph[u].push_back( pll( v , w ) );
                graph[v].push_back( pll( u , w ) );
        }
        for( int i = 1; i <= n; i++ ) dfs( i , 0 , 0 );
        cout << ans << endl;
        return 0;
}










