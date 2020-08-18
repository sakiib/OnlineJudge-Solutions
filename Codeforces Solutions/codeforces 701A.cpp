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
  int n,i,ara[10000],sum=0,j;
   cin >> n;
   for(i=1;i<=n;i++) {
    cin >> ara[i];
    sum+=ara[i];
   }
   int a=n/2;
   int dist=sum/a;
   for(i=1;i<=n;i++)
   {
   for(j=i+1;j<=n;j++)
      {
          if(ara[i]!=0&&ara[j]!=0)
          {
              if(ara[i]+ara[j]==dist)
            {
              ara[i]=0;ara[j]=0;
              printf("%d %d\n",i,j);
              break;
            }
          }

       }
   }
    return 0;
}


