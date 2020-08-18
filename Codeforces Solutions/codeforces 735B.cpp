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
 long long int n,n1,n2,i,ara[100009];
 scanf("%I64d%I64d%I64d",&n,&n1,&n2);
 float sum=0.0;
 for(i=0;i<n;i++)
  {
     scanf("%I64d",&ara[i]);
  }

 sort(ara,ara+n);

 if(n2>n1)
 swap(n1,n2);
   // printf("%d %d\n",n1,n2);
   for(i=0;i<n2;i++)
 {
     sum+=ara[n-1-i];
     //printf("%f\n",sum);
 }
  float add=0.0;
 for(i=0;i<n1;i++)
 {
     add+=ara[n-1-n2-i];
    // printf("%f\n",add);
 }
 printf("%0.8f\n",sum/n2+add/n1);
    return 0;
}


