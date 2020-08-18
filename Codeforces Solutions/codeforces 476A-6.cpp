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

int n , m;
int cost[ N ];

void bfs( ) {
    memset( cost , -1 , sizeof(cost) );
    cost[0] = 0;
    queue <int> Q;
    Q.push( 0 );
    while( !Q.empty( ) ) {
        int f = Q.front();
        Q.pop();
        int op1 = f+2;
        int op2 = f+1;
        cout <<"up "<< op1 << " " << op2 << endl;
        cout <<"down "<< cost[op1] << " " << cost[op2] <<endl;
        if( op1 <= n ) {
            if( cost[op1] == -1 || cost[op1] > cost[f]+1 ){
                cost[op1] = cost[f]+1;
                Q.push( op1 );
            }
        }
        if( op2 <= n ) {
            if( cost[op2] == -1 || cost[op2] > cost[f]+1 ){
                cost[op2] = cost[f]+1;
                Q.push( op2 );
            }
        }
    }
}
int main( int argc, char const *argv[] ) {
    cin >> n >> m;
    bfs( );
    cout << cost[ n ] << endl;
    return 0;
}

