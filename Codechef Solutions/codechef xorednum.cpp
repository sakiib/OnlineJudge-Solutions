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
#define Check( N , p )         (!(((N)&((1LL)<<(p)))==(0)))

vector < int > bit;

int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        LL n;
        cin >> n;
        for( int i = 30; i >= 0; i-- ) {
            if( Check(n,i) ) bit.push_back( 1 );
            else bit.push_back( 0 );
        }
        for( auto x : bit ) cout << x;
        cout << endl;
        bit.clear();
    }
    return 0;
}

