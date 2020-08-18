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

const LL mx = 100003;

int main( int argc, char const *argv[] ) {
    LL node , edge;
    cin >> node >> edge;
    int i;
    cout << mx << " " << mx << endl;
    for( i = 1; i < node-1; i++ ) {
        cout << i << " " << i+1 << " " << 1 << endl;
    }
    cout << i << " " << i+1 << " " << mx-node+2 << endl;
    int x = node-1;
    for( int i = 1; i < node-1 && x < edge ; i++ ) {
        for( int j = i+2; j <= node && x < edge; j++ ) {
            cout << i << " " << j << " " << mx << endl;
            x++;
        }
    }
    return 0;
}
