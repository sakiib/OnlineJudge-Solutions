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
   int n,ara[1000],i,k=1,j,ara1[1000];
   cin >> n;
   for(i=1;i<=n;i++) {
      cin >> ara[i];
     }
       for(i=1;i<=n;i++) {
         ara1[k]=ara[i];
           k++;
       }

       for(i=1;i<=n;i++) {
        for(j=i+1;j<=n;j++) {
             for (k=1;k<=n;k++) {
                if(ara[i]+ara[j]==ara1[k]) {
                    cout << k <<" "<<j<<" "<<i<<endl;
                      return 0;
                }
             }
          }
       }
      cout << "-1" <<endl;
      return 0;
}


