#include <bits/stdc++.h>
using namespace std;

struct point {
        double x , y;
        point(){}
        point( double x , double y ) : x(x) , y(y) {}
        void in( ) {
                scanf("%lf %lf",&x,&y);
        }
        void print( ) {
                printf("%.05f %.05f\n",x,y);
        }
};

int main( int argc , char const *argv[] ) {
        int t;
        scanf("%d",&t);
        for( int tc = 1; tc <= t; tc++ ) {
                point a , b , c , d;
                a.in() , b.in() , c.in() , d.in();

        }
        return 0;
}
