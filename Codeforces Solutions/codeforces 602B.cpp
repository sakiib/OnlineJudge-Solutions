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

int a[ N ];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> a[i];
    }
    int l = 1 , r = 1 , mn = inf , mx = -inf , ans = 0;
    while( r <= n ) {
        if( a[r] < mn ) {
            mn = a[r];
            l = r;
        }
        if( a[r] > mx ) {
            mx = a[r];
        }
        if( abs( mx-mn ) > 1 ) {
            ans = max( ans , abs( r-l+1));
            l = r;
        }
        r++;
    }
    cout << ans <<endl;
    return 0;
}

