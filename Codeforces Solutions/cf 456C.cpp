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

int ara[ N ];
int n , k;
bool done = false;

void dfs( int s ) {
    if( s == k ) {
        done = true;
        return;
    }
    if( s >= n ) return;
    dfs( s+ara[s] );
}
int main(int argc, char const *argv[]) {
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        cin >> ara[i];
    }
    dfs( 1 );
    if( done ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
