#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

struct point {
        LL x , y;
        point(){}
        point( LL x  , LL y ) : x(x) , y(y) {}
};
vector < point > V;
vector < LL > dist;

LL Dist( int i , int j ) {
        LL d = ( V[i].x - V[j].x )*( V[i].x - V[j].x ) + ( V[i].y - V[j].y )*( V[i].y - V[j].y );
        return d;
}
int main( int argc, char const *argv[] ) {
        int n , m;
        while( cin >> n >> m ) {
                if( n == 0 && m == 0 ) break;
                for( int i = 1; i <= n; i++ ) {
                        LL a , b;
                        cin >> a >> b;
                        V.push_back( point(a,b) );
                }
                for( int i = 0; i < V.size(); i++ ) {
                        for( int j = 0; j < V.size(); j++ ) {
                                dist.push_back( Dist( i , j ) );
                        }
                }
                sort( dist.begin() , dist.end() );
                while( m-- ) {
                        LL rad;
                        cin >> rad;
                        rad *= rad;
                        int lo = 0 , hi = dist.size()-1 , ret = 0;
                        while( lo <= hi ) {
                               int mid = ( lo+hi )/2;
                               if( dist[mid] <= rad ) {
                                    ret = mid;
                                    lo = mid+1;
                               }
                               else hi = mid-1;
                        }
                        double ans = 1.0*(ret+1)/n;
                        cout << setprecision(2) << fixed << ans << endl;
                }
                cout << endl;
                V.clear() , dist.clear();
        }
        return 0;
}






