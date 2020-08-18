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

LL a , b , c;

LL calc( LL dif ) {
    LL nb , nc;
    nb = a+dif , nc = nb+dif;
    LL cost = abs(nb-b)+abs(nc-c);
    return cost;
}
LL TernarySearch( ) {
    LL lo = -inf , hi = inf , ret = INF;
    while( hi-lo >= 5 ) {
        LL midL = ( 2*lo+hi )/3;
        LL midR = ( lo+2*hi )/3;
        if( calc( midL ) < calc( midR ) ) {
            ret = min( ret , calc( midL ) );
            hi = midR;
        }
        else lo = midL;
    }
    for( LL i = lo; i <= hi; i++ ) {
        ret = min( ret , calc( i ) );
    }
    return ret;
}
int main( int argc, char const *argv[] ) {
    int t;
    cin >> t;
    while( t-- ) {
        cin >> a >> b >> c;
        cout << TernarySearch( ) << endl;
    }
    return 0;
}

