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

LL ori , cop;

int main( int argc, char const *argv[] ) {
    scanf("%lld %lld",&cop,&ori);

    if( ori == 0 ) {
        puts("No");
        return 0;
    }
    if( ori > cop ) {
       cop = cop-abs( ori-cop-1 );
       if( cop%2 == 0 ) {
        puts("Yes");
       }
       else puts("No");
    }
    cop = cop - (ori-1);
    if( cop&1 ) puts("NO");
    else puts("Yes");
    return 0;
}


