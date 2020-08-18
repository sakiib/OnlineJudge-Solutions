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

int x , y;

bool ok( vector <int> &A ) {
    return ( A[0] == A[1] && A[1] == A[2] && A[0] == x );
}
int main( int argc, char const *argv[] ) {
    cin >> x >> y;
    vector <int> V = { y , y , y };
    int ans = 0 , t = 10;
    while( t-- ) {
        V[0] = V[1]+V[2]-1;
        ans++;
        if( ok(V) ) break;
        V[1] = V[0]+V[2]-1;
        ans++;
        if( ok(V) ) break;
        V[2] = V[1]+V[0]-1;
        ans++;
        if( ok(V) ) break;
        sort( V.begin() , V.end() );
        for( auto x : V ) cout << x << " ";
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}

