#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 1000000007//10^9+7
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))


using namespace std;
int main()
{
   int x,y,g,z,target,n=6;
   cin >> x >>y;
   z=MAX(x,y);
   target=7-z;
   g=__gcd( target, n);//GCD calculating//
    cout << target/g <<"/"<< n/g <<endl;
    return 0;
}



