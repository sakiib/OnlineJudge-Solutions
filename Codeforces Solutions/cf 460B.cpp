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

vector <LL> V;

bool pf( int x ) {
    int sum = 0;
    while( x ) {
        int rem = x%10;
        sum += rem;
        x /= 10;
        if( sum > 10 ) return false;
    }
    return ( sum == 10 );
}
void calc( ) {
    int cnt = 0;
    for( int i = 1; i <= 15000000; i++ ) {
        if( pf(i)) V.push_back( i );
        if( cnt > 10000 ) break;
    }
}
int main( int argc, char const *argv[] ) {
    calc();
    int n;
    cin >> n;
    cout << V[n-1] << endl;
    return 0;
}

