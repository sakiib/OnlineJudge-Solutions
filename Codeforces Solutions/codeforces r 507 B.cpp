#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int inf = 1e9;
const LL INF = 1e18;
const int N = 1e5 + 5;
const int MOD = 1000000007;

int n , k;
vector <int> ans;
bool done[ N ];

bool ok( int pos ) {
        int upto = pos + k;
        int rem = n - upto;
        //cout << "pos : " << pos << " " << rem << endl;
        return ( rem >= k+1 || rem <= 0 );
}
int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> k;
        if( k == 0 ) {
                cout << n << endl;
                for( int i = 1; i <= n; i++ ) cout << i << " ";
                return 0;
        }
        int i = 1;
        while( i <= n ) {
                //out << i <<" "<<ok(i) << endl;
                if( ok( i ) ) {
                        //cout << "in : "<< i << endl;
                        ans.push_back( i );
                        //for( int j = 1;j <= k; j++ ) done[i+j] = true;
                        i += ( k + 1 );
                        for( int j = 1; j <= k; j++ ) i++;
                }
                else i++;
        }
        cout << ans.size() << endl;
        for( auto x : ans ) cout << x << " ";
        return 0;
}






