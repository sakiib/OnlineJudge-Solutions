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

int n , m;
LL one;
int cnt[ N ];

bool f = true;
vector <int> big;
vector <LL> V[ N ];
vector < pair<LL,LL> > C;
int ara[ N ];
int id = 0;

multiset <int> S;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> m;
        for( int i = 1; i <= n; i++ ) {
                int p;
                LL taka;
                cin >> p >> taka;
                cnt[ p ]++;
                V[p].push_back( taka );
        }
        for( int i = 2; i <= m; i++ ) {
                if( cnt[i] >= cnt[1] ) {
                        f = false;
                        big.push_back( i );
                        for( auto x : V[i] ) {
                                C.push_back( {x,i} );
                        }
                        S.insert( cnt[i] );
                }
        }
        if( f ) return cout << 0 << endl,0;
        LL cost = 0;
        sort( C.begin() , C.end() );
        LL now = cnt[1];
        for( auto x : C ) {
                auto it = S.end();
                --it;
                if( *it < now ) break;
                cost += x.first;
                now++;
                int del = cnt[ x.second ];
                int in = del-1;
                cnt[ x.second ]--;
                S.erase( S.find(del) );
                S.insert( in );
        }
        cout << cost << endl;
        return 0;
}






