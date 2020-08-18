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

map <int,int> pos;
int ara[ 2*N ];

int main( int argc, char const *argv[] ) {
    int n , q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        pos[ ara[i] ] = i;
    }
    int ans = 0;
    while( q-- ) {
        int x , y;
        cin >> x >> y;
        if( pos[x] > pos[y] ) swap( x , y );
        int l = pos[x] , r = pos[y];
        int coun = l-1+n-r;
        int clo = r-l-1;
        if( coun&1 || clo&1 ) ans++;
    }
    cout << ans << endl;
    return 0;
}

