#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
const int inf = (int)1e9;
const LL INF = (LL)2e18;
const int N = 100005;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n , k , l;
int ara[ N ];

int main( int argc, char const *argv[] ) {
    cin >> n >> k >> l;
    int m = n*k;
    for( int i = 1; i <= m; i++ ) cin >> ara[i];
    sort( ara+1 , ara+m+1 );
    int pos = upper_bound( ara+1 , ara+m+1 , ara[1]+l ) - ara;
    --pos;
    if( pos < n ) return cout << 0 << endl,0;
    LL ans = 0;
    int take = n , id = 0;

    for( int i = pos; i >= 1; i-- ) {
        if( (take-1)*k < i-1 ) {
            id = i; break;
        }
        ans += ara[i];
        take--;
    }
    for( int i = 1; i < id; i += k ) ans += ara[i];
    cout << ans << endl;
    return 0;
}






