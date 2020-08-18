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

LL can[ N ];

int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    LL tot = 0;
    for( int i = 1; i <= n; i++ ) {
        LL rem;
        cin >> rem;
        tot += rem;
    }
    for( int i = 1; i <= n; i++ ) {
        cin >> can[i];
    }
    sort( can+1 , can+n+1 );
    reverse( can+1 , can+n+1 );
    if( (can[1]+can[2]) >= tot ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

