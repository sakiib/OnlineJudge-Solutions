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

LL ara[ N ] , cnt[ 2*N ];
bool used[ N ];

int main( int argc, char const *argv[] ) {
    LL n , x;
    cin >> n >> x;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    LL ans = 0;
    for( int i = 1; i <= n; i++ ) {
        LL k = ara[i]^x;
        ans += cnt[ k ];
        cnt[ ara[i] ]++;
    }
    cout << ans <<endl;
    return 0;
}

