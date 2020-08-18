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
  int a,b,c,ara[1000],sum=0;
  scanf("%d%d%d",&a,&b,&c);
  ara[0]=a;
  ara[1]=b;
  ara[2]=c;
  sort(ara,ara+3);
  sum+=(ara[1]-ara[0])+(ara[2]-ara[1]);
  printf("%d\n",sum);
    return 0;
}


