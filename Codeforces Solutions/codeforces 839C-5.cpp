#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> graph[ N ];
bool visited[ N ];
int sum = 0;

double dfs( int s ) {
    double sum = 0;
    visited[s] = true;
    int ans = 0;
    for( int i = 0; i < graph[s].size();i++ ) {
        int next = graph[s][i];
        if( !visited[next] ) {
            sum += dfs( next)+1;
            ans++;
        }
    }
    //cout << sum << " " << ans <<" "<<s<<endl;
    if( ans != 0 ) sum/=ans;
    return sum;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ ) {
        int u , v;
        cin >> u >> v;
        graph[u].push_back( v );
        graph[v].push_back( u );
    }
    cout <<setprecision(10)<<fixed<< dfs( 1 ) <<endl;
    return 0;
}
