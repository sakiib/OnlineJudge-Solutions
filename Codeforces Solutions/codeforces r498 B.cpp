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

int n , k;
int a[ N ];
vector <int> V;
LL ans;
multiset < int > S;
vector <int> an;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k;
        for( int i = 1; i <= n; i++ ) {
                cin >> a[i];
                V.push_back( a[i] );
        }
        sort( V.rbegin() , V.rend() );
        for( int i = 0; i < k; i++ ) ans += V[i] , S.insert( V[i] );
        cout << ans << endl;
        int id = 0;
        int cnt = 0;
        for( int i = 1; i <= n; i++ ) {
                if( S.find( a[i] ) != S.end() ) {
                        S.erase( S.find(a[i]) );
                        cnt++;
                        an.push_back( cnt );
                        cnt = 0;
                        id = i;
                }
                else cnt++;
        }
        if( id != n ) an[k-1] += ( n-id );
        for( auto x : an ) cout << x << " ";
        return 0;
}






