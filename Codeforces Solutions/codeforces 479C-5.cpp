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

struct data {
    int a , b;
    bool operator<( const data &q ) const {
        if( a == q.a ) return b < q.b;
        return a < q.a;
    }
};
vector <data> V;

int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int x , y;
    for( int i = 1; i <= n ; i++ ) cin >> x >> y , V.push_back( {x,y} );
    sort( V.begin(), V.end() );
    int ans = -1;
    for( int i = 0; i < V.size(); i++ ) {
        if( ans <= V[i].b ) ans = V[i].b;
        else ans = V[i].a;
    }
    cout << ans <<endl;
    return 0;
}

