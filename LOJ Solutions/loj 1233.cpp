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
    int x , y;
    cin >> x >> y;
    vector <int> V = { y , y , y };
    int cur = 0;
    int t = 10;
    while( t-- ) {
        if( V[0] == V[1] && V[1] == V[2] && V[0] == x ) break;
        cur++;
        if( cur%3 == 0 ) {
            V[2] = V[1]+V[0]-1;
        }
        if( cur%3 == 1 ) {
            V[0] = V[1]+V[2]-1;
        }
        if( cur%3 == 2 ) {
            V[1] = V[2]+V[0]-1;
        }
        cout << V[0] << " " << V[1] << " " << V[2] << endl;
    }
    cout << cur << endl;
    return 0;
}
