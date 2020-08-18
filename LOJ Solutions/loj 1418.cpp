#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long LL;
const double eps = 1e-8;
const double pi = acos( -1.0 );

#define ii pair < int , int >
#define iii pair < ii , int >
#define ff first
#define ss second
#define SQ(x) (x*x)
#define Fix( x ) setprecision( x ) << fixed

bool EqualTo( double a , double b ) { return ( fabs ( a - b ) <= eps ); }
bool NotEqual( double a , double b ) { return ( fabs ( a - b ) > eps ); }
bool LessThan( double a , double b ) { return ( a + eps < b ); }
bool LessThanEqual( double a , double b ) { return ( a < b + eps ); }
bool GreaterThan( double a , double b ) { return ( a > b + eps ); }
bool GreaterThanEqual( double a , double b ) { return ( a + eps > b ); }


struct point {
    LL x , y;
    point( ) { }
    point( LL _x , LL _y ) { x = _x , y = _y; }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( double k ) { return point( x * k , y * k ); }
    point operator / ( double k ) { return point( x / k , y / k ); }

    void in( point &p ) { cin >> p.x >> p.y; }
    void print( point p )  { cerr << setprecision(5) << fixed <<"( "<< p.x << " , " << p.y <<" )"<< endl; }

    double dot( const point p ) { return ( x * p.x + y * p.y ); }
    double cross( const point p ) { return ( x * p.y - y * p.x ); }

    double dist( const point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
    double sqdist( const point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }

    /// angle between two vectors
    double Angle( point A , point B ) {
        double ans = fabs( ( atan2( A.y , A.x ) - atan2( B.y , B.x ) ) );
        return ans > pi+eps ? 2*pi-ans : ans;
    }
    /// angle from +ve X axis
    double AngleFromAxis( point P ) {
        double ang = atan2( P.y , P.x ); if( ang+eps < 0.0 ) ang += 2.0*pi; return ang;
    }
    /// dot product of AB & BC ( AB vector , BC vector )
    double dotABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point BC = point( C.x - B.x , C.y - B.y );
        return AB.dot( BC );
    }
    /// cross product of AB & BC ( AB vector , BC vector )
    double crossABC( point A , point B , point C ) {
        point AB = point( B.x - A.x , B.y - A.y ); point AC = point( C.x - A.x , C.y - A.y );
        return AB.cross( AC );
    }
    /// 0 = Collinear, 1 = Clockwise, 2 = Counterclockwise.
    int Orientation( point P , point Q , point R ) {
        LL ret = ( Q.y - P.y ) * ( R.x - Q.x ) - ( Q.x - P.x ) * ( R.y - Q.y );
        if ( ret > 0 ) return 1; ///Polar angle of (Q - R) is smaller than (P - Q) with respect to x axis.
        if ( ret < 0 ) return 2; ///Polar angle of (Q - R) is greater than (P - Q) with respect to x axis.
        return 0;
    }
    bool CoLinear( point a , point b , point c ) { return ( Orientation( a , b , c ) == 0 ); }
    LL PolygonArea( vector < point > poly ) {
        LL area = 0;
        int l = poly.size( );
        for ( int i = 1; i + 1 < l; i++ )
        area += ( poly[i].y-poly[0].y)*(poly[i+1].x-poly[i].x)-(poly[i].x-poly[0].x)*(poly[i+1].y-poly[i].y );
        return abs( area );
    }
} P;

vector < point > V;

int main( int argc, char const *argv[] ) {
        int t;
        cin >> t;
        for( int tc = 1; tc <= t; tc++ ) {
                int n;
                cin >> n;
                for( int i = 1; i <= n; i++ ) {
                        point a;
                        P.in( a );
                        V.push_back( a );
                }
                int a = P.PolygonArea( V );
                cout << a << endl;
                a += 1.0;
                int ans = (int)a*2 - n;
                cout << ans/2 << endl;
        }
        return 0;
}









