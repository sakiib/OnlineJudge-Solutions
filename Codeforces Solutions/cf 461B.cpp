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

LL n , k;
map <LL,LL> MM;

int main( int argc, char const *argv[] ) {
    scanf("%lld %lld",&n,&k);
    LL lo = 1;
    if( k >= 100 ) k = 100;
    for( LL i = 1; i <= k; i++ ) {
        MM[ n%i ]++;
    }
    for( auto x : MM ) {
        if( x.second >= 2 ) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}

