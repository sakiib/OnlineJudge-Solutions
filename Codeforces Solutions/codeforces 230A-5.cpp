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

struct info {
    int fight , bonus;

    bool operator <( const info &q ) const {
        if( fight == q.fight ) return bonus > q.bonus;
        else return fight < q.fight;
    }
};
vector < info > V;

int main( int argc, char const *argv[] ) {
    int s , n;
    cin >> s >> n;
    for( int i = 1; i <= n; i++ ) {
        int f , b;
        cin >> f >> b;
        V.push_back( {f,b} );
    }
    sort( V.begin() , V.end() );
    for( auto x : V ) {
        int a = x.fight , b = x.bonus;
        if( a >= s ) {
            cout << "NO" << endl;
            return 0;
        }
        s += b;
    }
    cout << "YES" << endl;
    return 0;
}

