#include <bits/stdc++.h>
using namespace std;

#define ii pair < int , int >
#define iii pair< ii , int >
#define ff first
#define ss second
#define SQ(x) (x*x)

typedef long double ld;
typedef long long LL;
const double eps = 1e-8;
const double pi = acos( -1.0 );

struct point {
    double x , y;
    point( ) { }
    point( double _x , double _y ) { x = _x , y = _y; }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( double k ) { return point( x * k , y * k ); }
    point operator / ( double k ) { return point( x / k , y / k ); }

    double dot( const point p ) { return ( x * p.x + y * p.y ); }
    double cross( const point p ) { return ( x * p.y - y * p.x ); }

    double dist( const point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
    double sqdist( const point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }

    double Angle( point A , point B ) {
        double ans = fabs( ( atan2( A.y , A.x ) - atan2( B.y , B.x ) ) );
        return ans > pi+eps ? 2*pi-ans : ans;
    }
    double AngleFromAxis( point P ) {
        double ang = atan2( P.y , P.x ); if( ang+eps < 0.0 ) ang += 2.0*pi; return ang;
    }
    double dotABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point BC = point( C.x - B.x , C.y - B.y );
        return AB.dot( BC );
    }
    double crossABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point AC = point( C.x - A.x , C.y - A.y );
        return AB.cross( AC );
    }
    int Orientation( point P , point Q , point R ) {
        LL ret = ( Q.y - P.y ) * ( R.x - Q.x ) - ( Q.x - P.x ) * ( R.y - Q.y );
        if ( ret > 0 ) return 1;
        if ( ret < 0 ) return 2;
        return 0;
    }
    bool CoLinear( point a , point b , point c ) { return ( Orientation( a , b , c ) == 0 ); }
    double PolygonArea( vector< point > poly ) {
        double area = 0;
        for ( int i = 1; i + 1 < poly.size(); i++ ) {
             area += ( poly[ i ].y - poly[ 0 ].y ) * ( poly[ i+1 ].x - poly[ i ].x ) -
                     ( poly[ i ].x - poly[ 0 ].x ) * ( poly[ i+1 ].y - poly[ i ].y );
        }
        return fabs( area / 2.0 );
    }
} P;

vector < point > V;

void solve( ) {
    point a = V[0];
    point b = V[1];
    vector < point > temp;
    for( int i = 2; i < V.size(); i++ ) {
        if( !P.CoLinear( a , b , V[i] ) ) temp.push_back( V[i] );
    }
    if( temp.size() < 3 ) {
        cout << "YES" << endl;
        exit(0);
    }
    a = temp[0] , b = temp[1];
    bool f = true;
    for( int i = 2; i < temp.size(); i++ ) {
        if( !P.CoLinear( a , b , temp[i] ) ) {
            f = false; break;
        }
    }
    if( f ) {
        cout << "YES" << endl;
        exit(0);
    }

    temp.clear( );
    a = V[0] , b = V[2];
    for( int i = 0; i < V.size(); i++ ) {
        if( i == 0 || i == 2 ) continue;
        if( !P.CoLinear( a , b , V[i] ) ) temp.push_back( V[i] );
    }
    if( temp.size() < 3 ) {
        cout << "YES" << endl;
        exit(0);
    }
    a = temp[0] , b = temp[1];
    f = true;
    for( int i = 2; i < temp.size(); i++ ) {
        if( !P.CoLinear( a , b , temp[i] )  ) {
            f = false; break;
        }
    }
    if( f ) {
        cout << "YES" << endl;
        exit(0);
    }

    temp.clear( );

    a = V[1] , b = V[2];
    for( int i = 0; i < V.size(); i++ ) {
        if( i == 1 || i == 2 ) continue;
        if( !P.CoLinear( a , b , V[i] ) ) temp.push_back( V[i] );
    }
    if( temp.size() < 3 ) {
        cout << "YES" << endl;
        exit(0);
    }
    a = temp[0] , b = temp[1];
    f = true;
    for( int i = 2; i < temp.size(); i++ ) {
        if( !P.CoLinear( a , b , temp[i] ) ) {
            f = false; break;
        }
    }
    if( f ) {
        cout << "YES" << endl;
        exit(0);
    }
    cout << "NO" << endl;
}
int main( int argc, char const *argv[] ) {
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) {
        double a , b;
        cin >> a >> b;
        V.push_back( point(a,b) );
    }
    if( n <= 4 ) return cout << "YES" << endl,0;
    solve( );
    return 0;
}






