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

int a[ 10 ] , b[ 10 ];
vector <int> V;

int main( int argc, char const *argv[] ) {
    int n , m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    for( int i = 1; i <= m; i++ ) cin >> b[i];
    for( int i = 1; i <= n; i++ ) {
        for( int j = 1; j <= m; j++ ) {
            if( a[i] == b[j] ) V.push_back( a[i] );
            else {
                V.push_back( a[i]*10+b[j] );
                V.push_back( b[j]*10+a[i] );
            }
        }
    }
    sort( V.begin() , V.end() );
    cout << V[0] << endl;
    return 0;
}

