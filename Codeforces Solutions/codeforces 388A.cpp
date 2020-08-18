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
bool used[ 105 ];
int n;

struct data {
    int val , idx;
    bool operator<( const data &q ) const {
        if( val == q.val ) return idx < q.idx;
        return ( val > q.val );
    }
};
vector <data> V;

int main( int argc, char const *argv[] ) {
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        cin >> ara[i];
        V.push_back( {ara[i],i} );
    }
    sort( V.begin() , V.end() );
    for( int i = 0; i < V.size(); i++ ) {
        cout << V[i].val << " " << V[i].idx << endl;
    }
    int ans = 0;
    for( int i = 0; i < V.size(); i++ ) {
        if( !used[i] ) {
            ans ++;
            used[i] = true;
            int v = V[i].val;
            int id = V[i].idx;
            for( int j = 0; j < V.size(); j++ ) {
                if( !used[j] && ( V[j].val < v || ( V[j].val == v && V[j].idx < id))) {
                    used[j] = true;
                    id = V[j].idx;
                    v = V[i].val;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}

