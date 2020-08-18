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

map <LL,LL> tot , lef;
LL ara[ 2*N ];

int main( int argc, char const *argv[] ) {
    LL n , k;
    scanf("%lld%lld",&n,&k);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        tot[ ara[i] ]++;
    }
    LL ans = 0;
    lef[ ara[1] ]++;
    tot[ ara[1] ]--;
    for( int i = 2; i < n; i++ ) {
        tot[ ara[i] ]--;
        if( ara[i]%k == 0 ) {
            LL l = ara[i]/k;
            LL r = ara[i]*k;
            ans += ( lef[l]*tot[r] );
        }
        lef[ ara[i] ]++;
    }
    cout << ans <<endl;
    return 0;
}

