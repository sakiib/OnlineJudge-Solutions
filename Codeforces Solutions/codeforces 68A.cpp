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

int main( int argc, char const *argv[] ) {
    int p1 , p2 , p3 , p4 , a , b;
    cin >> p1 >> p2 >> p3 >> p4 >> a >> b;
    int mn = min( p1 , min( p2 , min( p3 , p4)));
    int ans = 0;
    for( int i = a; i <= b; i++ ) {
        if( i%mn == i) ans++;
    }
    cout << ans <<endl;
    return 0;
}

