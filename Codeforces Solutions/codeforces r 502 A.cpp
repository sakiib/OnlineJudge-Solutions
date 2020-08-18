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

struct data {
        int tot,id;
        data(){}
        data( int _tot , int _id ) {
                tot = _tot , id = _id;
        }
        bool operator <( const data &q )const {
                if( tot == q.tot ) return id < q.id;
                return tot > q.tot;
        }
};
vector <data> V;

int main( int argc , char const *argv[] ) {
        ios_base :: sync_with_stdio(false); cin.tie(NULL);
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ ) {
                int a , b , c , d;
                cin >> a >> b >> c >> d;
                V.push_back( {a+b+c+d,i} );
        }
        sort( V.begin() , V.end() );
        for( int i = 0; i < V.size(); i++ ) if( V[i].id == 1 ) return cout <<i+1 << endl,0;
        return 0;
}






