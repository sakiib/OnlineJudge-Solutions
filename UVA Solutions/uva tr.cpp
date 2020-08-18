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
vector <int> V;
LL ans[ 10*N ];

bool ok( int x , int y , int z ) {
        return ( x+y > z && z+x > y && y+z > x );
}
void brute( ) {
        for( int i = 1; i <= n; i++ ) V.push_back( i );
        int ans = 0;
        for( int i = 0; i < V.size(); i++ ) {
                for( int j = i+1; j < V.size(); j++ ) {
                        for( int k = j+1; k < V.size(); k++ ) {
                                if( ok( V[i],V[j],V[k] ) ) {
                                        ans++;
                                }
                        }
                }
        }
        cout << ans << endl;
}
void process( ) {
        ans[3] = 0 , ans[4] = 1;
        LL s = 2 , add = 2;
        for( int i = 5; i <= 1000000; i += 2 ) {
                ans[i] = ans[i-1]+add;
                add += s;
                ans[i+1] = ans[i]+add;
                s ++;
        }
        for( int i = 4; i <= 40; i++ ) cout << ans[i] << " ";
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        process( );
        while( cin >> n ) {
                if( n < 3 ) break;
                cout << ans[n] << endl;
        }
        return 0;
}






