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
   int n,ara[3001],i,ans;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> ara[i];
    }
    sort(ara,ara+n);
      for(i=0;i<=n;i++){
        if(ara[i]!=i+1){
            cout <<i+1;
              return 0;
        }
      }
    return 0;
}


