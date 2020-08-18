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

double a , b , c;

double Val( double x ) {
    return ( a*x+b*sin(x) );
}
int main( int argc, char const *argv[] ) {
    int t;
    scanf("%d",&t);
    while( t-- ) {
       scanf("%lf %lf %lf",&a,&b,&c);
       double lo = 0.0 , hi = 1000000000.0;
       while( hi-lo >= EPS ) {
         double mid = (lo+hi)/2.0;
         if( Val( mid ) > c ) hi = mid;
         else if( Val( mid ) < c ) lo = mid;
       }
       printf("%0.6lf\n",lo);
    }
    return 0;
}

