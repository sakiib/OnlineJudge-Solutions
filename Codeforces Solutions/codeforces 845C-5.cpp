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

LL L[ 2*N ] , R[ 2*N ];
vector <LL> V;
map <LL,LL> M;

int main( int argc, char const *argv[] ) {
    int n;
    scanf("%d",&n);
    for( int i = 1; i <= n; i++ ) {
        scanf("%lld%lld",&L[i],&R[i]);
        V.push_back( L[i] ) , V.push_back( R[i] );
    }
    sort( V.begin() , V.end() );
    V.erase( unique( V.begin(),V.end()),V.end());
    for( int i = 0; i < V.size(); i++ ) {
        M[ V[i] ] = i+1;
    }
    for( int i = 1; i <= n; i++ ) {
        L[i] = M[ L[i] ] , R[i] = M[ R[i] ];
    }
    LL lim = V.size()+5;
    vector <LL> cum( lim , 0 );
    for( int i = 1; i <= n; i++ ) {
        cum[ L[i] ]++ , cum[ R[i]+1 ]--;
    }
    for( int i = 1; i <= lim; i++ ) {
        cum[i] += cum[i-1];
    }
    for( int i = 1; i <= lim; i++ ) {
        if( cum[i] > 2 ) {
            puts("NO") ; return 0;
        }
    }
    puts("YES");
    return 0;
}

