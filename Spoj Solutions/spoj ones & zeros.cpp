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

bool visited[ N ];

string bfs( int n ) {
    memset( visited , false , sizeof( visited ) );
    queue<pair<int,string> > Q;
    Q.push( {1 , "1"} );
    while( !Q.empty() ) {
        pair<int,string> p = Q.front();
        int val = p.first;
        string res = p.second;
        if( val%n == 0 ) return res;
        val %= n;
        visited[ val ] = true;
        Q.pop();
        int op1 = (10%n*val%n+1%n)%n;
        int op2 = (10%n*val%n)%n;
        if( !visited[ op2 ] ) {
            Q.push( {op2,res+"0"} );
        }
        if( !visited[ op1 ] ) {
            Q.push( {op1,res+"1"} );
        }
    }
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
        int n;
        scanf("%d",&n);
        cout << bfs( n ) <<endl;
    }
    return 0;
}

