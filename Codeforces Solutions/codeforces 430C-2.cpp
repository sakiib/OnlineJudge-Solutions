#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

vector <int> graph[ N ];
int A[ N ] , B[ N ];
vector <int> ans;

void dfs( int s , int p , int oddlevel , int evenlevel , int depth ) {
    if( depth%2 == 1 && oddlevel) A[s] ^= 1;
    if( depth%2 == 0 && evenlevel) A[s] ^= 1;
    if( A[s] != B[s] ) {
        A[s] ^= 1;
        ans.push_back( s );
        if( depth%2 == 1 ) oddlevel++;
        else evenlevel++;
        oddlevel %= 2 , evenlevel %= 2;
    }
    for( int i = 0; i < graph[ s ].size();i++ ) {
        int next = graph[ s ][ i ];
        if( next == p ) continue;
        dfs( next , s , oddlevel , evenlevel , depth+1 );
    }
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[ u ].push_back( v );
        graph[ v ].push_back( u );
    }
    for( int i = 1; i <= n; i++ ) {
        cin >> A[i];
    }
    for( int i = 1; i <= n; i++ ) {
        cin >> B[i];
    }
    dfs( 1 , 0 , 0 , 0 , 0 );
    cout << ans.size() <<endl;
    for( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << endl;
    }
    return 0;
}
