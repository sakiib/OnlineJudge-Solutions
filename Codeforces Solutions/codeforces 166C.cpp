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
vector <int> V;

int main( int argc, char const *argv[] ) {
    int n , x;
    cin >> n >> x;
    bool f = false;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        V.push_back( ara[i] );
        if( ara[i] == x ) f = true;
    }
    int ans = 0;
    if( !f ) V.push_back( x ) , ans++;
    int med = (n+1)/2;
    sort( V.begin() , V.end() );
    while( true ) {
        int med = (V.size()+1)/2;
        if( V[med-1] == x ) break;
        if( V[med-1] < x ) V.push_back( 100000 ) , ans++;
        else V.push_back( 1 ) , ans++;
        sort( V.begin() , V.end() );
    }
    cout << ans <<endl;
    return 0;
}

