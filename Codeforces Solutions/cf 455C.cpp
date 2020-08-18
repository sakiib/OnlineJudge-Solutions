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

int a[ 100 ] , b[ 100 ];
stack <int> p , q;
int cnt = 0;
void dfs( int s ) {
    if( cnt > 1000000 ) return;
    if( p.empty() || q.empty() ) return;
    cnt ++;
    int x = s;
    int y = q.top();
    if( x > y ) p.push( y ) , q.pop();
    else q.push( x ) , p.pop();
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    int x;
    cin >> x;
    for( int i = 1; i <= x; i++ ) {
        cin >> a[i];
    }
    for( int i = x; i >= 1; i-- ) {
        p.push( a[i] );
    }
    int y;
    cin >> y;
    for( int i = 1; i <= y; i++ ) {
        cin >> b[i];
    }
    for( int i = y; i >= 1; i-- ) {
        q.push( b[i] );
    }
    int v = p.top();
    dfs( p.top() );
    if( p.size() == q.size() ) cout << -1 << endl;
    else cout << p.size() <<" " << q.size() <<endl;
    return 0;
}

