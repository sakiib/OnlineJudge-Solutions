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
    int n , a , b , c;
    cin >> n >> a >> b >> c;
    int mx = 0;
    for( int i = 0; a*i <= n; i++ ) {
        for( int j = 0; a*i+b*j <= n; j++ ) {
            int val = a*i+b*j;
            int rem = n-val;
            int k = rem/c;
            if( rem%c == 0 && ( a*i+b*j+k*c == n) ) {
                mx = max( mx , i+j+k );
            }
        }
    }
    cout << mx <<endl;
    return 0;
}

