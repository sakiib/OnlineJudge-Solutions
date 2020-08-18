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

LL a[ 2*N ] , b[ 2*N ];

int main( int argc, char const *argv[] ) {
    LL n , m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    for( int i = 1; i <= m; i++ ) cin >> b[i];
    sort( a+1 , a+n+1 );
    for( int i = 1; i <= m; i++ ) {
        int idx = upper_bound(a+1 , a+n+1 , b[i] )-a;
        --idx;
        cout << idx << " ";
    }
    return 0;
}

