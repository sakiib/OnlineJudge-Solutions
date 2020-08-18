#include<bits/stdc++.h>
using namespace std;

int main( ) {
        int t , p , q;
        double ans, la, lb, ca, low, high, mid, x, y, c;
        while( scanf("%lf %lf %lf",&x,&y,&c) != EOF ) {
                ans = 1.0 * min( x , y );
                int iter = 50;
                low = 0 , high = ans;
                while( iter-- ) {
                    mid = ( low + high ) / 2.0;
                    la = sqrt( 1.0*x*x - mid*mid );
                    lb = sqrt( 1.0*y*y - mid*mid );
                    ca = 1 / ( (1/la) + (1/lb) );
                    if( ca > c ) low = mid;
                    else high = mid;
                }
                printf("%.03lf\n",mid);
        }
        return 0;
}
