#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

int n , k;
vector <int> graph[ N ];
int sub[ N ];

void dfs( int s , int p ) {
        for( auto x : graph[s] ) {
                if( x != p ) {
                        sub[s]++;
                        dfs( x , s );
                }
        }
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( nullptr );
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                cin >> n >> k;
                for( int i = 1; i < n; i++ ) {
                        int u , v;
                        cin >> u >> v;
                        graph[u].push_back( v );
                        graph[v].push_back( u );
                }
                //dfs( 1 , 0 );
                for( int i = 1; i <= n; i++ ) {
                        if( graph[i].size() == 1 ) cout << "leaf" << endl;
                        else cout << i << " " << graph[i].size() << endl;
                }
        }
        return 0;
}











