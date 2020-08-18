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

int n , q;
vector < int > graph[ 2*N ];
vector < int > ans[ 2*N ];
int Time = 0;
int st[ 2*N ] , en[ 2*N ];
int elem[ 2*N ];

void dfs( int s , int p ) {
        st[s] = ++Time;
        elem[ st[s] ] = s;
        for( auto x : graph[s] ) if( x != p ) dfs( x , s );
        en[s] = Time;
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> q;
        for( int i = 2; i <= n; i++ ) {
                int x;
                cin >> x;
                graph[x].push_back( i );
        }
        for( int i = 1; i <= n; i++ ) sort( graph[i].begin() , graph[i].end() );
        dfs( 1 , 0 );
        while( q-- ) {
                int u , k;
                cin >> u >> k;
                int s = ( en[u] - st[u] + 1 );
                if( s < k ) cout << -1 << endl;
                else cout << elem[ st[u] + k - 1 ] << endl;
        }
        return 0;
}






