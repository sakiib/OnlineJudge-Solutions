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

LL ara[ N ];
set <LL> S;

void process( LL a ) {
    while( a%2 == 0 ) a /= 2;
    while( a%3 == 0 ) a /= 3;
    S.insert( a );
}
int main( int argc, char const *argv[] ) {
    LL n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        process( ara[i] );
    }
    if( (int)(S.size()) == 1 ) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}

