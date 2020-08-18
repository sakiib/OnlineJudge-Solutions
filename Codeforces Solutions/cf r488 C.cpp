#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long LL;
const double eps = 1e-9;
const double pi = acos( -1.0 );

#define ii pair < int , int >
#define iii pair < ii , int >
#define ff first
#define ss second
#define SQ(x) (x*x)
#define Fix( x ) setprecision( x ) << fixed

bool EqualTo( double a , double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool NotEqual( double a , double b ){ if ( fabs ( a - b ) > eps ) return true; else return false; }
bool LessThan( double a , double b ){ if ( a + eps < b ) return true; else return false; }
bool LessThanEqual( double a , double b ){ if ( a < b + eps ) return true;   else return false; }
bool GreaterThan( double a , double b ){ if ( a > b + eps ) return true; else return false; }
bool GreaterThanEqual( double a , double b ){ if ( a + eps > b ) return true; else return false; }


struct point {
    int x , y;
    point( ) { }
    point( int _x , int _y ) { x = _x , y = _y; }
    bool operator <( const point &q ) const {
        if( x == q.x ) return ( y < q.y );
        return ( x < q.x );
    }
    point operator + ( const point p ) { return point( x + p.x , y + p.y ); }
    point operator - ( const point p ) { return point( x - p.x , y - p.y ); }
    point operator * ( int k ) { return point( x * k , y * k ); }
    point operator / ( int k ) { return point( x / k , y / k ); }

    void in( point &p ) { cin >> p.x >> p.y , p.x += 100 , p.y += 100; }
    void print( point p )  { cerr << setprecision(0) << fixed <<"( "<< p.x << " , " << p.y <<" )"<< endl; }

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
        int ret = ( Q.y - P.y ) * ( R.x - Q.x ) - ( Q.x - P.x ) * ( R.y - Q.y );
        if ( ret > 0 ) return 1; ///Polar angle of (Q - R) is smaller than (P - Q) with respect to x axis.
        if ( ret < 0 ) return 2; ///Polar angle of (Q - R) is greater than (P - Q) with respect to x axis.
        return 0;
    }
    bool CoLinear( point a , point b , point c ) { return ( Orientation( a , b , c ) == 0 ); }
    double PolygonArea( vector < point > poly ) {
        double area = 0;
        int l = poly.size( );
        for ( int i = 1; i + 1 < l; i++ )
        area += ( poly[i].y-poly[0].y)*(poly[i+1].x-poly[i].x)-(poly[i].x-poly[0].x)*(poly[i+1].y-poly[i].y );
        return fabs( area / 2.0 );
    }
} P;

/// must include point template..

struct Line {

    /// Returns A,B,C of the Line equation Ax + By = C joining points p & q
    iii LineEqn( point p , point q ) {
        int a = q.y - p.y , b = p.x - q.x , c = a * p.x + b * p.y;
        return make_pair( make_pair( a,b ) , c );
    }
    /// Find minimum distance between point C and line or segment ( A - B ) given end point
    double PointToLineDist( point a , point b , point c , bool seg ) {
        double d = P.crossABC( a , b , c ) / a.dist( b );
        if( seg ) {
            if( P.dotABC( a , b , c ) > 0.0 ) return ( b.dist( c ) );
            if( P.dotABC( b , a , c ) > 0.0 ) return ( a.dist( c ) );
        }
        return fabs( d );
    }
    /// Point to Line distance given a point ( p ) & ( A , B , C ) of Line Ax+By+C = 0
    double PointLineDist( point p , double a , double b , double c ) {
        double u = fabs( a*p.x + b*p.y + c ) / ( sqrt( a*a + b*b ) );
        return u;
    }
    /// Check if point R lies on line segment ( P - Q )
    bool OnSegment( point P , point Q , point R ) {
        if ( R.x >= min( P.x , Q.x ) && R.x <= max( P.x , Q.x ) && R.y >= min( P.y , Q.y ) && R.y <= max( P.y , Q.y ) ) {
            return true;
        }
        else return false;
    }
    /// Check if line segment ( P1-P2 ) and line segment ( P3-P4 ) intersect or not
    bool SegmentIntersect( point P1 , point P2 , point P3 , point P4 ) {
        int o1 = P.Orientation( P1 , P2 , P3 ); int o2 = P.Orientation( P1 , P2 , P4 );
        int o3 = P.Orientation( P3 , P4 , P1 ); int o4 = P.Orientation( P3 , P4 , P2 );
        if ( o1 != o2 && o3 != o4 && o1 != 0 && o2 != 0 && o3 != 0 && o4 != 0 ) return true;
        if ( o1 == 0 && OnSegment( P1 , P2 , P3 ) ) return true; if ( o2 == 0 && OnSegment( P1 , P2 , P4 ) ) return true;
        if ( o3 == 0 && OnSegment( P3 , P4 , P1 ) ) return true; if ( o4 == 0 && OnSegment( P3 , P4 , P2 ) ) return true;
        return false;
    }
    /// Find Intersection point of line ( P1-P2 ) and (P3-P4)
    void IntersectionPoint( point P1 , point P2 , point P3 , point P4 ) {
        iii L1 = LineEqn( P1 , P2 );
        int A1 = L1.ff.ff , B1 = L1.ff.ss , C1 = L1.ss;
        iii L2 = LineEqn( P3 , P4 );
        int A2 = L2.ff.ff , B2 = L2.ff.ss , C2 = L2.ss;
        int dif = A1 * B2 - A2 * B1; /// Slope difference of the two lines
        if( dif == 0 ) {
            /// /// Lines are either collinear or parallel.
            vector < point > List;
            List.push_back( P1 ); List.push_back( P3 ); List.push_back( P4 ); List.push_back( P2 );
            if ( P.PolygonArea( List ) == 0 ) printf("Collinear\n");
            else printf("Parallel\n");
        }
        else {
            double x = ( B2 * C1 - B1 * C2 ) / dif; double y = ( A1 * C2 - A2 * C1 ) / dif;
            cerr << setprecision(10) << fixed << x << " " << y << endl; /// Return if needed.
        }
    }
    /// Find a point C on line AB such that distance from A to C is D.
    point pointAtDistanceD( point A , point B , double D ){
        point vecAB , C;
        vecAB.x = B.x - A.x;  vecAB.y = B.y - A.y;
        double norm = sqrt( SQ( vecAB.x ) + SQ( vecAB.y ) );
        vecAB.x /= norm;  vecAB.y /= norm;
        /// To find a point D distance away but outside the line then minus here.
        C.x = A.x + D*vecAB.x;  C.y = A.y + D*vecAB.y;
        return C;
    }
} L;



