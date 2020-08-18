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

int n , a , b;

int solve( int k , int x , int y ) {
    if( x < 0 || y < 0 || k < 0 ) return inf;
    if( x == 0 && y == 0 ) return 0;
    int A = solve( n-a , x-a , y )+1;
    int B = solve( n-b , x , y-b )+1;
    int C = solve( k-a , x-a , y );
    int D = solve( k-b , x , y-b );
    return min( A , min( B , min( C , D ) ) );
}
int main( int argc, char const *argv[] ) {
    cin >> n >> a >> b;
    cout << solve( n , a*4 , b*2 )+1 <<endl;
    return 0;
}


