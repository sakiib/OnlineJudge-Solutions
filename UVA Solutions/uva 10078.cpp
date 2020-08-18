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
const int inf = 1e9;
const double EPS = 1e-9;
const double PI = acos(-1.0);
const long long INF = 1e18;
const int N = 1e5 + 5;

struct Point {
        int x , y;
        Point( ) {}
        Point( int x , int y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) { return Point ( x + p.x, y + p.y ); }
        Point operator - ( Point p ) { return Point ( x - p.x, y - p.y ); }
        Point operator * ( LL k ) { return Point( x * k , y * k ); }
        Point operator / ( LL k ) { return Point( x / k , y / k ); }
        int dot( const Point p ) { return ( x * p.x + y * p.y ); }
        int cross( const Point p ) { return ( x * p.y - y * p.x ); }
        double dist( const Point p ) { return ( sqrt( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
        int sqdist( const Point p ) { return ( ( (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) ) ); }
} P;

int Orientation( Point st , Point mid , Point ed ) {
        LL v = ( ed - st ).cross( mid - st );
        if( !v ) return 0;
        return v < 0 ? 1 : -1;
}
bool Convex( vector <Point> &V ) {
        bool hasPos = false , hasNeg = false;
        int k = V.size();
        for( int i = 0; i < V.size(); i++ ) {
                int ori = Orientation( V[i] , V[(i+1)%k] , V[(i+2)%k] );
                if( ori > 0 ) hasPos = true;
                if( ori < 0 ) hasNeg = true;
        }
        return !( hasPos && hasNeg );
}
int main( ) {
        IO;
        #ifdef LOCAL
            freopen( "input.txt" , "r" , stdin );
        #endif // LOCAL
        int n;
        while( cin >> n ) {
                if( n == 0 ) break;
                vector <Point> V;
                for(int i = 1; i <= n; i++ ) {
                        int x , y;
                        cin >> x >> y;
                        V.push_back( Point( x , y ) );
                }
                if( Convex( V ) ) cout << "No" << endl;
                else cout << "Yes" << endl;
        }
        return 0;
}