point a , b , c , d;
point p , q , r , s;

double area(int x1, int y1, int x2, int y2,int x3, int y3)
{
    return abs( (double)(x1 * (y2 - y3) + x2 * (y3 - y1) +x3 * (y1 - y2)) / 2.0);
}
bool check(int x1, int y1, int x2, int y2, int x3,int y3, int x4, int y4, int x, int y)
{
    double A = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3);

    /* Calculate area of triangle PAB */
    double A1 = area(x, y, x1, y1, x2, y2);

    /* Calculate area of triangle PBC */
    double A2 = area(x, y, x2, y2, x3, y3);

    /* Calculate area of triangle PCD */
    double A3 = area(x, y, x3, y3, x4, y4);

    /* Calculate area of triangle PAD */
    double A4 = area(x, y, x1, y1, x4, y4);

    /* Check if sum of A1, A2, A3 and A4
       is same as A */
    return ( EqualTo( A , A1+A2+A3+A4 ) );
    //return (A == A1 + A2 + A3 + A4);
}
bool inside( ) {
    if( check( a.x , a.y , b.x , b.y , c.x , c.y , d.x , d.y , p.x , p.y ) ) return true;
    if( check( a.x , a.y , b.x , b.y , c.x , c.y , d.x , d.y , q.x , q.y ) ) return true;
    if( check( a.x , a.y , b.x , b.y , c.x , c.y , d.x , d.y , r.x , r.y ) ) return true;
    if( check( a.x , a.y , b.x , b.y , c.x , c.y , d.x , d.y , s.x , s.y ) ) return true;
    if( L.OnSegment( a , b , p ) ) return true;
    if( L.OnSegment( a , b , q ) ) return true;
    if( L.OnSegment( a , b , r ) ) return true;
    if( L.OnSegment( a , b , s ) ) return true;

    if( L.OnSegment( b , c , p ) ) return true;
    if( L.OnSegment( b , c , q ) ) return true;
    if( L.OnSegment( b , c , r ) ) return true;
    if( L.OnSegment( b , c , s ) ) return true;

    if( L.OnSegment( c , d , p ) ) return true;
    if( L.OnSegment( c , d , q ) ) return true;
    if( L.OnSegment( c , d , r ) ) return true;
    if( L.OnSegment( c , d , s ) ) return true;

    if( L.OnSegment( a , d , p ) ) return true;
    if( L.OnSegment( a , d , q ) ) return true;
    if( L.OnSegment( a , d , r ) ) return true;
    if( L.OnSegment( a , d , s ) ) return true;
    return false;
}
#define pb push_back
vector < point > V;

int main( int argc, char const *argv[] ) {

    P.in( a ) , P.in( b ) , P.in( c ) , P.in( d );
    V.pb( a ) , V.pb( b ) , V.pb( c ) , V.pb( d );
    sort( V.begin() , V.end() );
    a = V[0] , b = V[1] , c = V[2] , d = V[3];
    V.clear();

    P.in( p ) , P.in( q ) , P.in( r ) , P.in( s );
    V.pb( p ) , V.pb( q ) , V.pb( r ) , V.pb( s );
    sort( V.begin() , V.end() );
    p = V[0] , q = V[1] , r = V[2] , s = V[3];
    V.clear();


    if( inside( ) ) return cout << "YES" << endl,0;
    int f = 0;
    f |= L.SegmentIntersect( a , b , p , q );
    f |= L.SegmentIntersect( a , b , q , r );
    f |= L.SegmentIntersect( a , b , r , s );
    f |= L.SegmentIntersect( a , b , p , s );

    f |= L.SegmentIntersect( b , c , p , q );
    f |= L.SegmentIntersect( b , c , q , r );
    f |= L.SegmentIntersect( b , c , r , s );
    f |= L.SegmentIntersect( b , c , p , s );

    f |= L.SegmentIntersect( c , d , p , q );
    f |= L.SegmentIntersect( c , d , q , r );
    f |= L.SegmentIntersect( c , d , r , s );
    f |= L.SegmentIntersect( c , d , p , s );

    f |= L.SegmentIntersect( a , d , p , q );
    f |= L.SegmentIntersect( a , d , q , r );
    f |= L.SegmentIntersect( a , d , r , s );
    f |= L.SegmentIntersect( a , d , p , s );
    if( f ) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
