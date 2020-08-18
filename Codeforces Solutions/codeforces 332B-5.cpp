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

LL ara[ 2*N ];

int main( int argc, char const *argv[] ) {
    LL n , k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    for( int i = 1; i <= n; i++ ) {
        ara[i] += ara[i-1];
    }
    LL mx1 = 0 , l = 0;
    LL lo = 0 , hi = k;
    while( hi <= n-k ) {
        if( ara[hi]-ara[lo] > mx1 ) {
            mx1 = ara[hi]-ara[lo];
            l = lo+1;
        }
        lo++ , hi++;
    }
    LL he = n , le = n-k+1 ,  r = 0 , mx2 = 0;

    while( le <= l+k+1 ) {
        if( ara[he]-ara[le] > mx2 ) {
            mx2 = ara[he]-ara[le];
            r = le;
        }
        he-- , le++;
    }
    cout << l << " " << r <<endl;
    return 0;
}

