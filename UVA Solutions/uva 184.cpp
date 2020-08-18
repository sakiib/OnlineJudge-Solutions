#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long uLL;
typedef long long int LL;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
typedef pair <long long,long long> pll;
typedef pair <long long,pll> plll;
const int N = 505;
const int inf = 1e9;
const long long INF = 1e18;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const int MOD = 1000000007;

struct Point {
        int x , y;
        Point( ) {}
        Point( int x , int y ) : x( x ) , y( y ) {}
        Point operator + ( Point p ) { return Point ( x + p.x, y + p.y ); }
        Point operator - ( Point p ) { return Point ( x - p.x, y - p.y ); }
        Point operator * ( int k ) { return Point( x * k , y * k ); }
        Point operator / ( int k ) { return Point( x / k , y / k ); }
        int dot( const Point p ) { return ( x * p.x + y * p.y ); }
        int cross( const Point p ) { return ( x * p.y - y * p.x ); }
} P;

vector <Point> V;
vector <Point> ans[ N ];
bool taken[ N ];

int Orientation( Point st , Point mid , Point ed ) {
        int v = ( ed - st ).cross( mid - st );
        if( !v ) return 0;
        return v > 0 ? 1 : -1;
}
bool coLinear( Point a , Point b , Point c ) {
        LL ori = Orientation( a , b , c );
        return ori == 0;
}
int main( int argc , char const *argv[] ) {
        int x , y;
        while( scanf("%d %d",&x,&y) ) {
                if( x == 0 && y == 0 ) break;

                V.clear();
                for( int i = 1; i < N; i++ ) ans[i].clear();
                memset( taken , false , sizeof( taken ) );

                V.push_back( Point( x , y ) );
                while( scanf("%d %d",&x,&y) ) {
                        if( x == 0 && y == 0 ) break;
                        V.push_back( Point( x , y ) );
                }
                //for( auto x : V ) cout << x.x << " " << x.y << endl;
                int id = 0;
                for( int i = 0; i < V.size(); i++ ) {
                        for( int j = i+1; j < V.size(); j++ ) {
                                vector <Point> temp;
                                for( int k = j+1; k < V.size(); k++ ) {
                                        if( coLinear( V[i] , V[j] , V[k] ) ) {
                                                temp.push_back( V[k] );
                                        }
                                }
                                if( temp.size() ) {
                                        ++id;
                                        temp.push_back( V[i] );
                                        temp.push_back( V[j] );
                                        for( auto x : temp ) ans[id].push_back( x );
                                }
                        }
                }
                if( id == 0 ) {
                        printf("No lines were found\n");
                }
                else {
                        printf("The following lines were found:\n");
                        for( int i = 1; i <= id; i++ ) {
                                for( auto x : ans[i] ) {
                                        cout << "( " << x.x << " " << x.y << " ) , ";
                                }
                                cout << endl;
                        }
                }
        }
        return 0;
}











