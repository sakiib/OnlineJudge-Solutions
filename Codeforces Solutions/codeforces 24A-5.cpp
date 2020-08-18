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

int L[ N ] = {0} , R[ N ] = {0};

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int x = 0 , y = 0;
    for( int i = 1; i <= n; i++ ) {
        int u , v , w;
        cin >> u >> v >> w;
        if( !L[u] && !R[v] ) {
            L[u] = 1 , R[v] = 1;
            x += w;
        }
        else {
            R[u] = 1 , L[v] = 1,
            y += w;
        }
    }
    cout << min( x , y ) << endl;
    return 0;
}

