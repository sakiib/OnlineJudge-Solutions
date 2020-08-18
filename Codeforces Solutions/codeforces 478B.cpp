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

LL nC2( LL x ) {
    return ( x*(x-1)/2 );
}
int main( int argc, char const *argv[] ) {
    LL n , m;
    cin >> n >> m;
    LL rem = n-m;
    rem++;
    LL mx = nC2( rem );
    LL each_team = n/m;
    LL r = n%m;
    LL mn = nC2( each_team )*m;
    mn += (each_team*r);
    cout << mn << " " << mx <<endl;
    return 0;
}

