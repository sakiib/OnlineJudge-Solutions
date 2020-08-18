#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 1e5 + 5;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int MOD = 1000000007;

bool EqualTo( double a , double b ) { return ( fabs ( a - b ) <= eps ); }
bool NotEqual( double a , double b ) { return ( fabs ( a - b ) > eps ); }
bool LessThan( double a , double b ) { return ( a + eps < b ); }
bool LessThanEqual( double a , double b ) { return ( a < b + eps ); }
bool GreaterThan( double a , double b ) { return ( a > b + eps ); }
bool GreaterThanEqual( double a , double b ) { return ( a + eps > b ); }

struct Point {
        double x , y;
        Point( ) {}
        Point( double x , double y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) { return Point ( x + p.x, y + p.y ); }
        Point operator - ( Point p ) { return Point ( x - p.x, y - p.y ); }
        Point operator * ( double k ) { return Point( x * k , y * k ); }
        Point operator / ( double k ) { return Point( x / k , y / k ); }
        double dot( const Point p ) { return ( x * p.x + y * p.y ); }
        double cross( const Point p ) { return ( x * p.y - y * p.x ); }
        double dist( const Point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
        double sqdist( const Point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;


struct lineSegment {
        Point A , B; /// two endpoints of the line
        lineSegment( ) {}
        lineSegment( Point A , Point B ) : A( A ) , B( B ) {}
        lineSegment( double ax , double ay , double bx , double by ) {
                Point A = Point( ax , ay );
                Point B = Point( bx , by );
        }
} L;

int Orientation( Point st , Point mid , Point ed ) {
        double v = ( ed - st ).cross( mid - st );
        if( EqualTo( v , 0.0 ) ) return 0; /// co-linear
        return GreaterThan( v , 0.0 ) ? 1 : -1; /// acw , cw
}
/// check if two line segment intersects or not.
bool lineIntersect( lineSegment p , lineSegment q ) {
        if( Orientation( p.A , p.B , q.A ) == - Orientation( p.A , p.B , q.B )
         && Orientation( q.A , q.B , p.A ) == - Orientation( q.A , q.B , p.B ) ) return true;
        else return false;
}
double PolygonArea( vector <Point> poly ) {
        double area = 0.0;
        for ( int i = 1; i + 1 < poly.size(); i++ )
        area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
              - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
        return fabs( area / 2.0 );
}

vector <Point> poly;
Point X , Y;

bool check( Point p ) {
        double tot = PolygonArea( poly );
        double small = 0.0;
        for( int i = 0; i < poly.size(); i++ ) {
                vector <Point> temp = { p , poly[i] , poly[(i+1)%4] };
                small += PolygonArea( temp );
        }
        if( EqualTo( small , tot ) ) return true;
        return false;
}
int main( int argc , char const *argv[] ) {
        ios_base::sync_with_stdio( false ); cin.tie( NULL );
        freopen( "input.txt" , "r" ,stdin );
        freopen( "output.txt" , "w" , stdout );
        int t;
        cin >> t;
        while( t-- ) {
                Point p , q;
                cin >> p.x >> p.y >> q.x >> q.y;
                X = p , Y = q;

                lineSegment l = lineSegment( p , q );
                poly.clear();
                cin >> p.x >> p.y;
                cin >> q.x >> q.y;

                if( p.x > q.x ) swap( p.x , q.x );
                if( p.y < q.y ) swap( p.y , q.y );

                Point r = Point( p.x , q.y );
                Point s = Point( q.x , p.y );

                poly.push_back( p );
                poly.push_back( s );
                poly.push_back( q );
                poly.push_back( r );

                bool f = false;
                f |= lineIntersect( l , lineSegment( p , s ) );
                f |= lineIntersect( l , lineSegment( p , r ) );
                f |= lineIntersect( l , lineSegment( q , s ) );
                f |= lineIntersect( l , lineSegment( q , r ) );
                f |= check( X );
                f |= check( Y );
                if( f ) cout << "T" << endl;
                else cout << "F" << endl;
        }
        return 0;
}











