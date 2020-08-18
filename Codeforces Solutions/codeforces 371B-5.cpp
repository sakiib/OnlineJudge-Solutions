#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
typedef unsigned long long uLL;
typedef pair< int,int > ii;
typedef pair< int,ii > iii;
const int inf = 1e9;
const LL INF = 1e18;
const int N1 = 100005;
const int MOD = 1e9+7;
const double EPS = 1e-6;
const double PI = acos(-1.0);

map < LL,LL > M , N;

int main( int argc, char const *argv[] ) {
    LL a , b;
    scanf("%lld%lld",&a,&b);
    vector <int> V = { 2 , 3 , 5 };
    for( int i = 0; i < V.size(); i++ ) {
        while( a%V[i] == 0 ) {
            a /= V[i];
            M[ V[i] ]++;
        }
    }
    for( int i = 0; i < V.size(); i++ ) {
        while( b%V[i] == 0 ) {
            b /= V[i];
            N[ V[i] ]++;
        }
    }
    if( (a > 1 || b > 1) && a != b ) {
        printf("-1\n");
        return 0;
    }
    LL ans = 0;
    for( int i = 0; i < V.size(); i++ ) {
        ans += abs( M[ V[i] ] -N[ V[i] ] );
    }
    printf("%lld\n",ans);
    return 0;
}

