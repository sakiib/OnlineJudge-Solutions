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

bool used[ N ];

int main( int argc, char const *argv[] ) {
    int n , k;
    cin >> n >> k;
    int v = n-k;
    for( int i = 1; i <= v; i++ ) {
        cout << i << " ";
        used[i] = true;
    }
    int lo = v+1 , hi = n;
    while( lo <= hi ) {
        if( !used[hi] ) cout << hi << " " , used[hi] = true;
        hi--;
        if( !used[lo] )cout << lo << " " , used[lo] = true;
        lo++;
    }
    return 0;
}

