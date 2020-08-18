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

vector <int> V;
LL ans[ 10*N+5 ];

bool ok( int x , int y , int z ) {
    return ( x+y > z && y+z > x && z+x > y );
}
void Bruteforce( ) {
    for( int i = 1; i <= 10; i++ ) {
        V.push_back( i );
    }
    int cnt = 0;
    for( int i = 0; i < V.size(); i++ ) {
        for( int j = i+1; j < V.size(); j++ ) {
            for( int k = j+1; k < V.size(); k++ ) {
                if( ok( V[i] , V[j] , V[k] ) ) cnt++;
            }
        }
    }
    cout << "Tot : " << cnt << endl;
}
void calc( ) {
    ans[4] = 1LL , ans[5] = 3LL;
    LL add = 2 , prev = 2 , times = 0;
    for( int i = 6; i <= 10*N; i++ ) {
        add = add+prev;
        times++;
        ans[i] = ans[i-1]+add;
        if( times == 2 ) {
            times = 0 , prev++;
        }
    }
    //for( int i = 1; i <= 20; i++ ) cout << ans[i] << " ";
}
int main( int argc, char const *argv[] ) {
    // Bruteforce( );
    calc( );
    LL n;
    while( scanf("%lld",&n) ) {
        if(n < 3 ) break;
        printf("%lld\n",ans[n] );
    }
    return 0;
}

