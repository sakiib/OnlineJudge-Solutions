#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#include<stack>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
int main()
{
    int a,b,x,y,z,count=0;
    cin >> a >> b;
    while(a<=b)
    {
        a*=3;
        b*=2;
        count++;
    }
  cout << count << endl;

  return 0;
}


