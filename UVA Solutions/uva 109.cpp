#include <bits/stdc++.h>
using namespace std;

#define trace(...) __f( #__VA_ARGS__ , __VA_ARGS__ )
template <typename Arg1>
void __f( const char* name , Arg1&& arg1 ) {
        cerr << name << " : " << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void __f( const char* na , Arg1&& arg1 , Args&&... args ) {
        const char* c = strchr( na + 1 , ',' );
        cerr.write( na , c - na ) << " : " << arg1 << " , ";
        __f( c + 1 , args... );
}
#define endl "\n"
#define all(V) V.begin(),V.end()
#define Unique(V) sort(all(V)),V.erase(unique(all(V)),V.end())
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int LL;
typedef pair <int,int> pii;
const int MOD = 1e9 + 7;
const int inf = 1e5;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

struct point {
        double x, y;
        point( ) {}
        point( double x , double y ) : x( x ), y( y ) {}
        void operator = ( const point &p ) { x = p.x, y = p.y; }
        bool operator < ( const point &p ) { return x == p.x ? y < p.y : x < p.x; }
        point operator + ( point p ) { return point ( x + p.x, y + p.y ); }
        point operator - ( point p ) { return point ( x - p.x, y - p.y ); }
        point operator * ( double k ) { return point( x * k , y * k ); }
        point operator / ( double k ) { return point( x / k , y / k ); }
        double cross( const point &p ) const { return x * p.y - y * p.x; }
        double dot( const point &p ) const { return x * p.x + y * p.y; }
        double dist( point q ){ return ( ( x - q.x ) * ( x - q.x ) + ( y - q.y ) * ( y - q.y ) ); }
        double PolygonArea( vector <point> &poly ) {
                double area = 0.0;
                if( poly.size() < 3 ) return 0;
                for ( int i = 1; i + 1 < poly.size(); i++ )
                area += ( poly[i].y - poly[0].y ) * ( poly[i+1].x - poly[i].x )
                      - ( poly[i].x - poly[0].x ) * ( poly[i+1].y - poly[i].y );
                return abs( area ) / 2.0;
        }
} P;

bool comp( point &p1, point &p2 ) { return p1.x != p2.x ? p1.x < p2.x : p1.y < p2.y; }

bool cw( point &a, point &b, point &c ) {
        return ( a.x * ( b.y - c.y ) + b.x * ( c.y - a.y ) + c.x * ( a.y - b.y ) ) < 0;
}
bool ccw( point &a, point &b, point &c ) {
        return ( a.x * ( b.y - c.y ) + b.x * ( c.y - a.y ) + c.x * ( a.y - b.y ) ) > 0;
}
vector <point> convex_hull( vector<point> &v ) {
        if( v.size() == 1 ) return v;
        sort( v.begin(), v.end() );
        point p1 = v[0], p2 = v.back();
        vector <point> up , down;
        up.push_back( p1 ) , down.push_back( p1 );
        for( int i = 1; i < v.size(); i++ ) {
                if( i == v.size() - 1 || cw( p1, v[i], p2 ) ) {
                        while( up.size() >= 2 && !cw( up[up.size()-2], up[up.size()-1], v[i] ) )
                                up.pop_back();
                                up.push_back( v[i] );
                }
                if( i == v.size() - 1 || ccw( p1, v[i], p2 ) ) {
                        while( down.size() >= 2 && !ccw( down[down.size()-2], down[down.size()-1], v[i] ) )
                                down.pop_back();
                                down.push_back( v[i] );
                }
        }
        for( int i = down.size()-2; i > 0; i-- ) up.push_back( down[i] );
        return up;
}

struct lineSegment {
        point A , B;
        lineSegment( ) {}
        lineSegment( point A , point B ) : A( A ) , B( B ) {}
        lineSegment( LL ax , LL ay , LL bx , LL by ) {
                point A = point( ax , ay );
                point B = point( bx , by );
        }
} L;
LL Orientation( point st , point mid , point ed ) {
        LL v = ( ed - st ).cross( mid - st );
        if( !v ) return 0;
        return v > 0 ? 1 : -1;
}
bool coLinear( point a , point b , point c ) {
        LL ori = Orientation( a , b , c );
        return ori == 0;
}
bool onSegment( point p , lineSegment l ) {
        if( coLinear( l.A , l.B , p ) ) {
                point r = l.A , s = l.B;
                return ( 1LL * ( p.x - r.x ) * ( p.x - s.x ) <= 0 &&
                         1LL * ( p.y - r.y ) * ( p.y - s.y ) <= 0 );
        }
        else return false;
}
bool lineIntersect( lineSegment p , lineSegment q ) {
        if( Orientation( p.A , p.B , q.A ) == - Orientation( p.A , p.B , q.B )
         && Orientation( q.A , q.B , p.A ) == - Orientation( q.A , q.B , p.B ) ) return true;
        else return false;
}
LL RayShoot( vector <lineSegment> V , point A , point B ) {
        LL cnt = 0;
        lineSegment Q = lineSegment( A , B );
        for( int i = 0; i < V.size(); i++ ) {
                lineSegment P = V[i];
                if( onSegment( A , P ) ) return 1;
                cnt += lineIntersect( P , Q ) ? 1 : 0;
        }
        return cnt;
}
bool destroyed[ N ];
vector < vector <point> > hull[ N ];

int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int n;
        int idx = 0;
        while( cin >> n ) {
                if( n == -1 ) break;
                vector <point> V;
                for( int i = 1; i <= n; i++ ) {
                        double x , y;
                        cin >> x >> y;
                        V.push_back( point( x , y ) );
                }
                vector <point> p = convex_hull( V );
                hull[++idx].push_back( p );
        }
        for( auto it : hull[1][0] ) trace( it.x , it.y );
        point p;
        double ans = 0.0;
        while( cin >> p.x >> p.y ) {
                for( int i = 1; i <= idx; i++ ) {
                        if( destroyed[i] ) continue;
                        vector <lineSegment> V;
                        for( int j = 1; j < hull[i][0].size(); j++ ) {
                                V.push_back( lineSegment( hull[i][0][j] , hull[i][0][j-1] ) );
                        }
                        lineSegment( hull[i][0][ hull[i][0].size()-1] , hull[i][0][0] );
                        if( RayShoot( V , p , point( p.x + inf , p.y + inf + 1 ) )&1 ) {
                                trace( "get : " , i , p.x , p.y , ans );
                                ans += P.PolygonArea( hull[i][0] );
                                destroyed[i] = true;
                        }
                }
        }
        cout << setprecision(2) << fixed;
        cout << ans << endl;
        return 0;
}








