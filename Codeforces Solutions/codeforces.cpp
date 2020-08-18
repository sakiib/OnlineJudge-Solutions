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
 int n,d,i,count=0,ara[1000]={0},t;
 char str[100000];
 scanf("%d%d",&n,&d);
  for(t=1;t<=d;t++)
  {

     scanf(" %[^\n]",str);
     int l=strlen (str);
     for(i=0;i<l;i++)
     {
         if(str[i]=='0')
         {
          ara[t]=1;
         }

     }
  }



  printf("%d\n",count);
    return 0;
}


