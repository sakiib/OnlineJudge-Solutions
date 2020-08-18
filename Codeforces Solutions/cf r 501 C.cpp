#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair < int , int > ii;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int mod = 1000000007;
const double eps = 1e-8;
const double pi = acos( -1.0 );

int n;
LL m;
pair <LL,LL> P[ N ];
vector < pair<LL,LL> > V;

bool cmp( pair <LL,LL> x , pair<LL,LL> y ) {
        LL a = x.first - x.second , b = y.first - y.second;
        if( a == b ) return ( x.first < y.first );
        return ( a > b );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m;
        LL tot = 0 , big = 0;
        for( int i = 1; i <= n; i++ ) {
                cin >> P[i].first >> P[i].second;
                tot += P[i].first;
                big += P[i].second;
                V.push_back( {P[i].first,P[i].second} );
        }
        if( tot <= m ) return cout << 0 << endl,0;
        if( big > m ) return cout << -1 << endl,0;
        sort( V.begin() , V.end() , cmp );
        LL taken = 0 , ans = 0;
        for( auto x : V ) {
              LL rem = tot - x.first;
              LL remcap = m - x.first;
              if( remcap < rem ) ans++ , m -= x.second , tot -= x.first;
        }
        cout << ans << endl;
        return 0;
}






