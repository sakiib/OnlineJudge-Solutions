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

int ara[ N ];

int main( int argc, char const *argv[] ) {
    int n , k;
    cin >> n >> k;
    for( int i = 1; i <= k; i++ ) {
        cin >> ara[i];
    }
    int ans = ara[1]-1;
    for( int i = 2; i <= k; i++ ) {
        if( ara[i] > ara[i-1] ) {
            ans += abs( ara[i]-ara[i-1] );
        }
        else if( ara[i] < ara[i-1] ) {
            ans += abs( n-ara[i-1] );
            ans += abs( n-ara[i] );
        }
    }
    cout << ans << endl;
    return 0;
}

