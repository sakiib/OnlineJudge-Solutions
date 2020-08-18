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

int ara[ 105 ];

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
    }
    sort( ara+1 , ara+n+1 );
    cout << ara[n] <<" ";
    for( int i = 2; i < n; i++ ) cout << ara[i] << " ";
    cout << ara[1] <<endl;
    return 0;
}

