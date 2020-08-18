#include <bits/stdc++.h>
using namespace std;

int a, b;

struct data {
    double val;
    int idx;
    bool operator<( const data &q ) const {
       if( val == q.val ) return ( idx < q.idx );
       return ( val > q.val );
    }
};
vector< data > V;

int main( int argc, char const *argv[] ) {
    int n , t1 , t2 , k;
    scanf("%d%d%d%d",&n,&t1,&t2,&k);
    for ( int i = 1; i <= n; i++ ) {
        scanf("%d%d",&a,&b);
        double x = 1.0*a*t1 - a*t1*1.0*k/100 + 1.0*b*t2;
        double y = 1.0*b*t1 - b*t1*1.0*k/100 + 1.0*a*t2;
        V.push_back( {max(x,y) , i} );
    }
    sort( V.begin(), V.end() );
    for ( auto x: V ) {
        printf("%d %0.2lf\n",x.idx,x.val);
    }
    return 0;
}
