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
   int n,ara[1000],min=1001,temp,ind1,ind2;
      cin >> n;
   for(int i=1;i<=n;i++){
        cin >> ara[i];
   }
       for(int i=1;i<n;i++){
          int a=abs(ara[i]-ara[i+1]);

               if(a<=min){
                 min=a;
                 ind1=i;ind2=i+1;
         }
         temp=abs(ara[1]-ara[n]);
   }
       if(min<temp){
           cout << in1 <<" "<< in2 <<endl;
    }
       else
          cout << 1 << " " << n <<endl;
    return 0;
}


