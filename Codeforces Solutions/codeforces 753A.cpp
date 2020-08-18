#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 10000007

using namespace std;
int main()
{
   int n,count;
   cin >> n;
   int i;
   for(i=1;i<n;i++)
   {
       count=1;
       cout << count << endl;
       for(int j=i+1;j<n;j++)
       {
           count++;
           if(n-i-j>j)
           {
             count++;
             cout << i << j << endl;
           }
           else
            break;
       }
   }

    return 0;
}

