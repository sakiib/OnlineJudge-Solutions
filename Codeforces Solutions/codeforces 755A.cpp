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
  int n;
  cin >>n;
  if(n==1)
    cout << 3 <<endl;
  else if(n==2)
    cout << 4 <<endl;
  else
    cout << n-2 <<endl;

    return 0;
}


