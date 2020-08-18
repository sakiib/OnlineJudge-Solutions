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

LL ara[ 10*N ];
LL mn = INF , mx = -INF;
int n;
map <LL,LL> M;

bool ok( ) {
    for( int i = 2; i <= n; i++ ) {
        if( ara[i] >= ara[i-1] ) continue;
        else return false;
    }
    return true;
}
int main( int argc, char const *argv[] ) {
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld",&ara[i]);
        mn = min( mn , ara[i] );
        mx = max( mx , ara[i] );
        M[ ara[i] ]++;
    }
    if( ok( ) || n == 1 ) printf("0\n");
    else if( n == 2 ) printf("Impossible\n");
    else if( ara[1] == mn || ara[n] == mx ) printf("1\n");
    else if( ara[1] == mx && ara[n] == mn && M[mx] == M[mn] && M[mx] == 1 ) printf("3\n");
    else printf("2\n");
    return 0;
}
