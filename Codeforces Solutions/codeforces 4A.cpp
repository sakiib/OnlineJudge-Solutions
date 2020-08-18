#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;
int main()
{
  int n,a;
   cin >> n;
    if(n%2!=0){
        printf("NO\n");
         return 0;
    }
   else{
    a=n/2;
    if(a<2){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        return 0;
    }
   }
    return 0;
}


