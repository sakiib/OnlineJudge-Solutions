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
typedef long long int ll;
using namespace std;
int main()
{
  ll k2,k3,k5,k6,sum=0,add=0;
  scanf("%I64d%I64d%I64d%I64d",&k2,&k3,&k5,&k6);
   while(k2>=1&&k5>=1&&k6>=1)
   {
      sum+=256;
     k2--;k5--;k6--;
    // printf("Sum=%I64d\n",sum);
    // printf("%I64d %I64d %I64d\n",k2,k5,k6);
   }
 // printf("%I64d %I64d %I64d\n",k2,k5,k6);
   while(k3>=1&&k2>=1)
   {
       add+=32;
       k3--;k2--;
       //printf("%I64d\n",add);
   }
 printf("%I64d\n",sum+add);

    return 0;
}


